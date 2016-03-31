package com.lib;

import com.exception.DatabaseException;
import com.mysql.jdbc.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author sanit
 */
public class DatabaseConnection
{

    private Connection connection;
    private DatabaseSettings databaseSettings;
    private DatabaseProperties databaseProperties;
    private SystemLogger systemLogger;
    
    public DatabaseConnection()
    {
        this.connection = null;
        databaseProperties=new DatabaseProperties();
        systemLogger=new SystemLogger(this);
    }

    /**
     * Create Database connection
     */
    public Connection createConnection() throws DatabaseException
    {
        String url ="jdbc:mysql://";
        try
        {
            databaseSettings=databaseProperties.getSettings();
            url=url+databaseSettings.getHost()+":"+databaseSettings.getPort()+"/"+databaseSettings.getName();

            // Load driver
            Class.forName(databaseSettings.getDriver());

            // Create Connection
            this.connection=DriverManager.getConnection(url, databaseSettings.getUser(), databaseSettings.getPassword());
            
        } catch (SQLException ex)
        {
            systemLogger.getLogger().error("SQLException: "+ex.getMessage());
            throw new DatabaseException("SQLException: "+ex.getMessage());
        } catch (ClassNotFoundException ex)
        {
            systemLogger.getLogger().fatal("ClassNotFoundException: "+ex.getMessage());
            throw new DatabaseException("ClassNotFoundException:: "+ex.getMessage());
        }
        return this.connection;
    }

    public void closeConnction(Connection connection, ResultSet resultSet, Statement statement)
    {
        try
        {
            if (statement != null)
            {
                statement.close();
            }
            if (resultSet != null)
            {
                resultSet.close();
            }
            if (connection != null)
            {
                connection.close();
            }
        } catch (SQLException ex)
        {
            System.out.println("SQL Exception: "+ex.getMessage());
        }
    }
    public void closeConnction(Connection connection, Statement statement)
    {
        try
        {
            if (statement != null)
            {
                statement.close();
            }
            if (connection != null)
            {
                connection.close();
            }
        } catch (SQLException ex)
        {
            System.out.println("SQL Exception: "+ex.getMessage());
        }
    }
}
