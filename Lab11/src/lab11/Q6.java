package lab11;
import java.awt.GridLayout;
import javax.swing.*;

class Window {
    Window(){
        JFrame jf = new JFrame("Hello World");
        jf.setSize(500,500);
        jf.setLayout(new GridLayout(4,3));
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        ImageIcon i = new ImageIcon("C:\\Users\\nikep\\Downloads\\unsplash.jpg");
//        JLabel label = new JLabel("Hello World",i,JLabel.CENTER);
        for(int i=1;i<10;i++) {JLabel label = new JLabel(i+"",JLabel.CENTER);
//        label.setHorizontalAlignment(JLabel.CENTER);
//        label.setVerticalAlignment(JLabel.CENTER);
        jf.add(label);
        }
        JLabel label = new JLabel(0+"",JLabel.CENTER);
        jf.add(label);
        jf.setVisible(true);
    }
}
public class Q6 {
    public static void main(String[] args) {
        new Window();
    }
}
