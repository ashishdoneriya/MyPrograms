package librarymanagementsystem;
import static java.lang.System.out;
import java.sql.*;
import java.util.Scanner;
/*
 *
 * @author ashish
 */
public class MainMenu {
    Connection con;
    Scanner kb;
    public MainMenu(Connection con){
      this.con=con;
      kb=new Scanner(System.in);
    }
    public void show(){
        while(true){
            menu();
        }
    }
    public void menu(){
        out.println("\n\nWelcome to Library Management System");
        out.println("1. Add New Book");
        out.println("2. Add New Member");
        out.println("3. Issue Book");
        out.println("4. Return Book");
        out.println("5. List of Books");
        out.println("6. List of Members");
        out.println("7. List of Issued Books");
        out.println("8. Search Book");
        out.println("9. Search Member");
        out.println("10. Edit Records");
        out.println("11. Delete Record");
        out.println("12. Calculate Fine");
        out.println("13. Exit\n");
        out.print("Enter your choice : ");
        int choice = kb.nextInt();
        switch (choice){
            case 1:
                addBook();
                break;
            case 2:
                addMember();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                listOfBooks();
                break;
            case 6:
                listOfMembers();
                break;
            case 7:
                listOfIssuedBooks();
            case 10:
                editRecord();
                break;
            case 8:
                searchBook();
                break;
            case 9:
                searchMember();
                break;
            case 11:
                deleteRecord();
            case 12:
                calculateFine();
                break;
            case 13:
                System.exit(0);
            default:
                out.println("Wrong Choice");
        }
    }
    public void addBook(){
        Book book=new Book();
        book.getDetails();
        book.insertRecord(con);
    }
    public void addMember(){
        Member member=new Member();
        member.getDetails();
        member.insertRecord(con);
    }
    public void issueBook(){
        IssueBook ib=new IssueBook(con);
        ib.getDetail();
        ib.issueBook();
        
    }
    public void returnBook(){
        ReturnBook rb=new ReturnBook(con);
        rb.getDetail();
        rb.returnBook();
    }
    public void listOfBooks(){
        Book.listOfBooks(con);
    }
    public void listOfMembers(){
        Member.listOfMembers(con);
    }
    public void listOfIssuedBooks(){
        Book.listOfIssuedBooks(con);
    }
    public void editRecord(){
        out.println("1. Modify Book Details");
        out.println("2. Modify Member Details");
        out.print("Enter your choice : ");
        int choice = kb.nextInt();
        if(choice==1){
        	Book.ModifyBookDetails(con);
        }
        else if(choice==2){
        	Member.ModifyMemberDetails(con);
        }
        else {
			out.println("Wrong Choice");
		}
    }
    public void searchBook(){
    	Book.SearchBook(con);
    }
    public void searchMember(){
    	Member.SearchMember(con);
    }
    public void calculateFine(){	
        out.print("Enter Scholar No\t: ");
        int scholarNo=kb.nextInt();
        out.print("Enter Book Id\t: ");
        int bookId=kb.nextInt();
        Member.CalculateFine(scholarNo,bookId,con);
    }
	public void deleteRecord(){
		out.println("1. Delete Book Record\n2. Delete Member Record\nEnter your Choice :");
		int choice=kb.nextInt();
		if(choice==1) {
			Book.deleteRecord(con);
		}
        else if(choice==2) {
            Member.deleteRecord(con);
        }
        else {
            out.println("Wrong choice");
        }
        
    }
    public static boolean IsValidNumber(String S){
		for(int i=0;i<S.length();i++){
			if((S.charAt(i)<'0')||((S.charAt(i)>'9')))
				return false;
		}
		return true;
	}
}
