package com.exception;

/**
 * @author sanit
 */
public class DatabaseException  extends RuntimeException
{
    public DatabaseException(String message)
    {
        super(message);
    }
}
