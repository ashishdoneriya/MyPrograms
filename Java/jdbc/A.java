import java.sql.*;

public class A{
  public static void main(String[] args) {
  System.out.println("MySQL Connect Example.");
  Connection conn = null;
  String url = "jdbc:mysql://127.0.0.1/ashish";
  String dbName = "krishna";
  String driver = "com.mysql.jdbc.Driver";
  String userName = "ashish"; 
  String password = "ashish";
  try {
  Class.forName(driver).newInstance();
  conn = DriverManager.getConnection(url+dbName,userName,password);
  System.out.println("Connected to the database");
  conn.close();
  System.out.println("Disconnected from database");
  } catch (Exception e) {
  e.printStackTrace();
  }
  }
}
