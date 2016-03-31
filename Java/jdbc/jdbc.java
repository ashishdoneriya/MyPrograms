import java.sql.*;
 
public class jdbc {
 
	public static void main(String[] argv) {
 
		System.out.println("-------- MySQL JDBC Connection Testing ------------");
 
		try {
 
			Class.forName("com.mysql.jdbc.Driver");
 
		} catch (ClassNotFoundException e) {
 
			System.out.println("Where is your MySQL JDBC Driver?");
			e.printStackTrace();
			return;
 
		}
 
		System.out.println("MySQL JDBC Driver Registered!");
		Connection connection = null;
 
		try {
			connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/college",
							"ashish", "ashish");
 
		} catch (SQLException e) {
			System.out.println("Connection Failed! Check output console");
			e.printStackTrace();
			return;
		}
 
		if (connection != null) {
			System.out.println("You made it, take control your database now!");
		} else {
			System.out.println("Failed to make connection!");
		}
          
                try{
                DatabaseMetaData dbm = connection.getMetaData();
                String[] types = {"TABLE"};
                ResultSet rs = dbm.getTables(null,null,"%",types);
                System.out.println("Table name:");
                while (rs.next()){
                    String table = rs.getString("TABLE_NAME");
                    System.out.println(table);
                }
                }
                catch(Exception e){
                    System.out.println(e);
                }
	}
}
