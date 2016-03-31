//Setting the icon on JFrame
import javax.swing.*;
import java.awt.*;

class MyPanel extends JPanel{
	public MyPanel(){
		setBackground(Color.white);
	}
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		Font f=new Font("Arial",Font.BOLD,20);
		g.setFont(f);
		g.setColor(Color.magenta);
		g.drawString("Welcome to Swings",50,50);
	}
}
class MyFrame extends JFrame{
	MyPanel mp;
	public MyFrame(String title){
		super(title);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container ct=super.getContentPane();
		ct.setBackground(Color.green);
		
		Toolkit tk=Toolkit.getDefaultToolkit();
		Dimension d=tk.getScreenSize();
		setBounds(d.width/4,d.height/4,d.width/2,d.height/2);
	
		Image im=tk.getImage("D:/SwingExperiments/src/fog.png");
		this.setIconImage(im);
	
		mp=new MyPanel();
		ct.add(mp);
	}
}

class Test5{
	public static void main(String args[]){
		MyFrame fr=new MyFrame("Test2");
	}
}