import java.util.Scanner;

public class InterfaceUsuario {
  private Scanner teclado = new Scanner(System.in); 
  public void interface() {
    System.out.printf("Escolha uma das opcoes: \n1) insere \n2) salvar lista\n3) sair pelo amor de deus.");
    int entrada = teclado.nextInt();
    while (entrada != 3) {
      switch (entrada) {
        case 1:
          System.out.printf("ler aluno"); 
          break;
        case 2:
          break;
        case 3: 
      }
    }
  }
}
