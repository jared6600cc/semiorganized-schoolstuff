public class Outer {

  private int x = 10;

  public void f() {
    Inner inner = new Inner();
    inner.g();
    inner.y = 5;
    System.out.println("inner.y = "+inner.y);
    System.out.println("x = "+x);
  }

  private class Inner {
    private int y;
    private int x;  // comment this
    //Outer o1 = new Outer();
    //o1.f();
    
    private void g() 
    { 
      x = 15; 
    }
  }  
  
  public static void main(String[] args)
  {
    Outer o = new Outer();
    o.f();
    //System.out.println("x = "+x);
  }  
}