init {
	run A();
	printf("this is process: %d\n", _pid);
}

proctype A() {
	printf("this is process: %d\n", _pid);
}
