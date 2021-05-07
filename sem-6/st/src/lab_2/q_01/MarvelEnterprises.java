package lab_2.q_01;

public class MarvelEnterprises {

    public void calculatePay(String employeeName, int basePay, int hoursWorked) {
        final int minimumPay = 400;
        if (hoursWorked > 60) {
            System.out.printf("Error: More than 60 hours work for %s\n", employeeName);
            return;
        }

        if (basePay < minimumPay) {
            System.out.printf("Error: Base Pay less than Minimum Wage for %s\n", employeeName);
            return;
        }
        int normalHours = Math.min(40, hoursWorked);
        int extraHours = Math.max(0, hoursWorked - 40);

        double totalPay = (normalHours + extraHours * 1.5) * basePay;
        System.out.printf("Total Pay for %s: %.2f\n", employeeName, totalPay);
    }
}
