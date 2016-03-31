//Inheriting Frame

import javax.swing.*;
import java.awt.*;

class MyFrame extends JFrame{
	public MyFrame(String title){
		super(title);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container ct=super.getContentPane();
		ct.setBackground(Color.green);
		
		Toolkit tk=Toolkit.getDefaultToolkit();
		Dimension d=tk.getScreenSize();
		setBounds(d.width/4,d.height/4,d.width/2,d.height/2);
	}
}

class Test3{
	public static void main(String args[]){
		MyFrame fr=new MyFrame("Test2");
	}
}