import javax.swing.JOptionPane;

public class Lab7 {
  public static void main(String[] args) {
    ProductionWorker e1 = new ProductionWorker();
    ProductionWorker e2 = new ProductionWorker();
    e1.eName = JOptionPane.showInputDialog("Enter Emp1 Name: ");
    e1.eNum = JOptionPane.showInputDialog("Enter Emp1 Number (XXX-L): ");
    e1.hireDate = JOptionPane.showInputDialog("Enter Emp1's Hire Date (XX/XX/XX): ");
    e1.shift = Integer.parseInt(JOptionPane.showInputDialog("Enter 1 for day shift or 2 for night shift: "));
    e1.hourlyPayRate = Double.parseDouble(JOptionPane.showInputDialog("Enter hour pay rate: "));
    e1.salary = e1.hourlyPayRate * 40;
    JOptionPane.showMessageDialog(null, "Emp1's Name: " + e1.eName + "\n" +
                                        "Emp1's Number: " + e1.eNum + "\n" +
                                        "Emp1's Hire date: " + e1.hireDate + "\n" +
                                        "Emp1's Shift (day=1, night=2): " + e1.shift + "\n" +
                                        "Emp1's Hourly pay rate: $" + e1.hourlyPayRate + "\n" +
                                        "Emp1's Salary/week: $" +  e1.salary);
    e2.eName = JOptionPane.showInputDialog("Enter Emp2 Name: ");
    e2.eNum = JOptionPane.showInputDialog("Enter Emp2 Number (XXX-L): ");
    e2.hireDate = JOptionPane.showInputDialog("Enter Emp2's Hire Date (XX/XX/XX): ");
    e2.shift = Integer.parseInt(JOptionPane.showInputDialog("Enter 1 for day shift or 2 for night shift: "));
    e2.hourlyPayRate = Double.parseDouble(JOptionPane.showInputDialog("Enter hour pay rate: "));
    e2.salary = e2.hourlyPayRate * 40;
    JOptionPane.showMessageDialog(null, "Emp2's Name: " + e2.eName + "\n" +
                                        "Emp2's Number: " + e2.eNum + "\n" +
                                        "Emp2's Hire date: " + e2.hireDate + "\n" +
                                        "Emp2's Shift (day=1, night=2): " + e2.shift + "\n" +
                                        "Emp2's Hourly pay rate: $" + e2.hourlyPayRate + "\n" +
                                        "Emp2's Salary/week: $" +  e2.salary);
    System.out.println("Name: " + e1.eName + ", " +
                       "Num: " + e1.eNum + ", " +
                       "Hire date: " + e1.hireDate + ", " +
                       "Shift: " + e1.shift + ", " +
                       "HourlyPayRate: " + e1.hourlyPayRate + ", " +
                       "Salary: $" + e1.salary);
    System.out.println("Name: " + e2.eName + ", " +
                       "Num: " + e2.eNum + ", " +
                       "Hire date: " + e2.hireDate + ", " +
                       "Shift: " + e2.shift + ", " +
                       "HourlyPayRate: " + e2.hourlyPayRate + ", " +
                       "Salary: $" + e2.salary);
  }
}
