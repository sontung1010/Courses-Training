import javax.swing.JOptionPane;

/**
   This program demonstrates using dialogs with JOptionPane.
*/

public class Lab1 {
  public static int binarySearch(int arr[], int start, int end, int x) {
    if (end >= start) {
      int mid = start + (end - start)/2;
      if (arr[mid] == x) {
        return mid;
      }
      if (arr[mid] > x) {
        return binarySearch(arr, start, mid-1, x);
      }
      else {
        return binarySearch(arr, mid+1, end, x);
      }
    }
    return -1;
  }

  public static void main(String[] args) {
     int numbers[] = { 3, 6, 7, 8, 12, 15, 22, 36, 45, 48, 51, 53, 64, 69, 72, 89, 95};
     String input; // For reading input
     int end = numbers.length - 1;
     // Get the user's input
     input = JOptionPane.showInputDialog("What is your search key? ");
     int key = Integer.parseInt(input);

     int result = binarySearch(numbers, 0, end, key);
     //Display the reuslt
     if (result == -1) {
       JOptionPane.showMessageDialog(null, "Key not found");
     }
     else {
       JOptionPane.showMessageDialog(null, "Your search key is at index " + result);
     }
     // End the program.
     System.exit(0);
   }
}
