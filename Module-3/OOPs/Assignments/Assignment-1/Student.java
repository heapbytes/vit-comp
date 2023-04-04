class Student {
  static int prn;
  int PRN;
  String Name;
  String divi;
  static {
    System.out.println("Static block");
    prn = 12220032;
  } {
    System.out.println("Instance block");
  }
  public Student() {}
  public Student(String name, String div) {
    this.Name = name;
    this.divi = div;
    this.PRN = prn;
    prn++;
  }
  public Student(Student another) {
    this(another.Name, another.divi);
  }
  static int getCurrPRN() {
    return prn;
  }
  String getdivi() {
    return this.divi;
  }
  String getName() {
    return this.Name;
  }
  int getPRN() {
    return this.PRN;
  }
  public static void main(String args[]) {
    Student student = new Student("Gourav Balaji Suram", "CS-D");
    System.out.println("Student Name: " +
      student.getName());
    System.out.println("divi: " + student.getdivi());
    System.out.println("PRN: " + student.getPRN());
    System.out.println("Current PRN : "+getCurrPRN());
  }
}
