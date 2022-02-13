import java.lang.Math;

class ex2 {
  public static void main( String args[] ){
    System.out.printf("Raízes da equação x^2 + x - 6 = 0\n");
    int a = 1;
    int b = 1;
    int c = -6;

    int delta = b*b - 4*a*c;
    double x1 = (- b + Math.sqrt(delta)) / 2*a;
    double x2 =  (- b - Math.sqrt(delta)) / 2*a;

    System.out.printf("Raízes são (x1, x2) = (%f, %f)\n", x1, x2);
  }
}