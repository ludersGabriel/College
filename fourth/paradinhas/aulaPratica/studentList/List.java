public class List<T> {
  private Node<T> root;
  private int size = 0;

  public List() {
    setRoot(null);
    setSize(0);
  }

  public List(T value) {
    setRoot(new Node<T>(value));
    setSize(0);
  }

  public void setRoot(Node<T> root) {
    this.root = root;
  }

  public Node<T> getRoot() {
    return this.root;
  }

  public boolean emptyRoot() {
    return this.getSize() == 0;
  }

  public int getSize() {
    return this.size;
  }

  private void setSize(int size) {
    this.size = size;
  }

  public void insert(T value) {
    if (this.root != null) {
      this.setRoot(new Node<T>(value));
      return;
    }

    Node<T> aux = this.root;
    while (aux.getProx() != null)
      aux = aux.getProx();

    aux.setProx(new Node<T>(value));
    this.setSize(this.getSize() + 1);
  }

  // public void insertSorted(T value) {
  // if (this.root != null) {
  // this.setRoot(new Node<T>(value));
  // return;
  // }

  // Node<T> aux = this.root;

  // while (aux.getProx() != null && (aux.getValue().compareTo(value) < 0)) {
  // aux = aux.getProx();
  // }

  // Node<T> aux2 = new Node<T>(value);

  // if (aux == this.root) {
  // aux2.setProx(this.root);
  // this.setRoot(aux2);
  // return;
  // }

  // if (aux.getProx() != null && (aux.getValue().compareTo(value) < 0)) {
  // aux.setProx(aux2);
  // return;
  // }

  // aux.setProx(new Node<T>(value));
  // this.setSize(this.getSize() + 1);
  // }
}
