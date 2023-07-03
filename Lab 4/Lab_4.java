import java.util.Scanner;

public class Lab_4 {
  //Task #1
  public static void printMenu() {
    System.out.println("This is a geometry calculator");
    System.out.println("\n");
    System.out.println("Choose what you would like to calculate");
    System.out.println("1. Find the area of a circle");
    System.out.println("2. Find the area of a rectangle");
    System.out.println("3. Find the area of a triangle");
    System.out.println("4. Find the circumference of a circle");
    System.out.println("5. Find the parameter of a rectangle");
    System.out.println("6. Find the perimeter of a triangle");
    System.out.println("Enter the number of your choice: ");
  }

  //Task #2
  public static double circleArea(double r) {
    return Math.PI*(r*r);
  }
  public static double rectangleArea(double l, double w) {
    return l*w;
  }
  public static double triangleArea(double b, double h) {
    return 0.5*b*h;
  }
  public static double circleCircumference(double r) {
    return 2*(Math.PI)*r;
  }
  public static double rectanglePerimeter(double l, double w) {
    return (l+w)*2;
  }
  public static double trianglePerimeter(double x, double y, double z) {
    return x+y+z;
  }

  //Task #3
  public static void main (String[] args) {
    printMenu();

    int input;
    double result = 0;
    double R, L, W, B, H, X, Y, Z;

    Scanner keyboard = new Scanner(System.in);
    input = keyboard.nextInt();

    if (input == 1) {
      System.out.print("Radius: ");
      R = keyboard.nextDouble();
      result = circleArea(R);
      System.out.println("The area of the circle is: " + result);
    }
    else if (input == 2) {
      System.out.print("Length: ");
      L = keyboard.nextDouble();
      System.out.print("Width: ");
      W = keyboard.nextDouble();
      result = rectangleArea(L, W);
      System.out.println("The area of the rectangle is " + result);
    }
    else if (input == 3) {
      System.out.print("Base: ");
      B = keyboard.nextDouble();
      System.out.print("Height: ");
      H = keyboard.nextDouble();
      result = triangleArea(B, H);
      System.out.println("The area of triangle is " + result);
    }
    else if (input == 4) {
      System.out.print("Radius: ");
      R = keyboard.nextDouble();
      result = circleCircumference(R);
      System.out.println("The circumference of the circle is: " + result);
    }
    else if (input == 5) {
      System.out.print("Length: ");
      L = keyboard.nextDouble();
      System.out.print("Width: ");
      W = keyboard.nextDouble();
      result = rectanglePerimeter(L, W);
      System.out.println("The perimeter of the rectangle is: " + result);
    }
    else if (input == 6) {
      System.out.print("First side: ");
      X = keyboard.nextDouble();
      System.out.print("Second side: ");
      Y = keyboard.nextDouble();
      System.out.print("Third side: ");
      Z = keyboard.nextDouble();
      result = trianglePerimeter(X, Y, Z);
      System.out.println("The perimeter of the rectangle is: " + result);
    }
    else {
      System.out.println("Invalid choice, try again");
    }
    System.exit(0);
  }
}
