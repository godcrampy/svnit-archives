#define rand	pan_rand
#define pthread_equal(a,b)	((a)==(b))
#if defined(HAS_CODE) && defined(VERBOSE)
	#ifdef BFS_PAR
		bfs_printf("Pr: %d Tr: %d\n", II, t->forw);
	#else
		cpu_printf("Pr: %d Tr: %d\n", II, t->forw);
	#endif
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* PROC philosopher */
	case 3: // STATE 1 - lab-05-q1.pml:20 - [((i==(SIZE-1)))] (0:0:0 - 0)
		IfNotBlocked
		reached[1][1] = 1;
		if (!((((P1 *)_this)->i==(now.SIZE-1))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: // STATE 2 - lab-05-q1.pml:20 - [low = ((i+1)%SIZE)] (0:0:1 - 0)
		IfNotBlocked
		reached[1][2] = 1;
		(trpt+1)->bup.oval = ((P1 *)_this)->low;
		((P1 *)_this)->low = ((((P1 *)_this)->i+1)%now.SIZE);
#ifdef VAR_RANGES
		logval("philosopher:low", ((P1 *)_this)->low);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 5: // STATE 3 - lab-05-q1.pml:20 - [high = i] (0:0:1 - 0)
		IfNotBlocked
		reached[1][3] = 1;
		(trpt+1)->bup.oval = ((P1 *)_this)->high;
		((P1 *)_this)->high = ((P1 *)_this)->i;
#ifdef VAR_RANGES
		logval("philosopher:high", ((P1 *)_this)->high);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 6: // STATE 5 - lab-05-q1.pml:21 - [low = i] (0:0:1 - 0)
		IfNotBlocked
		reached[1][5] = 1;
		(trpt+1)->bup.oval = ((P1 *)_this)->low;
		((P1 *)_this)->low = ((P1 *)_this)->i;
#ifdef VAR_RANGES
		logval("philosopher:low", ((P1 *)_this)->low);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 7: // STATE 6 - lab-05-q1.pml:21 - [high = ((i+1)%SIZE)] (0:0:1 - 0)
		IfNotBlocked
		reached[1][6] = 1;
		(trpt+1)->bup.oval = ((P1 *)_this)->high;
		((P1 *)_this)->high = ((((P1 *)_this)->i+1)%now.SIZE);
#ifdef VAR_RANGES
		logval("philosopher:high", ((P1 *)_this)->high);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 8: // STATE 9 - lab-05-q1.pml:25 - [printf('Philosopher %d is thinking...\\n',(i+1))] (0:0:0 - 0)
		IfNotBlocked
		reached[1][9] = 1;
		Printf("Philosopher %d is thinking...\n", (((P1 *)_this)->i+1));
		_m = 3; goto P999; /* 0 */
	case 9: // STATE 10 - lab-05-q1.pml:26 - [((FORKS[low]==0))] (0:0:0 - 0)
		IfNotBlocked
		reached[1][10] = 1;
		if (!((now.FORKS[ Index(((P1 *)_this)->low, 4) ]==0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 10: // STATE 11 - lab-05-q1.pml:26 - [FORKS[low] = 1] (0:0:1 - 0)
		IfNotBlocked
		reached[1][11] = 1;
		(trpt+1)->bup.oval = now.FORKS[ Index(((P1 *)_this)->low, 4) ];
		now.FORKS[ Index(((P1 *)_this)->low, 4) ] = 1;
#ifdef VAR_RANGES
		logval("FORKS[philosopher:low]", now.FORKS[ Index(((P1 *)_this)->low, 4) ]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 11: // STATE 12 - lab-05-q1.pml:26 - [printf('Philosopher %d has picked fork %d...\\n',(i+1),(low+1))] (0:0:0 - 0)
		IfNotBlocked
		reached[1][12] = 1;
		Printf("Philosopher %d has picked fork %d...\n", (((P1 *)_this)->i+1), (((P1 *)_this)->low+1));
		_m = 3; goto P999; /* 0 */
	case 12: // STATE 13 - lab-05-q1.pml:27 - [((FORKS[high]==0))] (0:0:0 - 0)
		IfNotBlocked
		reached[1][13] = 1;
		if (!((now.FORKS[ Index(((P1 *)_this)->high, 4) ]==0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 13: // STATE 14 - lab-05-q1.pml:27 - [FORKS[high] = 1] (0:0:1 - 0)
		IfNotBlocked
		reached[1][14] = 1;
		(trpt+1)->bup.oval = now.FORKS[ Index(((P1 *)_this)->high, 4) ];
		now.FORKS[ Index(((P1 *)_this)->high, 4) ] = 1;
#ifdef VAR_RANGES
		logval("FORKS[philosopher:high]", now.FORKS[ Index(((P1 *)_this)->high, 4) ]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 14: // STATE 15 - lab-05-q1.pml:27 - [printf('Philosopher %d has picked fork %d...\\n',(i+1),(high+1))] (0:0:0 - 0)
		IfNotBlocked
		reached[1][15] = 1;
		Printf("Philosopher %d has picked fork %d...\n", (((P1 *)_this)->i+1), (((P1 *)_this)->high+1));
		_m = 3; goto P999; /* 0 */
	case 15: // STATE 16 - lab-05-q1.pml:28 - [printf('Philosopher %d is eating...\\n',(i+1))] (0:0:0 - 0)
		IfNotBlocked
		reached[1][16] = 1;
		Printf("Philosopher %d is eating...\n", (((P1 *)_this)->i+1));
		_m = 3; goto P999; /* 0 */
	case 16: // STATE 17 - lab-05-q1.pml:29 - [FORKS[low] = 0] (0:0:1 - 0)
		IfNotBlocked
		reached[1][17] = 1;
		(trpt+1)->bup.oval = now.FORKS[ Index(((P1 *)_this)->low, 4) ];
		now.FORKS[ Index(((P1 *)_this)->low, 4) ] = 0;
#ifdef VAR_RANGES
		logval("FORKS[philosopher:low]", now.FORKS[ Index(((P1 *)_this)->low, 4) ]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 17: // STATE 18 - lab-05-q1.pml:30 - [FORKS[high] = 0] (0:0:1 - 0)
		IfNotBlocked
		reached[1][18] = 1;
		(trpt+1)->bup.oval = now.FORKS[ Index(((P1 *)_this)->high, 4) ];
		now.FORKS[ Index(((P1 *)_this)->high, 4) ] = 0;
#ifdef VAR_RANGES
		logval("FORKS[philosopher:high]", now.FORKS[ Index(((P1 *)_this)->high, 4) ]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 18: // STATE 19 - lab-05-q1.pml:31 - [printf('Philosopher %d done eating...\\n',(i+1))] (0:0:0 - 0)
		IfNotBlocked
		reached[1][19] = 1;
		Printf("Philosopher %d done eating...\n", (((P1 *)_this)->i+1));
		_m = 3; goto P999; /* 0 */
	case 19: // STATE 20 - lab-05-q1.pml:32 - [printf('Forks: [%d, %d, %d, %d]\\n',FORKS[0],FORKS[1],FORKS[2],FORKS[3])] (0:0:0 - 0)
		IfNotBlocked
		reached[1][20] = 1;
		Printf("Forks: [%d, %d, %d, %d]\n", now.FORKS[0], now.FORKS[1], now.FORKS[2], now.FORKS[3]);
		_m = 3; goto P999; /* 0 */
	case 20: // STATE 24 - lab-05-q1.pml:34 - [-end-] (0:0:0 - 0)
		IfNotBlocked
		reached[1][24] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC :init: */
	case 21: // STATE 1 - lab-05-q1.pml:5 - [FORKS[0] = 0] (0:0:1 - 0)
		IfNotBlocked
		reached[0][1] = 1;
		(trpt+1)->bup.oval = now.FORKS[0];
		now.FORKS[0] = 0;
#ifdef VAR_RANGES
		logval("FORKS[0]", now.FORKS[0]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 22: // STATE 2 - lab-05-q1.pml:6 - [FORKS[1] = 0] (0:0:1 - 0)
		IfNotBlocked
		reached[0][2] = 1;
		(trpt+1)->bup.oval = now.FORKS[1];
		now.FORKS[1] = 0;
#ifdef VAR_RANGES
		logval("FORKS[1]", now.FORKS[1]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 23: // STATE 3 - lab-05-q1.pml:7 - [FORKS[2] = 0] (0:0:1 - 0)
		IfNotBlocked
		reached[0][3] = 1;
		(trpt+1)->bup.oval = now.FORKS[2];
		now.FORKS[2] = 0;
#ifdef VAR_RANGES
		logval("FORKS[2]", now.FORKS[2]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 24: // STATE 4 - lab-05-q1.pml:8 - [FORKS[3] = 0] (0:0:1 - 0)
		IfNotBlocked
		reached[0][4] = 1;
		(trpt+1)->bup.oval = now.FORKS[3];
		now.FORKS[3] = 0;
#ifdef VAR_RANGES
		logval("FORKS[3]", now.FORKS[3]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 25: // STATE 5 - lab-05-q1.pml:9 - [(run philosopher(0))] (0:0:0 - 0)
		IfNotBlocked
		reached[0][5] = 1;
		if (!(addproc(II, 1, 1, 0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 26: // STATE 6 - lab-05-q1.pml:10 - [(run philosopher(1))] (0:0:0 - 0)
		IfNotBlocked
		reached[0][6] = 1;
		if (!(addproc(II, 1, 1, 1)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 27: // STATE 7 - lab-05-q1.pml:11 - [(run philosopher(2))] (0:0:0 - 0)
		IfNotBlocked
		reached[0][7] = 1;
		if (!(addproc(II, 1, 1, 2)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 28: // STATE 8 - lab-05-q1.pml:12 - [(run philosopher(3))] (0:0:0 - 0)
		IfNotBlocked
		reached[0][8] = 1;
		if (!(addproc(II, 1, 1, 3)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 29: // STATE 9 - lab-05-q1.pml:13 - [-end-] (0:0:0 - 0)
		IfNotBlocked
		reached[0][9] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}

