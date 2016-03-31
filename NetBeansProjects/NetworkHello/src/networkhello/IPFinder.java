package networkhello;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class IPFinder
{

    public String findIPAddress(String host)
    {
        String ipAddress = "";

        try
        {

            InetAddress address = InetAddress.getByName(host);

            ipAddress=address.toString();
            
        } catch (UnknownHostException ex)
        {
            Logger.getLogger(IPFinder.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        return ipAddress;
    }

    public static void main(String args[])
    {
        String host=null;
        IPFinder ipFinder = new IPFinder();

        Scanner input = new Scanner(System.in);
        System.out.print("\n\nEnter host name: ");

        host = input.next();

        System.out.println("\n\nIP  Address:"+ipFinder.findIPAddress(host));

    }
}
