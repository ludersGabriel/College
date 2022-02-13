import java.lang.Math;
import java.util.HashMap;
import java.util.Map;

class ex1 {
  static int sorteio() {
    return (int) (Math.random() * 5);
  }

  public static void main(String args[]) {
    Map<Integer, String> names = new HashMap<Integer, String>();
    names.put(0, "Gabriel");
    names.put(1, "Richard");
    names.put(2, "Iago");
    names.put(3, "Vudala");
    names.put(4, "Ana");

    int num = sorteio();
    System.out.printf("Vencedor é: %s\n", names.get(num));

  }
}