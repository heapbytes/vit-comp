import java.util.*;

public class smallestNuminArray{
  public static void main(String args[]){

    //Scanner sc = new Scanner(System.in);
    int arr[] = {5, 6, 4, 9, 7, 8}; 
    int min = arr[0];

    for(int i=1; i < arr.length; i++){ 
      if (min > arr[i]){ min = arr[i]; } 
    }
    
    System.out.println("Smallest among the array : " + min);
  }
}

