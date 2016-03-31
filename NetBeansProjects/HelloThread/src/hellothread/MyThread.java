package hellothread;

/**
 *
 * @author sanit
 */
public class MyThread implements Runnable
{
    public void run()
    {
        while (Main.count < 10)
        {
            try
            {

                Main.count++;
                System.out.println("My Thread -- Count = " + Main.count);            
                Thread.sleep(1000);
                
            } catch (InterruptedException ex)
            {
                ex.printStackTrace();
            }
        }
    }
}
