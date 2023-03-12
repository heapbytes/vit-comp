import java.util.*;

public class targetsum {

  private int[] intarr;
  private int tsum;

  public targetsum(int[] intarr, int tsum){
    this.intarr = intarr;
    this.tsum = tsum;
  }

  //  
  //comment above lines then you can use :
  //public static targetsum(int[] intarr, int tsum){}
  //if u used this then in the main function no need to 
  //create objects since targetsum would be static, 
  //so it would look like: 
  //int[] ans = targetsum.targetsum(intarr, tsum);
  //

  public int[] targetsum(){ 

    for(int i=0; i<=intarr.length; i++){
      for(int j=i+1; j<intarr.length; j++){
        if(intarr[i] + intarr[j] == tsum){
          return new int[] {intarr[i], intarr[j]};
        }
      }
    }
    return new int[] {}; 
  }

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int inp;
    int[] intarr;

    System.out.print("Enter a number : ");
    inp = sc.nextInt();

    intarr = new int[inp];

    for(int i=0; i<inp; i++){
      System.out.print("Enter " + i + " number: ");
      intarr[i]=sc.nextInt();
    }

    System.out.print("\nEnter targetsum : ");
    int tsum = sc.nextInt();
    
    targetsum ts = new targetsum(intarr, tsum);
    int[] ans = ts.targetsum();
    System.out.println("\nValues are: " + ans[0] + ", " + ans[1]);

    sc.close();
  }
}
