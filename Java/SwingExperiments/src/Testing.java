import java.awt.*;nel()
	{
		Font f=new Font("Courier",Font.BOLD,25);
		jta=new JTextArea(text,6,8);
		jta.setWrapStyleWord(true);
		jta.setLineWrap(true);
		jta.append("\nThis is the second line");
		jta.append("\nThis is the third line");
		JScrollPane jsp=new JScrollPane(jta);
		add(jsp);
		
		
	}
}	
	
class MyJFrame extends JFrame
{
	MyJPanel jp;
	MyJFrame(String title)
	{
		super(title);
		jp=new MyJPanel();
		getContentPane().add(jp,BorderLayout.CENTER);
		setBounds(100,100,340,400);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
class Testing
{
	public static void main(String args[])
	{
		new MyJFrame("test");
	}
}