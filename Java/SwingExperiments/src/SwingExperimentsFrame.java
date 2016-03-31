/**
 * @(#)SwingExperimentsFrame.java
 *
 * JFC SwingExperiments application
 *
 * @author 
 * @version 1.00 2012/5/24
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class SwingExperimentsFrame extends JFrame {
    
    /**
     * The constructor
     */  
	public SwingExperimentsFrame() {
                
        JMenuBar menuBar = new JMenuBar();
        JMenu menuFile = new JMenu();
        JMenuItem menuFileExit = new JMenuItem();
        
        menuFile.setText("File");
        menuFileExit.setText("Exit");
        
        // Add action listener.for the menu button
        menuFileExit.addActionListener
        (
            new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    SwingExperimentsFrame.this.windowClosed();
                }
            }
        ); 
        menuFile.add(menuFileExit);
        menuBar.add(menuFile);
        
        setTitle("SwingExperiments");
        setJMenuBar(menuBar);
        setSize(new Dimension(400, 400));
        
        // Add window listener.
        this.addWindowListener
        (
            new WindowAdapter() {
                public void windowClosing(WindowEvent e) {
                    SwingExperimentsFrame.this.windowClosed();
                }
            }
        );  
    }
    
    
    /**
     * Shutdown procedure when run as an application.
     */
    protected void windowClosed() {
    	
    	// TODO: Check if it is safe to close the application
    	
        // Exit application.
        System.exit(0);
    }
}