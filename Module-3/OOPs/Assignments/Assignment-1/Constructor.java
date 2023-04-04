import java.util.*;

class Student {
  static int studentCount = 0;
  int id;
  String name;
  int age;

{
    this.id = ++studentCount;
    System.out.println("Instance block");
  }

  static {
        System.out.println("Static block");
    }



  public Student() {
    this.name = "";
    this.age = 0;
  }

  public Student(String name, int age) {
    this.name = name;
    this.age = age;
  }

  public static int getStudentCount() {
    return studentCount;
  }

  public int getId() {
    return id;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getAge() {
    return age;
  }

  public void setAge(int age) {
    this.age = age;
  }

  public void displayStudent() {
    System.out.println("Student ID: " + id);
    System.out.println("Name: " + name);
    System.out.println("Age: " + age + "\n");
  }
}

public class Constructor {
  public static void main(String[] args) {

    Scanner scan = new Scanner(System.in);

    Student student1 = new Student();

    System.out.println("Enter your name: ");
    String name = scan.next();
    student1.setName(name);

    System.out.println("Enter your age: ");
    int age = scan.nextInt();
    student1.setAge(age);

    student1.displayStudent();

    Student student2 = new Student("Pranav", 19);
    student2.displayStudent();

    Student student3 = new Student("Mayur", 19);
    student3.displayStudent();

    System.out.println("Number of Students: " + Student.getStudentCount());

    scan.close();
  }
}
