import java.util.Arrays;
import java.util.Scanner;

public class ex4 {
  public static void main(String args[]) {
    String[] names = new String[10];
    Scanner sc = new Scanner(System.in);

    for (int i = 0; i < names.length; i++) {
      System.out.printf("Digite um nome: ");
      names[i] = sc.nextLine();
    }

    System.out.printf("\nDigite um nome para checar: ");
    String check = sc.nextLine();

    if (Arrays.stream(names).anyMatch(check::equals)) {
      System.out.printf("O nome %s pertence ao array\n", check);
    } else {
      System.out.printf("O nome %s näo pertence ao array\n", check);
    }

    sc.close();
  }
}
