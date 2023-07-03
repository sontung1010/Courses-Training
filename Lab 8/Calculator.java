import java.awt.event.*;
import java.awt.*;
import javax.swing.*;
public class Calculator extends JFrame {
   JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16;
   JTextField res;
   public Calculator() {
      super("Calulator");
      setLayout(new BorderLayout());
      JPanel p = new JPanel();
      p.setLayout(new GridLayout(4,4));

      b1 = new JButton("7");
      p.add(b1);
      b2 = new JButton("8");
      p.add(b2);
      b3 = new JButton("9");
      p.add(b3);
      b4 = new JButton("/");
      p.add(b4);
      b5 = new JButton("4");
      p.add(b5);
      b6 = new JButton("5");
      p.add(b6);
      b7 = new JButton("6");
      p.add(b7);
      b8 = new JButton("*");
      p.add(b8);
      b9 = new JButton("1");
      p.add(b9);
      b10 = new JButton("2");
      p.add(b10);
      b11 = new JButton("3");
      p.add(b11);
      b12 = new JButton("-");
      p.add(b12);
      b13 = new JButton("0");
      p.add(b13);
      b14 = new JButton(".");
      p.add(b14);
      b15 = new JButton("=");
      p.add(b15);
      b16 = new JButton("+");
      p.add(b16);

      res = new JTextField(10);
      add(p,BorderLayout.CENTER);
      add(res,BorderLayout.NORTH);
      setVisible(true);
      setSize(200,200);
      }

  public static void main(String arg[]) {
      new Calculator();
  }
}
