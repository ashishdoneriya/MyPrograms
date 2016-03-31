/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package hellosocket;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 *
 * @author sanit
 */
public class Client
{

    public static void main(String a[])
    {
        Socket client = null;
        
        Scanner userInput;
        PrintWriter output;
        int count=0;
        
        String message = null;


        try
        {
            client = new Socket(InetAddress.getLocalHost(), 4242);
            userInput = new Scanner(System.in);
            output = new PrintWriter(new OutputStreamWriter(client.getOutputStream()),true);

            System.out.println("***************************************************");
            do
            {
                System.out.printf("CLIENT"+count+">");
                message = userInput.nextLine();

                output.println(message);
                count++;
            } while (!message.equalsIgnoreCase("close"));




        } catch (UnknownHostException ex)
        {
            ex.printStackTrace();
        } catch (IOException ex)
        {
            ex.printStackTrace();
        } finally
        {
            try
            {
                client.close();
                System.out.print("Connection Closed..");
                System.exit(0);
            } catch (IOException ex)
            {
                ex.printStackTrace();
            }
            
        }

    }
}
