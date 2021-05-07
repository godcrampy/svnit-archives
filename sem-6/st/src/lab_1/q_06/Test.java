package lab_1.q_06;

public class Test extends Student {
    private int dbms;
    private int dsa;

    public int getDbms() {
        return dbms;
    }

    public int getDsa() {
        return dsa;
    }

    public Test(int rollNumber, int dbms, int dsa) {
        super(rollNumber);
        this.dbms = dbms;
        this.dsa = dsa;
    }

    public void printDBMS() {
        System.out.printf("DBMS: %d\n", dbms);
    }

    public void printDSA() {
        System.out.printf("DSA: %d\n", dsa);
    }


}
