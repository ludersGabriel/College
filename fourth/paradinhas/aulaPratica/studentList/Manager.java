import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Manager {
  public static void main(String args[]) throws IOException {
    File testFile = new File("./teste.txt");
    Scanner sc = new Scanner(testFile);
    StudentManager sm = new StudentManager("./students.txt");

    for (int i = 0; i < 9; i++) {
      String input = sc.nextLine();
      String[] inputs = input.split("\\s+");

      sm.readStudent(inputs[2], inputs[1], inputs[0]);
    }

    sm.saveStudents();

    sc.close();
  }
}
