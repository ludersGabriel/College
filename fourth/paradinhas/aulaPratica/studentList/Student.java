public class Student extends Person {
  private String GRR;

  public Student(String name, String email, String GRR) {
    super(name, email);
    setGRR(GRR);
  }

  public void setGRR(String GRR) {
    this.GRR = GRR;
  }

  public String getGRR() {
    return this.GRR;
  }

  public String stringFormat() {
    return getGRR() + ' ' + getName() + ' ' + getEmail();
  }
}
