package hellosocket;


import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

/**
 *
 * @author sanit
 */
public class Server
{

    static final int port=4242;
    static ServerSocket server ;

    public static void main(String[] args)
    {

        Scanner input;

        int count=0;
        String message="start";
         Socket socket;
        
        try
        {
            server= new ServerSocket(port);

            socket = server.accept();

            System.out.println("Client Accepted....");
            System.out.println("***************************************************");

            while(!message.equals("close"))
            {
                input=new Scanner(new InputStreamReader(socket.getInputStream()));

                message=input.nextLine();
                //print message sent by client
                System.out.println("SERVER"+count+">"+message);
                
                count++;
            }

        } catch (IOException ex)
        {
            ex.printStackTrace();
        }
        finally
        {
            try
            {                
                server.close();
                System.out.print("Connection Closed..");
                System.exit(0);
            } catch (IOException ex)
            {
                ex.printStackTrace();
            }
        }
    }
}
