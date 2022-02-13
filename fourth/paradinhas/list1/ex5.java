import java.io.*;
import java.util.Scanner;

class ex4 {

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);

    System.out.printf("Enter a number: ");
    int num = sc.nextInt();



    if(num % 2 == 0)
      System.out.printf("%d is even\n", num);
    else  
      System.out.printf("%d is odd\n", num);
  }

}