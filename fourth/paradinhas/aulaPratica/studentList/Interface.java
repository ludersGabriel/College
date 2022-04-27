import java.util.Scanner;

public class Interface {
  private Scanner sc;
  private CadastraAluno manager;

  public Interface(CadastraAluno manager) {
    this.manager = manager;
  }

  public void run() {
    this.sc = new Scanner(System.in);
    System.out.printf("1 para escrever no bd\n2 para inserir aluno\n3 para sair do programa\n");
    int entrada = Integer.parseInt(sc.nextLine());
    while (entrada != 3) {
      switch (entrada) {
        case 1:
          System.out.printf("ler aluno");
          break;
        case 2: {
          System.out.printf("\nNome, email e grr do aluno a ser inserido. Nessa ordem e sem vírgula\n");
          String read = sc.nextLine();
          String[] line = read.split(" ");
          manager.insereAluno(line[0], line[1], line[2]);
          break;
        }
      }
      System.out.printf("\n1 para ler aluno\n2 para inserir aluno\n3 para sair do programa\n");
      entrada = Integer.parseInt(sc.nextLine());
    }
    System.out.println();
    manager.lista.printList();
    sc.close();
  }
}
