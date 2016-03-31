package hellothread;

public class Main
{
    public static int count = 0;

    public static void main(String[] args)
    {
        
        Thread t1=new Thread(new MyThread(),"t1");
        Thread t2=new Thread(new SecondThread(),"t2");

        
        t1.start();
        t2.start();

    }
}
