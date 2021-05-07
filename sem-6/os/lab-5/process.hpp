#if !defined(PROCESS_BLOC)
#define PROCESS_BLOC

typedef struct Process {
  Process(int pid, int cpu_time, int arrival_time);
  bool operator<(const Process &rhs) const;
  int pid;
  int cpu_time;
  int arrival_time;
} Process;

void print_process(const Process &p);

#endif // PROCESS_BLOC
