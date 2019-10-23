package lab11;
import javax.swing.*;

class Window {
    Window(){
        JFrame jf = new JFrame("Hello World");
        jf.setSize(300,200);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel label = new JLabel("Hello World");
        label.setHorizontalAlignment(JLabel.CENTER);
        label.setVerticalAlignment(JLabel.CENTER);
        jf.add(label);
        jf.setVisible(true);
    }
}
public class Q6 {
    public static void main(String[] args) {
        new Window();
    }
}
