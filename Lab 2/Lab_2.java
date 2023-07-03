import java.util.Random;
import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class Lab_2 {
  public static void main (String[] args) throws IOException {
    PrintWriter outputFile1 = new PrintWriter("Lab_2.txt");
    for (int i = 0; i < 10; i++) {
      Random rand = new Random();
      outputFile1.println(rand.nextInt(1000));
    }
    outputFile1.close();
    System.out.println("Written to Lab_2.txt");


    File file = new File("Lab_2.txt");
    Scanner inputFile = new Scanner(file);
    String[] a = new String[10];
    for (int i = 0; i < 10; i++) {
      a[i] = inputFile.nextLine();
    }
    System.out.println(Arrays.toString(a));
    Arrays.sort(a);
    System.out.println("\nThe sorted array is: ");
    System.out.println(Arrays.toString(a));
    JOptionPane.showMessageDialog(null, "The maximum value is " + a[9]);
    System.exit(0);
  }

}
