package lab_1.q_04;

import java.util.Scanner;

public class Solver {
    int vowelCount(String s) {
        s = s.toLowerCase();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++count;
            }
        }

        return count;
    }

    public void run() {
        var sc = new Scanner(System.in);
        String s = "";

        while (!(s = sc.nextLine()).equals("quit")) {
            System.out.printf("Vowels: %d\n", vowelCount(s));
        }
    }
}
