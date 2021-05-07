package lab_1.q_01;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        System.out.print("Enter radius: ");
        double r = sc.nextDouble();
        System.out.print("Enter height: ");
        double h = sc.nextDouble();
        double v = Math.PI * r * r * h / 3;
        System.out.printf("Volume: %.2f", v);
    }
}
