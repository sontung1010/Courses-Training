import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import java.lang.Math;
class calculator extends JFrame implements ActionListener {
	// create a frame
	static JFrame f;

	// create a textfield
	static JTextField l;

	// store operator and operands
	String s0, s1, s2;

	// default constructor
	calculator()
	{
		s0 = s1 = s2 = "";
	}

	// main function
	public static void main(String args[])
	{
		// create a frame
		f = new JFrame("calculator");

		// create a object of class
		calculator c = new calculator();

		// create a textfield
		l = new JTextField(32);

		// set the textfield to non editable
		l.setEditable(false);

		// create number buttons and some operators
		JButton b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, ba, bs, bd, bm, be, beq, beq1, bSin, bCos, bTan, bLn, bSqr, bPow, bSqu;

		// create number buttons
		b0 = new JButton("0");
		b1 = new JButton("1");
		b2 = new JButton("2");
		b3 = new JButton("3");
		b4 = new JButton("4");
		b5 = new JButton("5");
		b6 = new JButton("6");
		b7 = new JButton("7");
		b8 = new JButton("8");
		b9 = new JButton("9");

		// equals button
		beq1 = new JButton("=");

		// create operator buttons
		ba = new JButton("+");
		bs = new JButton("-");
		bd = new JButton("/");
		bm = new JButton("*");
		beq = new JButton("C");

		// create . button
		be = new JButton(".");
        
        //create trig buttons
        bCos = new JButton("cos");
        bSin = new JButton("sin");
        bTan = new JButton("tan");

        //create exponent buttons
        bSqr = new JButton("sqrt");
        bSqu = new JButton("x^2");
        bPow = new JButton("x^y");
        bLn = new JButton("ln");

        //set button sizes
        b0.setPreferredSize(new Dimension(90, 50));
        b1.setPreferredSize(new Dimension(90, 50));
        b2.setPreferredSize(new Dimension(90, 50));
        b3.setPreferredSize(new Dimension(90, 50));
        b4.setPreferredSize(new Dimension(90, 50));
        b5.setPreferredSize(new Dimension(90, 50));
        b6.setPreferredSize(new Dimension(90, 50));
        b7.setPreferredSize(new Dimension(90, 50));
        b8.setPreferredSize(new Dimension(90, 50));
        b9.setPreferredSize(new Dimension(90, 50));
        ba.setPreferredSize(new Dimension(90, 50));
        bs.setPreferredSize(new Dimension(90, 50));
        bm.setPreferredSize(new Dimension(90, 50));
        bd.setPreferredSize(new Dimension(90, 50));
        beq1.setPreferredSize(new Dimension(90, 50));
        be.setPreferredSize(new Dimension(90, 50));
        bSin.setPreferredSize(new Dimension(90, 50));
        bCos.setPreferredSize(new Dimension(90, 50));
        bTan.setPreferredSize(new Dimension(90, 50));
        bLn.setPreferredSize(new Dimension(90, 50));
        bSqr.setPreferredSize(new Dimension(90, 50));
        bSqu.setPreferredSize(new Dimension(90, 50));
        bPow.setPreferredSize(new Dimension(90, 50));
        beq.setPreferredSize(new Dimension(90, 50));

		// create a panel
		JPanel p = new JPanel();

		// add action listeners
		bm.addActionListener(c);
		bd.addActionListener(c);
		bs.addActionListener(c);
		ba.addActionListener(c);
		b9.addActionListener(c);
		b8.addActionListener(c);
		b7.addActionListener(c);
		b6.addActionListener(c);
		b5.addActionListener(c);
		b4.addActionListener(c);
		b3.addActionListener(c);
		b2.addActionListener(c);
		b1.addActionListener(c);
		b0.addActionListener(c);
		be.addActionListener(c);
		beq.addActionListener(c);
		beq1.addActionListener(c);
        bSin.addActionListener(c);
        bCos.addActionListener(c);
        bTan.addActionListener(c);
        bLn.addActionListener(c);
        bSqr.addActionListener(c);
        bSqu.addActionListener(c);
        bPow.addActionListener(c);

		// add elements to panel
        p.add(l);
		p.add(b7);
        p.add(b8);
        p.add(b9);
        p.add(bd);
        p.add(b4);
        p.add(b5);
        p.add(b6);
        p.add(bm);
        p.add(b1);
        p.add(b2);
        p.add(b3);
        p.add(bs);
        p.add(b0);
        p.add(be);
        p.add(beq1);
        p.add(ba);
        p.add(bSin);
        p.add(bCos);
        p.add(bTan);
        p.add(bLn);
        p.add(beq);
        p.add(bSqr);
        p.add(bPow);
        p.add(bSqu);

		// add panel to frame
		f.add(p);

        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(400, 400);
		f.setVisible(true);
	}
	public void actionPerformed(ActionEvent e)
	{
		String s = e.getActionCommand();

		// if the value is a number
		if ((s.charAt(0) >= '0' && s.charAt(0) <= '9') || s.charAt(0) == '.') {
			// if operand is present then add to second no
			if (!s1.equals(""))
				s2 = s2 + s;
			else
				s0 = s0 + s;

			// set the value of text
			l.setText(s0 + s1 + s2);
		}
        //if the value is clear
		else if (s.charAt(0) == 'C') {
			// clear the one letter
			s0 = s1 = s2 = "";

			// set the value of text
			l.setText(s0 + s1 + s2);
		}
        
        //equal sign
		else if (s.charAt(0) == '=') {

			double te;

			// store the value in 1st
			if (s1.equals("+"))
				te = (Double.parseDouble(s0) + Double.parseDouble(s2));
			else if (s1.equals("-"))
				te = (Double.parseDouble(s0) - Double.parseDouble(s2));
			else if (s1.equals("/"))
				te = (Double.parseDouble(s0) / Double.parseDouble(s2));  
            else if (s1.equals("x^y"))
                te = Math.pow(Double.parseDouble(s0),Double.parseDouble(s2)); 
			else
				te = (Double.parseDouble(s0) * Double.parseDouble(s2));

			// set the value of text
			String text = Double.toString(te);
			l.setText(text);

			// convert it to string
			s0 = Double.toString(te);

			s1 = s2 = "";
		}
        //sin
        else if(s.charAt(0) == 's' && s.charAt(1) == 'i' && s.charAt(2) == 'n'){ //check if sin is selected
            double res = Math.sin(Double.parseDouble(s0)); //calculate
			String te = Double.toString(res); //convert result to string
            l.setText(te); //display
			s0 = te; //set s0 to the result
			s1 = s2 = ""; //clear other fields
        }
		//cos
        else if(s.charAt(0) == 'c' && s.charAt(1) == 'o' && s.charAt(2) == 's'){ //check if cos is selected
            double res = Math.cos(Double.parseDouble(s0)); //calculate
			String te = Double.toString(res); //convert result to string
            l.setText(te); //display
			s0 = te; //set s0 to the result
			s1 = s2 = ""; //clear other fields
        }
		//natural log
        else if(s.charAt(0) == 'l' && s.charAt(1) == 'n'){ //check if ln is selected
            double res = Math.log(Double.parseDouble(s0)); //calculate
			String te = Double.toString(res); //convert result to string
            l.setText(te); //display
			s0 = te; //set s0 to the result
			s1 = s2 = ""; //clear other fields
        }
		//tan
        else if(s.charAt(0) == 't' && s.charAt(1) == 'a' && s.charAt(2) == 'n'){ //check if tan is selected
            double res = Math.tan(Double.parseDouble(s0)); //calculate
			String te = Double.toString(res); //convert result to string
            l.setText(te); //display
			s0 = te; //set s0 to the result
			s1 = s2 = ""; //clear other fields
        }
		//square root
        else if(s.charAt(0) == 's' && s.charAt(1) == 'q' && s.charAt(2) == 'r' && s.charAt(3) == 't'){ //check if sqrt is selected
            double res = Math.sqrt(Double.parseDouble(s0)); //calculate
			String te = Double.toString(res); //convert result to string
            l.setText(te); //display
			s0 = te; //set s0 to the result
			s1 = s2 = ""; //clear other fields
        }
		//square
        else if(s.charAt(0) == 'x' && s.charAt(1) == '^' && s.charAt(2) == '2'){ //check if square is selected
            double res = Math.pow(Double.parseDouble(s0),2); //calculate
			String te = Double.toString(res); //convert result to string
            l.setText(te); //display
			s0 = te; //set s0 to the result
			s1 = s2 = ""; //clear other fields
        }
		else {
			// if there was no operand
			if (s1.equals("") || s2.equals(""))
				s1 = s;
			// else evaluate
			else {
				double te;

				// store the value in 1st
				if (s1.equals("+"))
					te = (Double.parseDouble(s0) + Double.parseDouble(s2));
				else if (s1.equals("-"))
					te = (Double.parseDouble(s0) - Double.parseDouble(s2));
				else if (s1.equals("/"))
					te = (Double.parseDouble(s0) / Double.parseDouble(s2));
                else if (s1.equals("cos"))
                    te = Math.cos(Double.parseDouble(s0));
				else
					te = (Double.parseDouble(s0) * Double.parseDouble(s2));

				// convert it to string
				s0 = Double.toString(te);

				// place the operator
				s1 = s;

				// make the operand blank
				s2 = "";
			}

			// set the value of text
			l.setText(s0 + s1 + s2);
		}
	}
}
