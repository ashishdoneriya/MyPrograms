package com.lib;

import com.exception.PropertyFileException;
import java.io.IOException;
import java.util.Properties;
import java.io.FileInputStream;

public class DatabaseProperties
{

    private SystemLogger systemLogger;

    public DatabaseProperties()
    {
        systemLogger=new SystemLogger(this);
    }
    
    public DatabaseSettings getSettings()
    {
        DatabaseSettings databaseSettings = new DatabaseSettings();            
        try
        {
            Properties properties = new Properties();
            properties.load(new FileInputStream("/home/sanit/works/chat-server-log/db.properties"));

            // Setting all database configuration
            databaseSettings.setHost(properties.getProperty("db.host"));
            databaseSettings.setPort(properties.getProperty("db.port"));
            databaseSettings.setName(properties.getProperty("db.name"));
            databaseSettings.setUser(properties.getProperty("db.user"));
            databaseSettings.setPassword(properties.getProperty("db.password"));
            databaseSettings.setDriver(properties.getProperty("db.driver"));            
            
        } catch (IOException ex)
        {
            systemLogger.getLogger().fatal("IOException:: "+ex.getMessage());
            throw new PropertyFileException("IOException::"+ex.getMessage());
        }        
        // Return Database settings
        return databaseSettings;
    }
}
