import static java.lang.System.out;
class MyThread implements Runnable{
	Thread th;
	public MyThread(String name){
		th=new Thread(this,name);
		th.start();
	}
	public void run(){
		try{
			for(int i=0;i<=10;i=i+2){
				out.println(th.getName()+":"+i);
				Thread.sleep(2);
			}
		}
		catch(Exception e){
			out.println(e);
		}
		out.println(th.getName()+" ends");
	}
}
class ThreadTest{
	public static void main(String args[]){
		MyThread t1=new MyThread("even");
		Thread t2=Thread.currentThread();
		try{
			for(int i=1;i<=10;i=i+2){
				out.println(t2.getName()+":"+i);
				Thread.sleep(1);
			}
		}
		catch(Exception e){
			out.println(e);
		}
		out.println(t2.getName()+" ends");
	}
}
