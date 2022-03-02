public class Person {
  private String email;
  private String name;

  public Person(String email, String name) {
    setEmail(email);
    setName(name);
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getEmail() {
    return this.email;
  }

  public String getName() {
    return this.name;
  }

  // public int compareTo(Person p) {
  // return name.compareTo(p.name);
  // }
}
