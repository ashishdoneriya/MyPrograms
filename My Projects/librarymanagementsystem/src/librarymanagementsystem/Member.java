package librarymanagementsystem;
import com.mysql.jdbc.exceptions.MySQLIntegrityConstraintViolationException;
import static java.lang.System.out;
import java.sql.*;
import java.text.SimpleDateFormat;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.Date;
/**
 *
 * @author ashish
 */
public class Member {
    int scholarNo;
    String name;
    String phone;
    String address;
    int noOfBooks;
    static PreparedStatement ps;
    static ResultSet rs;
    public void getDetails(){
        Scanner kb=new Scanner(System.in);
        while(true){
            try{
                out.print("Enter Scholar No.\t: ");
                scholarNo=kb.nextInt();
                out.print("Enter Name\t\t: ");
                String str;
                str = kb.nextLine();
                name=kb.nextLine();
                while(true){
                    out.println("Enter Phone No.\t: ");
                    phone=kb.next();
                    if(phone.length()<=10) {
                        break;
                    }
                    else {
                        out.println("Please type phone no having less than 10 digits");
                    }
                }
                out.print("Enter Address\t: ");
                str=kb.nextLine();
                address=kb.nextLine();
                out.print("Enter No. of Books currently have\t: ");
                noOfBooks=kb.nextInt();
                break;
            }
           catch(InputMismatchException e){
               System.out.println("Please Enter Correct Data");
            }
        }
        
    }
    public void insertRecord(Connection con){
        try{
            ps=con.prepareStatement("INSERT INTO member_list VALUES(?,?,?,?,?)");
            ps.setInt(1, scholarNo);
            ps.setString(2, name);
            ps.setString(3, phone);
            ps.setString(4, address);
            ps.setInt(5, noOfBooks);
            int x=ps.executeUpdate();
        }
        catch(MySQLIntegrityConstraintViolationException e){
            out.println("Duplicate Record having Same Scholar Number Found");
        }
        catch(Exception e){
          //  System.out.println(e);
            e.printStackTrace();
        }
    }
    public static void ShowList(ResultSet rs) throws SQLException{
    	out.println("Scholar No.\tName\t\t\tPhone\t\tAddress\t\tNO. of Books issued");
        while(rs.next()){
            out.println("\""+rs.getInt(1)+"\"\t\""+rs.getString(2)+"\"\t\""+rs.getString(3)+"\"\t\""+rs.getString(4)+"\"\t\""+rs.getInt(5)+"\"");
        }
    }
    public static void listOfMembers(Connection con){
        try{
            ps=con.prepareStatement("Select * FROM member_list");
            rs=ps.executeQuery();
            ShowList(rs);
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    public static void deleteRecord(Connection con){
        Scanner kb=new Scanner(System.in);
        out.println("Enter Scholar No : ");
        int scholarNo=kb.nextInt();
        try{
            ps=con.prepareStatement("Select no_of_books FROM member_list WHERE scholar_no=?");
            ps.setInt(1,scholarNo);
            rs=ps.executeQuery();
            rs.next();
            int count=rs.getInt(1);
            if(count>0){
                out.println("Please Submit Issued Books First");
                return;
            }
            ps=con.prepareStatement("DELETE FROM member_list WHERE scholar_no=?");
            ps.setInt(1, scholarNo);
            ps.executeUpdate();
            out.println("Record Deleted");
        }
        catch(SQLException e){
            e.printStackTrace();
        }
    }
	public static void SearchMember(Connection con) {
		String name;
		out.print("Enter the Scholar No or Name of the Member : ");
		Scanner kb=new Scanner(System.in);
		name=kb.nextLine();
		if(name.length()==0)
			return;
		if(MainMenu.IsValidNumber(name)){
			try {
				ps=con.prepareStatement("SELECT * FROM member_list WHERE scholar_no=?");
				ps.setInt(1, Integer.parseInt(name));
				rs=ps.executeQuery();
				ShowList(rs);
				
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		else{
			try {
				ps=con.prepareStatement("SELECT * FROM member_list WHERE member_name LIKE '%"+name+"%'");
				rs=ps.executeQuery();
				ShowList(rs);
			} catch (SQLException e) {
				out.println(e);
			}	
		}
	}
	public static void Modify(ResultSet rs) throws SQLException{
    	Scanner kb=new Scanner(System.in);
    	String temp;
    	rs.next();
		out.println("Scholar No. = "+rs.getInt(1));
		out.println("Enter new Scholar No. : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateInt(1, Integer.valueOf(temp));
		}
		out.println("Member Name = "+rs.getString(2));
		out.println("Enter new Name : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateString(2, temp);
		}
		rs.updateRow();
		out.println("Phone No. = "+rs.getString(3));
		out.println("Enter new Phone No. : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateString(3, temp);
		}
		out.println("Address = "+rs.getString(4));
		out.println("Enter new Address : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateString(4, temp);
		}
		out.println("No. of books currently issuing = "+rs.getInt(5));
		out.println("Enter new Value : ");
		temp=kb.nextLine();
		if(!(temp.length()==0)){
			rs.updateInt(5, Integer.valueOf(temp));
		}
		rs.updateRow();
    }
    public static void ModifyMemberDetails(Connection con){
    	Scanner kb=new Scanner(System.in);
    	int id;
    	out.print("Enter Scholar No. : ");
    	id=kb.nextInt();
    	try {
    		ps=con.prepareStatement("SELECT * FROM member_list WHERE scholar_no="+id, ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_UPDATABLE);
			rs=ps.executeQuery();
			Modify(rs);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    }
	public static void CalculateFine(int scholarNo, int bookId,Connection con) {
		try {
			ps=con.prepareStatement("SELECT issue_date FROM issued_books WHERE book_id=? AND scholar_no=?");
			ps.setInt(1, bookId);
			ps.setInt(2, scholarNo);
			rs=ps.executeQuery();
			Date d=new Date();
			SimpleDateFormat sdf = new SimpleDateFormat("ddMMyyyy");
			String f=sdf.format(d);
			int d1,m1,y1,d2,m2,y2;
			d1=Integer.parseInt(f.substring(0,2));
			m1=Integer.parseInt(f.substring(2,4));
			y1=Integer.parseInt(f.substring(4, 8));
			rs.next();
			java.sql.Date date=rs.getDate(1);
			d2=Integer.parseInt((date.toString()).substring(8,10));
			m2=Integer.parseInt((date.toString()).substring(5,7));
			y2=Integer.parseInt((date.toString()).substring(0,4));
			int noOfDays=GetDifference(d1,m2,y1,d2,m2,y2);
			out.println(noOfDays);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static int GetDifference(int d1, int m1, int y1, int d2, int m2, int y2)
	{
		int days = 0 ;
		if ((y2<y1) || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
			return days ;
		int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
		while (d1 != d2 || m1 != m2 || y1 != y2)
		{
			days++ ;
			d1++ ;
			if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
			{
				d1 = 1 ;
				m1++ ;
			}
			if (m1 > 12)
			{
				m1 = 1 ;
				y1++ ;
			}
		}
		return days ;
	}
}
