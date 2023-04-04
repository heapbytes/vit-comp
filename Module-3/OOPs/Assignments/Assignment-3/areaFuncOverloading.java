import java.util.Scanner;

class Shape {
  double area() {
    return 0;
  }
}

public class areaFuncOverloading extends Shape {

  public double area(float PIE, int r){
    return PIE * ( r * r );
  }

  public double area(int base, int height){
    return (base * height) / 2;
  }

  public double area(int side){
    return side * side;
  }
  
  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);

    int r, base, height, side;
    float PIE;

    areaFuncOverloading ar = new areaFuncOverloading();

    System.out.print("Enter PIE value : ");
    PIE = sc.nextFloat();
    System.out.print("Enter radius : ");
    r = sc.nextInt();
    System.out.println("Area of circle = " + ar.area(PIE, r) + "\n");

    System.out.print("Enter side of a square : ");
    side = sc.nextInt();
    System.out.print("Area of square : " + ar.area(side) + "\n");

    System.out.print("\nEnter height : ");
    height = sc.nextInt();
    System.out.print("Enter base : ");
    base = sc.nextInt();
    System.out.print("Area of Triangle : " + ar.area(base, height) + "\n");

    sc.close();

  }
}
