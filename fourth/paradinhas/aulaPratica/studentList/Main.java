public class Main {
  public static void main(String args[]) {
    CadastraAluno manager = new CadastraAluno();
    Interface myInterface = new Interface(manager);

    myInterface.run();
  }
}
