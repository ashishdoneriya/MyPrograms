package librarymanagementsystem;
import java.sql.Connection;
import java.util.Scanner;
public class LibraryManagementSystem {
    public static void main(String[] args) {
        
        // TODO code application logic here
      /*
    	String username, password;
        Scanner kb=new Scanner(System.in);
        System.out.print("Please Enter user name : ");
        username=kb.next();
        System.out.print("Please Enter password  : ");
        password=kb.next();
        Connection connection=MySQLConnection.getConnection(username,password);
     */   Connection connection=MySQLConnection.getConnection("root","ashish");
        MainMenu menu;
        menu = new MainMenu(connection);
        menu.show();
    }
}
