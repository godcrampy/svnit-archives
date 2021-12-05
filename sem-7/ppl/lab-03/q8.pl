polarity(X):- (
X > 0
-> write('Positive'), nl
; (X == 0) -> write('Zero'), nl
; write('Negative'), nl
).
