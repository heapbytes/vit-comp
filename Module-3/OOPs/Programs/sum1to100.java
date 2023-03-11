public class sum1to100 {
   public static void main(String[] args) {
      
      int sum = 0;
      for(int i=2; i<=100; i+=2){
        sum += i;
      }
      System.out.println("Sum is : " + sum);

   }
}
