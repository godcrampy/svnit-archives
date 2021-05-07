      MACRO
      ADDTEN &X, &Y
      MOVER AREG, X
      MOVER BREG, Y
      LCL &M
&M    SET 0
      ADDNUM AREG, BREG
      INCR AREG
      INCR BREG
&M    SET &M + 1
      AIF ( &M NE 10 ) .MORE
      MEND
