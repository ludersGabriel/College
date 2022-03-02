import java.io.IOException;
import java.util.Arrays;

public class StudentManager {
  private String dbPath;
  private Student[] students = new Student[10];
  private int reads = 0;

  public StudentManager(String path) {
    setPath(path);
  }

  public void setPath(String path) {
    this.dbPath = path;
  }

  public String getPath() {
    return this.dbPath;
  }

  public void readStudent(String name, String email, String GRR) {
    if (this.reads == this.students.length)
      this.students = Arrays.copyOf(this.students, this.students.length + 50);

    this.students[this.reads] = new Student(name, email, GRR);
    this.reads += 1;
  }

  public void removeStudent(String GRR) {
    int i;
    for (i = 0; i < this.reads && !this.students[i].getGRR().equals(GRR); i++)
      ;
    if (i < this.reads) {
      Student[] temp = new Student[this.reads - 1];

      int j;
      for (i = 0, j = 0; i < this.reads && j < temp.length; i++) {
        if (!this.students[i].getGRR().equals(GRR)) {
          temp[j] = this.students[i];
          j++;
        }
      }
      this.students = temp;
      this.reads -= temp.length;
    }
  }

  public void saveStudents() throws IOException {
    String[] save = new String[this.reads];

    for (int i = 0; i < this.reads; i++) {
      save[i] = new String(this.students[i].stringFormat());
    }

    Db.saveToFile(save, this.dbPath);
  }

}
