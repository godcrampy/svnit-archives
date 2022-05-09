struct inputs{
    float num1;
    float num2;
    char operator;
};

program CALCULATE_PROG{
    version CALCULATE_VER{
        float ADD(inputs)=1;
        float SUB(inputs)=2;
        float MUL(inputs)=3;
        float DIV(inputs)=4;
    }=1;
}=0x2fffffff;
