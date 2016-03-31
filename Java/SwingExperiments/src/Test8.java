//JTextField Demo

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MyJPanel extends JPanel{
	JTextField jtf;
	public MyJPanel(){
	//	setLayout(null);
		setBounds(10,10,300,300);
		setVisible(true);
		jtf=new JTextField("Hi Ashish",30);
		this.add(jtf);
		setBackground(Color.black);
		setOpaque(true);
	}
}

class MyFrame extends JFrame{
	MyJPanel mjp;
	public MyFrame(String title){
		super(title);
		mjp=new MyJPanel();
		setContentPane(mjp);
		this.setBounds(0,0,1000,700);
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}

class Test8{
	public static void main(String args[]){
		MyFrame fr=new MyFrame("ASHISH");
	}
}
