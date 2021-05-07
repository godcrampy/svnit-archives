package lab_1.q_05;

import java.util.Scanner;

public class Main {
    static double value(double p, double t, double r) {
        return p * Math.pow((1 + r) , t);
    }
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        System.out.printf("Enter Years: ");
        double t = sc.nextDouble();
        System.out.printf("Enter Principle: ");
        double p = sc.nextDouble();
        System.out.printf("Enter Rate: ");
        double r = sc.nextDouble();

        double v = value(p, t, r);
        System.out.printf("Value: %.2f", v);
    }
}
