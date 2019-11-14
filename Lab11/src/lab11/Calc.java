package lab11;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Dialog {
    Dialog(String s1,String s2){
        try {
            int i = Integer.parseInt(s1.trim()),j=Integer.parseInt(s2.trim());
            int z=i+j;
            JOptionPane.showMessageDialog(new JLabel(),z);
        } catch(NumberFormatException e){
            JOptionPane.showMessageDialog(new JLabel(),"ILLEGAL");
        }

    }
}
class Frame {
    Frame(){
        JFrame jf = new JFrame();
        JTextField f1 = new JTextField("Num 1",JLabel.CENTER);
        JTextField f2 = new JTextField("Num 2",JLabel.CENTER);
        JButton calc = new JButton("Calculate");
        //Defining Layout
        jf.setSize(500,100);
        jf.setLayout(new GridLayout(1,3));
        f1.setSize(150,80);f2.setSize(150,80);
        //Focus Fields
        f1.addFocusListener(new FocusListener(){
            public void focusGained(FocusEvent e){
                if(f1.getText().trim().equals("Num 1"))
                f1.setText("");
            }
            public void focusLost(FocusEvent e){
                if(f1.getText().trim().equals(""))
                f1.setText("Num 1");
            }
        });
        f2.addFocusListener(new FocusListener(){
            public void focusGained(FocusEvent e){
                if(f2.getText().trim().equals("Num 2"))
                f2.setText("");
            }
            public void focusLost(FocusEvent e){
                if(f2.getText().trim().equals(""))
                f2.setText("Num 2");
            }
        });
        calc.setSize(80, 80);
        //Action to be performed
        //When Clicked
        calc.addActionListener((ActionEvent e) -> {new Dialog(f1.getText(),f2.getText());});
        //When Entered
        calc.addKeyListener(new KeyListener(){
            public void keyReleased(KeyEvent e){}
            public void keyTyped(KeyEvent e){}
            public void keyPressed(KeyEvent e) {
                if(e.getKeyChar()!='\n'){return;}
                new Dialog(f1.getText(),f2.getText());
            }
        });
        jf.add(f1);jf.add(f2);jf.add(calc);
        jf.setVisible(true);jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
public class Calc {
    public static void main(String[] args) {
        new Frame();
    }
}
