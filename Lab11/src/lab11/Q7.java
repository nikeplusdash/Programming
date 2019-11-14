package lab11;
import java.awt.FlowLayout;
import java.awt.event.*;
import javax.swing.*;

class App {
    int i;
    App(){
        i=0;
        JFrame jf = new JFrame("Counter");
        jf.setSize(300, 100);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setLayout(new FlowLayout());
        JLabel label = new JLabel("Counter");
        JTextField count = new JTextField("Count");
        count.setSize(50,80);
        JButton button = new JButton("Count");
        button.addActionListener((ActionEvent e) -> {
            if(!count.getText().equals("Count")) count.setText(Integer.parseInt(count.getText())+1+"");
            else count.setText("0");
        });
        button.addKeyListener(new KeyListener(){
            public void keyTyped(KeyEvent e){}
            public void keyReleased(KeyEvent e){}
            public void keyPressed(KeyEvent e) {
                if(e.getKeyChar()!='\n'){return;}
                if(!count.getText().equals("Count")) count.setText(Integer.parseInt(count.getText())+1+"");
                else count.setText("0");
            }
        });
        jf.add(label);
        jf.add(count);
        jf.add(button);
        jf.setVisible(true);
    }
}

public class Q7 {
    public static void main(String[] args) {
        new App();
    }
}