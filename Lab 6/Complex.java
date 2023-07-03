import javax.swing.JOptionPane;

public class Complex {
  double real;
  double imaginary;

  public Complex(double r, double i) {
    this.real = r;
    this.imaginary = i;
  }
  public static Complex add(Complex n1, Complex n2) {
    Complex sum = new Complex(0, 0);
    sum.real = n1.real + n2.real;
    sum.imaginary = n1.imaginary + n2.imaginary;
    return sum;
  }
  public static Complex subtract(Complex n1, Complex n2) {
    Complex diff = new Complex(0,0);
    diff.real = n1.real - n2.real;
    diff.imaginary = n1.imaginary - n2.imaginary;
    return diff;
  }
  public static Complex multiply(Complex n1, Complex n2) {
    Complex prod = new Complex(0, 0);
    prod.real = (n1.real * n2.real) - (n1.imaginary * n2.imaginary);
    prod.imaginary = (n1.real * n2.imaginary) + (n1.imaginary * n2.real);
    return prod;
  }
  public static void printDialog(Complex n1, Complex n2, Complex sum, Complex diff, Complex prod) {
    JOptionPane.showMessageDialog(null, "a = " + "(" + n1.real + "," + n1.imaginary + ")" + "\n" +
                                        "b = " + "(" + n2.real + "," + n2.imaginary + ")" + "\n" +
                                        "a + b = " + "(" + sum.real + "," + sum.imaginary + ")" + "\n" +
                                        "a - b = " + "(" + diff.real + "," + diff.imaginary + ")" + "\n" +
                                        "a * b = " + "(" + prod.real + "," + prod.imaginary + ")");
  }

  public static void main(String[] args) {
    Complex com1 = new Complex(9.5, 7.7);
    Complex com2 = new Complex(1.2, 3.1);
    Complex sum = add(com1, com2);
    Complex diff = subtract(com1, com2);
    Complex prod = multiply(com1, com2);
    printDialog(com1, com2, sum, diff, prod);
  }
}
