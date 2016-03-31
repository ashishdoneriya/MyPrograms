//Inheriting Frame

import javax.swing.*;
import java.awt.*;

class MyFrame extends JFrame{
	public MyFrame(String title){
		super(title);
		setBounds(100,100,400,400);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container ct=super.getContentPane();
		ct.setBackground(Color.green);
	}
}

class Test2{
	public static void main(String args[]){
		MyFrame fr=new MyFrame("Test2");
	}
}