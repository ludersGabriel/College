import java.util.Scanner;

class ex4 {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    System.out.printf("Enter a number: ");
    int num = sc.nextInt();

    if (num >= 0)
      System.out.printf("%d is positive\n", num);
    else
      System.out.printf("%d is negative\n", num);

    sc.close();
  }

}