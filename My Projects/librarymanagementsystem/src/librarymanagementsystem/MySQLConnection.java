package librarymanagementsystem;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/*
 *
 * @author ashish
 */
public class MySQLConnection {
    public static Connection getConnection(String username,String password){
        try{
            Class.forName("java.sql.Driver");
        }
        catch(ClassNotFoundException e){
            System.out.println("Where is your MySQL JDBC Driver?");
            System.out.println(e);
            System.exit(1);
        }
        System.out.println("MySQL JDBC Driver Registered!");
        Connection connection;
        connection = null;
        try{
            connection=DriverManager.getConnection("jdbc:mysql://localhost:3306/library",username,password);
        }
        catch(SQLException e){
            System.out.println("Wrong Username or Password");
            System.exit(0);
        }
        
        if (connection != null) {
            System.out.println("You made it, take control your database now!");
	}
        else {
            System.out.println("Failed to make connection!");
            System.exit(0);
	}
        return connection;
    }
    
}
