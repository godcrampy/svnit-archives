struct intpair {
    int a;
};

program FACT_PROG {
    version FACT_VERS {
        int FACT(intpair) = 1;
    } = 1;
} = 0x23451111;
