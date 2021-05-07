package lab_1.q_09;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        int a, b, c;
        System.out.printf("Enter 3 numbers: ");
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        if (a <= b && b <= c) {
            System.out.println("Increasing");
        } else if (a >= b && b >= c) {
            System.out.println("Decreasing");
        } else {
            System.out.println("Neither Increasing or Decreasing");
        }
    }
}
