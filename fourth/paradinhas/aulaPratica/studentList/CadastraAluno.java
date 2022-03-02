public class CadastraAluno {
  List<Student> lista;

  public CadastraAluno() {
    this.lista = new List<Student>();
  }

  public void insereAluno(String nome, String email, String grr) {
    Student s = new Student(nome, email, grr);
    this.lista.insert(s);
  }
}

// 3) Crie uma classe CadastraAluno com o método insereAluno(nome, email, grr)
// que cria um objeto Aluno e o insira na lista em ordem alfabética.
