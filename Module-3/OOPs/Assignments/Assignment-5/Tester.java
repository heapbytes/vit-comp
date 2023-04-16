import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
class Order {

    int orderId;
    List<String> itemNames;
    boolean isCOD;
    public Order(int orderId, List<String> itemNames, boolean isCOD) {
        this.orderId = orderId;
        this.itemNames = itemNames;
        this.isCOD = isCOD;
    }
    public List<String> getItems() {
        return itemNames;
    }
}
class Tester {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Order> orders = new ArrayList<>();
        System.out.print("Enter number of orders: ");
        int n = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < n; i++) {
            System.out.printf("Enter order %d details:\n", i + 1);
            System.out.print("Enter order ID: ");
            int orderId = scanner.nextInt();
            scanner.nextLine();
            System.out.print("Enter items separated by commas: ");
            String[] itemNamesArray = scanner.nextLine().split(",");
            System.out.print("Is it a cash on delivery? (true/false): ");
            boolean isCOD = scanner.nextBoolean();
            List<String> itemNames = new ArrayList<>();
            for (String itemName : itemNamesArray) {
                itemNames.add(itemName.trim());
            }
            Order order = new Order(orderId, itemNames, isCOD);
            orders.add(order);
        }
        List<String> allItems = new ArrayList<>();
        for (Order order : orders) {
            allItems.addAll(order.getItems());
        }
        System.out.println("All ordered items: " + allItems);
    }
}

