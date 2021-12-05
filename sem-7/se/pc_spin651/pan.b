	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC philosopher */
;
		;
		
	case 4: // STATE 2
		;
		((P1 *)_this)->low = trpt->bup.oval;
		;
		goto R999;

	case 5: // STATE 3
		;
		((P1 *)_this)->high = trpt->bup.oval;
		;
		goto R999;

	case 6: // STATE 5
		;
		((P1 *)_this)->low = trpt->bup.oval;
		;
		goto R999;

	case 7: // STATE 6
		;
		((P1 *)_this)->high = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 10: // STATE 11
		;
		now.FORKS[ Index(((P1 *)_this)->low, 4) ] = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 13: // STATE 14
		;
		now.FORKS[ Index(((P1 *)_this)->high, 4) ] = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 16: // STATE 17
		;
		now.FORKS[ Index(((P1 *)_this)->low, 4) ] = trpt->bup.oval;
		;
		goto R999;

	case 17: // STATE 18
		;
		now.FORKS[ Index(((P1 *)_this)->high, 4) ] = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 20: // STATE 24
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC :init: */

	case 21: // STATE 1
		;
		now.FORKS[0] = trpt->bup.oval;
		;
		goto R999;

	case 22: // STATE 2
		;
		now.FORKS[1] = trpt->bup.oval;
		;
		goto R999;

	case 23: // STATE 3
		;
		now.FORKS[2] = trpt->bup.oval;
		;
		goto R999;

	case 24: // STATE 4
		;
		now.FORKS[3] = trpt->bup.oval;
		;
		goto R999;

	case 25: // STATE 5
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 26: // STATE 6
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 27: // STATE 7
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 28: // STATE 8
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 29: // STATE 9
		;
		p_restor(II);
		;
		;
		goto R999;
	}

