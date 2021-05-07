package lab_1.q_03;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        System.out.printf("Enter String: ");
        var s = sc.nextLine();
        System.out.printf("Enter Replacement Character: ");
        char c = sc.next().charAt(0);
        s = s.replace(' ', c);
        System.out.println(s);
    }
}
