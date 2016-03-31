package hellothread;

public class SecondThread implements Runnable
{
    public void run()
    {
        while (Main.count < 10)
        {
            
            try
            {
                Main.count++;
                System.out.println("Second Thread -- Count = " + Main.count);
                Thread.sleep(1500);
            } catch (InterruptedException ex)
            {
                ex.printStackTrace();
            }
        }
    }
}