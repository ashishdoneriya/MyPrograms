/**
 * MySqlLoadDriver.java
 * Copyright (c) 2007 by Dr. Herong Yang. All rights reserved.
 */
import javax.sql.*;
import java.sql.*;
class JDBCTest {
  public static void main(String [] args) {
    Connection con = null;
    try { 
// Load the MySQL JDBC driver
      Class.forName("com.mysql.jdbc.Driver") ;
      System.out.println("MySQL JDBC driver loaded ok.");
 
    } catch (Exception e) {
      System.err.println("Exception: "+e.getMessage());
    }
  }
}
