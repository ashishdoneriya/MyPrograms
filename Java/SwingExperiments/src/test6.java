//Button Handling

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MyButton extends JButton{
	public MyButton(String title,String ico){
		super(title,new ImageIcon(ico));
		setRolloverEnabled(true);
		setRequestFocusEnabled(true);
		setRolloverIcon(new ImageIcon("D:/SwingExperiments/src/rain.png"));
		setMnemonic(KeyEvent.VK_A);  //Set the keyboard alternative to clicking the button
		setLabel("hi");
	}
}
class MyPanel extends JPanel implements ActionListener{
	MyButton b1;
	public MyPanel(){
		setBackground(Color.white);
		setLayout(null);
		b1=new MyButton("ASHISH","D:/SwingExperiments/src/sun.png");
		add(b1);
		b1.setBounds(100,100,100,100);
	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==b1){
			setBackground(Color.green);
		}
			
	}
}
class MyFrame extends JFrame{
	MyPanel mp;
	public MyFrame(String title){
		super(title);
		mp=new MyPanel();
		Container ct=super.getContentPane();
		Toolkit tk=Toolkit.getDefaultToolkit();
		Dimension d=tk.getScreenSize();
		Image im=tk.getImage("D:/SwingExperiments/src/avatar.gif");
		setBounds(d.width/4,d.height/4,d.width/2,d.height/2);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setIconImage(im);
		ct.add(mp);
	}
}

class Test6{
	public static void main(String args[]){
		MyFrame fr=new MyFrame("Test2");
	}
}