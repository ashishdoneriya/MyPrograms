package librarymanagementsystem;
import static java.lang.System.out;
import java.sql.*;
import java.util.InputMismatchException;
import java.util.Scanner;
/*
 *
 * @author ashish
 */
public class Book {
    int bookId;
    String bookName;
    String authorName;
    int noOfPages;
    int totalCopies;
    int copiesAvailable;
    static PreparedStatement ps;
    static ResultSet rs;
    public void getDetails(){
        while(true){
            try{
                Scanner kb=new Scanner(System.in);
                out.print("Enter Book ID\t: ");
                bookId=kb.nextInt();
                out.print("Enter Book Name\t: ");
                String temp=kb.nextLine();
                bookName=kb.nextLine();
                out.print("Enter Author Name\t: ");
                authorName=kb.nextLine();
                out.print("Enter No. of Pages\t: ");
                noOfPages=kb.nextInt();
                out.print("Enter Total copies Available\t: ");
                totalCopies=kb.nextInt();
                out.println("Enter Copies Currently Available\t: ");
                copiesAvailable=kb.nextInt();
                break;
            }
            catch(InputMismatchException e){
                System.out.println("Please Enter Correct Data");
            }
        }
    }
    public void insertRecord(Connection con){
        try{
            ps=con.prepareStatement("INSERT INTO book_list VALUES(?,?,?,?,?,?)");
            ps.setInt(1, bookId);
            ps.setString(2, bookName);
            ps.setString(3, authorName);
            ps.setInt(4, noOfPages);
            ps.setInt(5, totalCopies);
            ps.setInt(6, copiesAvailable);
            int x = ps.executeUpdate();
        }
        catch(Exception e){
            out.println(e);
        }
    }
    public static void listOfBooks(Connection con){
        try{
            ps=con.prepareStatement("Select * FROM book_list");
            rs=ps.executeQuery();
            ShowList(rs);   
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    public static void listOfIssuedBooks(Connection con){
        try{
			ps=con.prepareStatement("select ib.book_id,bl.book_name,ib.scholar_no,ib.issue_date FROM book_list bl,issued_books ib WHERE ib.book_id=bl.book_id");
			rs=ps.executeQuery();
			out.println("Book Id\tBook Name\t\tScholar No.\tDate");
			while(rs.next()){
				out.println("\""+rs.getInt(1)+"\"\t\""+rs.getString(2)+"\"\t\t\""+rs.getInt(3)+"\"\t\t\""+rs.getInt(4)+"\"");
			}    
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    public static void deleteRecord(Connection con){
        out.println("Enter book_id");
        Scanner kb=new Scanner(System.in);
        int bookId=kb.nextInt();
        try{
            ps=con.prepareStatement("select count(?) from issued_books where book_id=?");
            ps.setInt(1,bookId);
            ps.setInt(2,bookId);
            rs = ps.executeQuery();
            rs.next();
            int count=rs.getInt(1);
            if(count>0){
                out.println("Book Record can't be deleted Since its copy is distributed to "+count+" persons");
                return;
            }
            out.println("Are you sure want to delete book (y/n) ? ");
            String ch=kb.next();
            if(!ch.equalsIgnoreCase("y")){
                return;
            }
            ps=con.prepareStatement("DELETE FROM book_list where book_id=?");
            ps.setInt(1,bookId);
            ps.executeUpdate();
            out.println("Book Record Deleted");
        }
        catch(SQLException e){
            e.printStackTrace();
        }
    }
    public static void Modify(ResultSet rs) throws SQLException{
    	Scanner kb=new Scanner(System.in);
    	String temp;
    	rs.next();
		out.println("Book Id = "+rs.getInt(1));
		out.println("Enter new id : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateInt(1, Integer.valueOf(temp));
		}
		out.println("Book Name = "+rs.getString(2));
		out.println("Enter new Name : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateString(2, temp);
		}
		rs.updateRow();
		out.println("Author Name = "+rs.getString(3));
		out.println("Enter new Author Name : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateString(3, temp);
		}
		out.println("No. of Pages = "+rs.getInt(4));
		out.println("Enter new value : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateInt(4, Integer.valueOf(temp));
		}
		out.println("Total Copies = "+rs.getInt(5));
		out.println("Enter new Value : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateInt(5, Integer.valueOf(temp));
		}
		out.println("Copies Availables = "+rs.getInt(6));
		out.println("Enter new Value : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateInt(6, Integer.valueOf(temp));
		}
		rs.updateRow();
    }
    public static void ModifyBookDetails(Connection con){
    	Scanner kb=new Scanner(System.in);
    	int id;
    	out.print("Enter Book Id : ");
    	id=kb.nextInt();
    	try {
    		ps=con.prepareStatement("SELECT * FROM book_list WHERE book_id="+id, ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_UPDATABLE);
			rs=ps.executeQuery();
			Modify(rs);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    }
    public static void ShowList(ResultSet rs) throws SQLException{
    	rs.next();
		out.println("Book Id\tBook Name\t\t\tAuthor Name\t\t\tNo. of Pages\tTotal Copies\tCopies Available");
        do{
            out.println("\""+rs.getInt(1)+"\"\t\""+rs.getString(2)+"\"\t\""+rs.getString(3)+"\"\t\t\""+rs.getInt(4)+"\"\t\t\""+rs.getInt(5)+"\"\t\t\""+rs.getInt(6)+"\"");
        }while(rs.next());
    }
	public static void SearchBook(Connection con) {
		String name;
		out.print("Enter the Book Name or Book ID or Author Name of the book : ");
		Scanner kb=new Scanner(System.in);
		name=kb.nextLine();
		if(name.length()==0)
			return;
		if(MainMenu.IsValidNumber(name)){
			try {
				ps=con.prepareStatement("SELECT * FROM book_list WHERE book_id=?");
				ps.setInt(1, Integer.parseInt(name));
				rs=ps.executeQuery();
				ShowList(rs);
				
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		else{
			try {
				ps=con.prepareStatement("SELECT * FROM book_list WHERE book_name LIKE '%"+name+"%' OR author_name LIKE '%"+name+"%'");
				rs=ps.executeQuery();
				ShowList(rs);
			} catch (SQLException e) {
				out.println(e);
			}
			
		}
		
	}
	
}
