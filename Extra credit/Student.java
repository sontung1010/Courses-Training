import java.util.Scanner;

public class Student {
  private String name;
  private int Id;
  private double Gpa;
  Scanner input = new Scanner(System.in);
  public void setInput() {
    String n = input.nextLine();
    int id = input.nextInt();
    double gpa = input.nextDouble();
    name = n;
    Id = id;
    Gpa = gpa;
  }
  public void output() {
    System.out.print(Id + " " + Gpa + " " + name);
  }
  public static void main(String[] args){
    Student s = new Student();
    s.setInput();
    s.output();
  }
}
