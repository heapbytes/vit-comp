import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public class CSP {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String s1 = "SATURN";
        String s2 = "URANUS";
        String s3 = "PLANETS";
        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s1.length(); i++) {
            if (!map.containsKey(s1.charAt(i)))
                map.put(s1.charAt(i), -1);
        }

        for (int i = 0; i < s2.length(); i++) {
            if (!map.containsKey(s2.charAt(i)))
                map.put(s2.charAt(i), -1);
        }

        for (int i = 0; i < s3.length(); i++) {
            if (!map.containsKey(s3.charAt(i)))
                map.put(s3.charAt(i), -1);
        }

        char[] unique = new char[map.size()];
        int k = 0;
        for (char c : map.keySet()) {
            unique[k++] = c;
        }

        boolean[] visited = new boolean[10];

        solution(0, map, unique, visited, s1, s2, s3);

        scan.close();
    }

    public static void solution(int index, Map<Character, Integer> map, char[] unique, boolean[] visited, String s1, String s2, String s3) {
        if (index >= unique.length) {
            int n1 = toNum(map, s1);
            int n2 = toNum(map, s2);
            int n3 = toNum(map, s3);

            if (n1 + n2 == n3) {
                for (char c : map.keySet()) {
                    System.out.println(c + ": " + map.get(c));
                }
                System.out.println();
                System.out.println(n1 + " + " + n2 + " = " + n3);
            }
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (visited[i] == false) {
                map.put(unique[index], i);
                visited[i] = true;
                solution(index + 1, map, unique, visited, s1, s2, s3);
                visited[i] = false;
                map.put(unique[index], -1);
            }
        }
    }

    public static int toNum(Map<Character, Integer> map, String s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            num = num * 10 + map.get(s.charAt(i));
        }
        return num;
    }
}
