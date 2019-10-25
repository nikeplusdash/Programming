package lab11;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
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
        button.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                count.setText(++i+"");
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