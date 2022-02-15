import java.util.Scanner;

public class ex6 {

  public static void main(String args[]) {

    Scanner sc = new Scanner(System.in);

    System.out.printf("Enter a phrase: ");
    String phrase = sc.nextLine();

    String[] words = phrase.split(" ");
    System.out.printf("A frase possui %d palavras\n", words.length);

    sc.close();
  }
}
