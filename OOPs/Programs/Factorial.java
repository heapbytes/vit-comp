import java.util.*;

public class Factorial{
  public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter a number : ");
    int a = sc.nextInt();

    int c = 1 ;
    for(int i=1 ;i<=a; ++i){
      c *= i;
    }
    
    System.out.println("Factorial of "+ a +" is "+ c);
  }
}
