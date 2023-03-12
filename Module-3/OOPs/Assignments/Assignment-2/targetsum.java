import java.util.*;
/*

There is a class Adder which has two data members of type 1D int array and int variable. It
has two functions: getdata and numsum. Function getdata accepts non-empty array of
distinct integers from user in 1D int array data member and a targetsum in another data
member. The function numsum adds any two elements from an input array which is equal to
targetsum and return an array of resulting two elements, in any order. If no two numbers
sum up to the target sum, the function should return an empty array. Note that the target sum
is to be obtained by summing two different integers in the array; you can’t add a single
integer to itself in order to obtain the target sum. You can assume that there will be at most
one pair of numbers summing up to the target sum. Use constructor. Use extra variables if
needed

Input:
Array=[3,5,-4,8,11,1,-1,7] targetsum=15
Output: [8,7]
Input:
Array=[3,5,-4,8,11,1,-1,6] targetsum=15
Output: []

*/

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
