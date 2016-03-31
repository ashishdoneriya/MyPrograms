/* A program to demonstrate JLabel */

import java.awt.*;
import javax.swing.*;
class MyJPanel extends JPanel
{
	JLabel jl;
	JTextField jt;
	MyJPanel()
	{
		jl=new JLabel("Hello",new ImageIcon("cool.gif"),SwingConstants.LEFT);
		jl.setVerticalTextPosition(SwingConstants.BOTTOM);
		jl.setHorizontalTextPosition(SwingConstants.CENTER);
		jl.setBackground(Color.blue);
		jl.setOpaque(true);
		jt=new JTextField(10);
		add(jt);
		add(jl);
		
		
	}
}
class MyJFrame extends JFrame
{
	MyJPanel jp;
	MyJFrame(String title)
	{
		super(title);
		jp=new MyJPanel();
		this.getContentPane().add(jp);
		this.setBounds(100,100,300,400);
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
class JLabelDemo
{
	public static void main(String args[])
	{
		MyJFrame fr=new MyJFrame("test");
	}
}