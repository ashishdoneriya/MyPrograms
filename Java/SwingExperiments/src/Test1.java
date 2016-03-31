import javax.swing.*;
import java.awt.*;
class Test1{
	public static void main(String args[]){
		JFrame fr=new JFrame("Test1");
		fr.setBounds(100,100,400,400);
		fr.setBackground(Color.red);
		//colour noot Change here
		fr.setVisible(true);
		
		
		Container ct=fr.getContentPane();
		ct.setBackground(Color.green);
		fr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		}
}