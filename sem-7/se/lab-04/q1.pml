init {
  run A();
  printf("PID of initial process: %d\n", _pid);
}

proctype A() {
  printf("PID of child process: %d\n", _pid);
}
