package librarymanagementsystem;

import static java.lang.System.out;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

/*
 *
 * @author ashish
 */
public class ReturnBook {
    int bookId;
    int scholarNo;
    Connection con;
    PreparedStatement ps;
    public ReturnBook(Connection con){
        ps=null;
        this.con=con;
    }
    public void getDetail(){
        Scanner kb=new Scanner(System.in);
        out.print("Enter BookId\t: ");
        bookId=kb.nextInt();
        out.print("Enter Scholar No.\t:");
        scholarNo=kb.nextInt();
    }
    public void returnBook(){
        try{
            clearEntryFromIssueTable();
            entryInMemberTable();
            entryInBookTable();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    public void clearEntryFromIssueTable()throws SQLException{
        ps=con.prepareStatement("DELETE FROM issued_books WHERE book_id=? AND scholar_no=?");
        ps.setInt(1, bookId);
        ps.setInt(2, scholarNo);
        ps.executeUpdate();
    }
    public void entryInMemberTable() throws SQLException, Exception{
        ps=con.prepareStatement("SELECT no_of_books FROM member_list WHERE scholar_no=?");
        ps.setInt(1, scholarNo);
        ResultSet rs;
        rs = ps.executeQuery();
        rs.next();
        int noOfBooks=0;
        try{
            noOfBooks=rs.getInt(1);
            if(noOfBooks==0){
                throw (new Exception("Member has currently no Book."));
            }
            noOfBooks--;
            ps=con.prepareStatement("UPDATE member_list SET no_of_books=? WHERE scholar_no=?");
            ps.setInt(1, noOfBooks);
            ps.setInt(2, scholarNo);
            ps.executeUpdate();
        }
        catch(SQLException e){
        //    out.println();
            throw (new Exception("Member not Found"));
        }
    }
    public void entryInBookTable()throws SQLException, Exception{
        ps=con.prepareStatement("SELECT copies_available,total_copies FROM book_list WHERE book_id=?");
        ps.setInt(1,bookId);
        ResultSet rs;
        rs=ps.executeQuery();
        rs.next();
        try{
            int copiesAvailable=rs.getInt("copies_available");
            int totalCopies=rs.getInt(2);
            if(totalCopies==copiesAvailable){
                throw (new Exception("No Book is Alloted Currently. Stock Already Full"));
            }
            copiesAvailable++;
            ps=con.prepareStatement("UPDATE book_list SET copies_available=? WHERE book_id=?");
        
            ps.setInt(1, copiesAvailable);
            ps.setInt(2, bookId);
            ps.executeUpdate();
        }
        catch(SQLException e){
            throw (new Exception("Book not Found"));
        }
    }
}
