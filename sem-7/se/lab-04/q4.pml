int SIZE = 5;
int FULL = 0;
int S = 1;
int IN = 0;
int OUT = 0;
byte BUFFER[SIZE];

init {
  printf("Hello");
  BUFFER[0] = ' ';
  BUFFER[1] = ' ';
  BUFFER[2] = ' ';
  BUFFER[3] = ' ';
  BUFFER[4] = ' ';
  run producer();
  run consumer();
  run consumer();
}

proctype consumer() {
  do
  :: printf("Consumer start\n");
  (FULL > 0) -> FULL = FULL - 1;
  (S == 1) -> S = 0;
  BUFFER[OUT] = ' ';
  OUT = OUT + 1;
  OUT = OUT % SIZE;
  S = 1;
  printf("Buffer: [%c, %c, %c, %c, %c]\n", BUFFER[0], BUFFER[1], BUFFER[2], BUFFER[3], BUFFER[4])
  od
}


proctype producer() {
  do
  :: printf("Producer start\n");
  (FULL < SIZE) -> FULL = FULL + 1;
  (S == 1) -> S = 0;
  BUFFER[IN] = '1';
  IN = IN + 1;
  IN = IN % SIZE;
  S = 1;
  printf("Buffer: [%c, %c, %c, %c, %c]\n", BUFFER[0], BUFFER[1], BUFFER[2], BUFFER[3], BUFFER[4])
  od
}
