package com.lib;

import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

public class SystemLogger 
{
	
	private Logger logger;
	
	public SystemLogger(Object object)
	{
		logger=Logger.getLogger(object.getClass());
		PropertyConfigurator.configure("/home/sanit/works/chat-server-log/log.properties");
	}
	
	public Logger getLogger()
	{
		return logger;
	}
	
}
