PROGRAM SECANTE
	REAL :: J, P0, P1, TEMP, PN=1000, FP0, FP1,x=0, res1
	CHARACTER(LEN=32) :: ARG
	CALL GETARG(1,ARG)
	READ(ARG,*)J
	
	P0=SQRT(J)-0.001
	P1=SQRT(J)+0.001
	FP0= (P0**2) - J
	FP1= (P1**2) -J
	res1= FP1 - FP0
	
	DO WHILE ( (PN -P1) > 0.001)	
		PN= P1 - FP1*(P1-P0)/RES1
		WRITE(*,*)PN
		P0=P1
		P1=PN
	END DO 
	
	


END PROGRAM
