package lab_1.q_06;

public class Result extends Test {
    private int totalMarks;

    public Result(int rollNumber, int dbms, int dsa) {
        super(rollNumber, dbms, dsa);
        this.totalMarks = dbms + dsa;
    }

    public int getTotalMarks() {
        return totalMarks;
    }

    public void printResult() {
        System.out.printf("Roll Number: %d\n", getRollNumber());
        printDBMS();
        printDSA();
        System.out.printf("Total: %d\n", totalMarks);
    }
}
