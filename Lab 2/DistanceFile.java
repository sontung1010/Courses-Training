import java.util.Scanner;
import java.io.*;

/**

This program demonstrates a solution to the

Distance File programming challenge.

*/

public class DistanceFile {
public static void main(String[] args) throws IOException {

double speed; // The vehicle's speed

int maxHours, // Max number of hours traveled

period; // To count time periods

// Create a Scanner object for keyboard input.

Scanner keyboard = new Scanner(System.in);

// Get the speed.

System.out.print("Enter the vehicle's speed: ");

speed = keyboard.nextDouble();

// Validate the speed.

while (speed < 0)

{

System.out.print("Enter 0 or greater for speed: ");

speed = keyboard.nextDouble();

}

// Get the number of hours.

System.out.print("Enter the number of hours the " +

"vehicle was in motion: ");

maxHours = keyboard.nextInt();

// Validate the hours.

while (maxHours < 1)

{

System.out.print("Enter 1 or greater for hours: ");

maxHours = keyboard.nextInt();

}

// Create the objects necessary to perform file output.

FileWriter fw = new FileWriter("DistanceReport.txt");

PrintWriter outFile = new PrintWriter(fw);

// Write the table header.

outFile.println("Hour\tDistance Traveled");

outFile.println("----------------------------------");

// Write the table of distances.

period = 1;

while (period <= maxHours)

{

// Display the distance for this period.

outFile.println(period + "\t\t" + period * speed);

// Increment period.

period++;

}

// Close the file.

outFile.close();

System.out.println("Report written to DistanceReport.txt.");

}

}
