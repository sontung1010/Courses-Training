import javax.swing.*;
import java.awt.event.*;

public class problem3{

   public static void main(String args[]){

       JFrame frame = new JFrame("Button");
       JButton button = new JButton("Click me");

       frame.add(button);
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       frame.setSize(200,200);
       frame.setLocationRelativeTo(null);
       frame.setVisible(true);

       button.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
           JLabel label = new JLabel("Name");
           frame.add(label);
           button.setVisible(false);
//           label.setVisible(true);
           System.out.println("Button clicked");
         }
       });
    }
}
