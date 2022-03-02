import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Db {
  public static String[] readFile(String path) throws IOException {
    List<String> studentList = new ArrayList<String>();

    studentList = Files.readAllLines(Paths.get(path));

    String[] ret = studentList.toArray(new String[0]);
    return ret;
  }

  public static void saveToFile(String[] students, String path) throws IOException {
    String[] db = readFile(path);

    List<String> list = new ArrayList<String>(Arrays.asList(db));
    list.addAll(new ArrayList<String>(Arrays.asList(students)));

    String[] ret = list.toArray(new String[0]);

    Set<String> set = new HashSet<String>();
    for (String string : ret) {
      set.add(string);
    }

    ret = set.toArray(new String[0]);

    File out = new File(path);
    try (FileWriter fileWriter = new FileWriter(out); BufferedWriter writer = new BufferedWriter(fileWriter)) {
      for (String str : ret) {
        writer.write(str);
        writer.newLine();
      }
    } catch (FileNotFoundException e) {
      System.out.printf("Unable to open file, file not found\n");
    } catch (IOException e) {
      System.out.printf("Unable to write to file %s\n", out.getName());
    }
  }
}
