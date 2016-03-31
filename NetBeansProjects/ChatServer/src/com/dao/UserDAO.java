package com.dao;

import com.bean.User;
import com.exception.DatabaseException;
import com.lib.DatabaseConnection;
import com.lib.SystemLogger;
import java.sql.PreparedStatement;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 *
 * @author sanit
 */
public class UserDAO
{

    private SystemLogger systemLogger;
    private Connection connection;

    public UserDAO()
    {
        systemLogger = new SystemLogger(this);
    }

    public User getUser(User user) throws DatabaseException
    {
        ResultSet resultSet;
        DatabaseConnection databaseConnection = new DatabaseConnection();
        String sql = "select id,userName,name,password from user where id=?";
        try
        {
            connection = databaseConnection.createConnection();
            if (connection != null)
            {
                PreparedStatement preparedStatement = connection.prepareStatement(sql);
                preparedStatement.setInt(1, user.getId());

                resultSet = preparedStatement.executeQuery();
                if (resultSet.next())
                {
                    user.setId(resultSet.getInt(1));
                    user.setUserName(resultSet.getString(2));
                    user.setName(resultSet.getString(3));
                    user.setPassword(resultSet.getString(4));
                }
            }
            else
            {
                systemLogger.getLogger().fatal("Connecttion is NULL");
                throw new DatabaseException("Connecttion is NULL");
            }

        } catch (SQLException ex)
        {
            systemLogger.getLogger().fatal("SQLException::"+ex.getMessage());
            throw new DatabaseException("SQLException::"+ex.getMessage());
        }
        return user;
    }

    public User getUserByUserName(User user) throws DatabaseException
    {
        ResultSet resultSet;
        DatabaseConnection databaseConnection = new DatabaseConnection();
        String sql = "select id,userName,name,password from user where userName=?";
        try
        {
            connection = databaseConnection.createConnection();
            if (connection != null)
            {
                PreparedStatement preparedStatement = connection.prepareStatement(sql);
                preparedStatement.setString(1, user.getUserName());

                resultSet = preparedStatement.executeQuery();
                if (resultSet.next())
                {
                    user.setId(resultSet.getInt(1));
                    user.setUserName(resultSet.getString(2));
                    user.setName(resultSet.getString(3));
                    user.setPassword(resultSet.getString(4));
                }
            }
            else
            {
                systemLogger.getLogger().fatal("Connecttion is NULL");
                throw new DatabaseException("Connecttion is NULL");
            }

        } catch (SQLException ex)
        {
            systemLogger.getLogger().fatal("SQLException::"+ex.getMessage());
            throw new DatabaseException("SQLException::"+ex.getMessage());
        }
        return user;
    }


    public ArrayList<User> getUserList() throws DatabaseException
    {
        ResultSet resultSet;
        DatabaseConnection databaseConnection = new DatabaseConnection();
        String sql = "select id,userName,name,password from user";
        ArrayList<User> userList=new ArrayList<User>();
        try
        {
            connection = databaseConnection.createConnection();
            if (connection != null)
            {
                PreparedStatement preparedStatement = connection.prepareStatement(sql);
                

                resultSet = preparedStatement.executeQuery();
                while (resultSet.next())
                {
                    User user=new User();
                    user.setId(resultSet.getInt(1));
                    user.setUserName(resultSet.getString(2));
                    user.setName(resultSet.getString(3));
                    user.setPassword(resultSet.getString(4));
                    userList.add(user);
                }
            }
            else
            {
                systemLogger.getLogger().fatal("Connecttion is NULL");
                throw new DatabaseException("Connecttion is NULL");
            }

        } catch (SQLException ex)
        {
            systemLogger.getLogger().fatal("SQLException::"+ex.getMessage());
            throw new DatabaseException("SQLException::"+ex.getMessage());
        }
        return userList;
    }

    public boolean isUser(User user) throws DatabaseException
    {
        boolean returnValue=false;
        
        ResultSet resultSet;
        DatabaseConnection databaseConnection = new DatabaseConnection();
        String sql = "select count(id) from user where id=?";
        int count=0;
        
        try
        {
            connection = databaseConnection.createConnection();
            if (connection != null)
            {
                PreparedStatement preparedStatement = connection.prepareStatement(sql);
                preparedStatement.setInt(1, user.getId());
                
                resultSet = preparedStatement.executeQuery();
                if (resultSet.next())
                {                    
                    count=resultSet.getInt(1);
                }
                if(count>0)
                {
                    returnValue=true;
                }
            }
            else
            {
                systemLogger.getLogger().fatal("Connecttion is NULL");
                throw new DatabaseException("Connecttion is NULL");
            }
        } catch (SQLException ex)
        {
            systemLogger.getLogger().fatal("SQLException::"+ex.getMessage());
            throw new DatabaseException("SQLException::"+ex.getMessage());
        }
        return returnValue;
    }

    public boolean isUserByUserName(User user) throws DatabaseException
    {
        boolean returnValue=false;

        ResultSet resultSet;
        DatabaseConnection databaseConnection = new DatabaseConnection();
        String sql = "select count(id) from user where userName=?";
        int count=0;

        try
        {
            connection = databaseConnection.createConnection();
            if (connection != null)
            {
                PreparedStatement preparedStatement = connection.prepareStatement(sql);
                preparedStatement.setString(1, user.getUserName());

                resultSet = preparedStatement.executeQuery();
                if (resultSet.next())
                {
                    count=resultSet.getInt(1);
                }
                if(count>0)
                {
                    returnValue=true;
                }
            }
            else
            {
                systemLogger.getLogger().fatal("Connecttion is NULL");
                throw new DatabaseException("Connecttion is NULL");
            }
        } catch (SQLException ex)
        {
            systemLogger.getLogger().fatal("SQLException::"+ex.getMessage());
            throw new DatabaseException("SQLException::"+ex.getMessage());
        }
        return returnValue;
    }
}
