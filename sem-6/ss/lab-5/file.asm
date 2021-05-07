      MACRO
      CLEARMEM &X, &N, &REG=AREG
      LCL &M
&M    SET 0
      MOVER &REG, ='0'
.MORE MOVEM &REG, &X + &M
&M    SET &M + 1
      AIF ( &M NE &N ) .MORE
      MEND