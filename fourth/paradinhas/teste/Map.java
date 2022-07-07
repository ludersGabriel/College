import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Vector;

public class Map<T> {
  T[] elements;
  String[] keys;

  public Map(Class<T> clazz) {
    this.keys = new String[10];
    this.elements = (T[]) Array.newInstance(clazz, 10);

    Vector<String> list2 = new Vector<String>();
    list2.add("gabriel");
    list2.add("marcelo");

    Iterator itr = list2.iterator();
    while (itr.hasNext())
      System.out.println(itr.next());

    System.out.println(list2.size());

    ArrayList<String> list = new ArrayList<String>();
    list.add("gabriel");
    list.add("marcelo");
    list.remove(new String("gabriel"));
    System.out.println(list.size());
  }
}