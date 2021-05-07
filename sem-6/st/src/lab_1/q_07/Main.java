package lab_1.q_07;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        System.out.printf("Enter Radii:");
        double r1 = sc.nextDouble();
        double r2 = sc.nextDouble();
        var circle = new Circle(r1);
        var circle1 = new Circle(r2);

        System.out.printf("Area: %.2f\nEqual: ", circle.getArea());
        System.out.println(circle1.equals(circle));
    }
}
