import java.awt.*;
import java.applet.*;
public class FaceApp extends Applet
{
public void init()
{
Button button = new Button("Close");
add(button);
}
public void paint(Graphics g)
{
// Head.
g.drawOval(40, 40, 120, 150);
http://www.ngohaianh.info
// Eyes.
g.drawOval(57, 75, 30, 20);
g.drawOval(110, 75, 30, 20);
// Pupils.
g.fillOval(68, 81, 10, 10);
g.fillOval(121, 81, 10, 10);
// Nose.
g.drawOval(85, 100, 30, 30);
// Mouth.
g.fillArc(60, 130, 80, 40, 180, 180);
// Ears.
g.drawOval(25, 92, 15, 30);
g.drawOval(160, 92, 15, 30);
}
public boolean action(Event evt, Object arg)
{
if (arg == "Close")
http://www.ngohaianh.info
System.exit(0);
return true;
}
public static void main(String args[])
{
FaceApp app = new FaceApp();
Frame frame = new Frame("Face Window");
app.init();
app.start();
frame.add("Center", app);
frame.resize(210, 300);
frame.show();
}
}
