import java.util.*;

public class reverseArray{
  public static void main(String args[]){

    int arr[] = {1, 2, 3, 4, 5};
    int rev[] = new int[arr.length];
    int num = 0;

    for(int i=arr.length-1; i>=0; i--){
      rev[num] = arr[i];
      num++;
    }

    System.out.print(Arrays.toString(rev));
  
  }
}

