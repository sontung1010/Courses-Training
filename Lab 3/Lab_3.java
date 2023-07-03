import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileReader;
import java.io.IOException;
import java.io.*;

public class Lab_3 {
  public static void main (String[] args) throws IOException {
    List<Double> stngFile = new ArrayList<Double>();
    Scanner sc = new Scanner(new FileReader("Numbers.txt"));
    Double str;
    while (sc.hasNext()) {
      str = sc.nextDouble();
      stngFile.add(str);
    }
    Double[] array = stngFile.toArray(new Double[0]);

    double sum = 0.0;
    double sumsd = 0.0;
    double sd = 0.0;
    double mean = 0.0;
    double sqr = 0.0;

    int l = array.length;
    for (int i = 0; i < l; i++) {
      sum = sum + array[i];
    }

    mean = sum/l;
    System.out.println(mean);

    for (int i = 0; i < l; i++) {
      array[i] = Math.pow(array[i] - mean,2);
    }
    for (int i = 0; i < l; i++) {
      sumsd = sumsd + array[i];
    }
    sd = Math.pow((sumsd/l),(1/2));
    System.out.println(sd);

    PrintWriter output = new PrintWriter("Result.txt");
    output.printf("mean = %.4f", mean);
    output.printf("\nstandard deviation = %.4f", sd);
    output.close();
    System.exit(0);
  }
}
