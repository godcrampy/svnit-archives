package lab_1.q_08;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        String s = sc.nextLine();

        if (s.length() != 1) {
            System.out.println("Error");
            return;
        }

        char c = s.charAt(0);

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                System.out.println("Vowel");
            } else {
                System.out.println("Constant");
            }
        } else {
            System.out.println("Error");
        }
    }
}
