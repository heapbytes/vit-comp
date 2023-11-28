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

        //it basically just puts all the characters in the map
        //with a value of -1
        // like this: {S=-1, A=-1, T=-1, U=-1, R=-1, N=-1, P=-1, L=-1}
        //this is done so that we can check if a character is already in the map
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

        //this is just to get all the unique characters in the map
        //and put them in an array
        //result is: [S, A, T, U, R, N, P, L]
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
        //at start index is 0 so this if loop will not run
        //when index is equal to unique.length, it means that we have
        //assigned a value to all the characters in the map
        //so we can now check if the equation is valid
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

        //this loop will run 10 times
        //it will check if the character at unique[index] is already in the map
        //if it is not in the map, it will assign a value to it
        //and then call the solution function again with index + 1
        //if it is in the map, it will not assign a value to it
        //and then call the solution function again with index + 1
        //this is done to check all the possible combinations
        //for e.g if the character at unique[index] is S
        //it will check if S is already in the map
        //if it is not in the map, it will assign a value to it
        //value assigned to s is 0
        //then it will call the solution function again with index + 1
        //now index is 1
        //so it will check if the character at unique[index] is already in the map
        //if it is not in the map, it will assign a value to it
        //and likewise
        //this is done to check all the possible combinations
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

