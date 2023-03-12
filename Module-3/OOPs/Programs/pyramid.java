import java.util.*;

public class pyramid {
  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    System.out.print("Enter no. of rows : ");
    int inp = sc.nextInt();

    for(int i=1; i<=inp; i++){

      for(int j=inp; j>i; j--){ System.out.print(" "); }

      for(int k=1; k<=(2*i)-1; k++){ System.out.print("*"); }

      System.out.print("\n");
    
    }
    sc.close();
  }
}
