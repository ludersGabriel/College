public class Node<T> {
  private T value;
  private Node<T> prox;

  public Node(T value) {
    setValue(value);
    this.prox = null;
  }

  public Node(T value, Node<T> prox) {
    setValue(value);
    setProx(prox);
  }

  public T getValue() {
    return this.value;
  }

  public void setValue(T value) {
    this.value = value;
  }

  public void setProx(Node<T> prox) {
    this.prox = prox;
  }

  public Node<T> getProx() {
    return this.prox;
  }
}
