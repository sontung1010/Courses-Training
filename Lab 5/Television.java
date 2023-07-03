import java.util.Scanner;

public class Television {

  private String MANUFACTURER;
  private int SCREEN_SIZE;
  private boolean powerOn;
  private int channel;
  private int volume;

  //initialize objects
  public Television(String brand, int screensize){
    MANUFACTURER = brand;
    SCREEN_SIZE = screensize;
    powerOn = false;
    channel = 2;
    volume = 20;
  }

  //read volume
  public int getVolume(){
    return volume;
  }
  //read channel
  public int getChannel(){
    return channel;
  }
  //get brand
  public String getManufacturer(){
    return MANUFACTURER;
  }
  //get screen size
  public int getScreenSize(){
    return SCREEN_SIZE;
  }
  //method to accept a value and assign to channel
  public void setChannel(int c){
    channel = c;
  }
  //method to set power to false
  public void power(){
    powerOn = !powerOn;
  }
  //increase volume value by 1
  public void increaseVolume(){
    volume++;
  }
  //decrease volume value by 1
  public void decreaseVolume(){
    volume--;
  }

  public static void main(String[] args){
    int c;

    Scanner keyboard = new Scanner(System.in);

    Television TV = new Television("Toshiba", 55);
    TV.power();

    System.out.println("A " + TV.getScreenSize() + " inch " + TV.getManufacturer() + " has been turned on.");
    TV.increaseVolume();

    System.out.print("What channel would you like to watch? ");
    c = keyboard.nextInt();
    TV.setChannel(c);

    System.out.println("Channel: " + TV.getChannel() + " Volume: " + TV.getVolume() + " Too loud! Lowering the volume.");

    TV.decreaseVolume();
    TV.decreaseVolume();
    TV.decreaseVolume();
    TV.decreaseVolume();
    TV.decreaseVolume();
    TV.decreaseVolume();
    System.out.println("Channel: " + TV.getChannel() + " Volume: " + TV.getVolume());
  }
}
