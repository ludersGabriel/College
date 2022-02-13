import java.util.Scanner;

public class ex2 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int[] nums = new int[10];
    float average = 0;
    int sum = 0;

    for (int i = 0; i < nums.length; i++) {
      System.out.printf("Enter a number: ");
      int temp = sc.nextInt();
      nums[i] = temp;
      sum += temp;
    }

    average = sum / nums.length;
    System.out.printf("Average age: %f\n", average);
    System.out.printf("Bellow average age: ");
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] < average) {
        System.out.printf("%d ", nums[i]);
      }
    }

    System.out.printf("\nAbove average age: ");
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] > average) {
        System.out.printf("%d ", nums[i]);
      }
    }

    System.out.printf("\n");

    sc.close();
  }
}
