package com.bean;

import java.sql.Timestamp;

/**
 *
 * @author sanit
 */
public class Message
{

    private int id;
    private int sentFrom;
    private int sentTo;
    private String message;
    private Timestamp creationDateTime;

    public Timestamp getCreationDateTime()
    {
        return creationDateTime;
    }

    public void setCreationDateTime(Timestamp creationDateTime)
    {
        this.creationDateTime = creationDateTime;
    }

    public int getId()
    {
        return id;
    }

    public void setId(int id)
    {
        this.id = id;
    }

    public String getMessage()
    {
        return message;
    }

    public void setMessage(String message)
    {
        this.message = message;
    }

    public int getSentFrom()
    {
        return sentFrom;
    }

    public void setSentFrom(int sentFrom)
    {
        this.sentFrom = sentFrom;
    }

    public int getSentTo()
    {
        return sentTo;
    }

    public void setSentTo(int sentTo)
    {
        this.sentTo = sentTo;
    }
}