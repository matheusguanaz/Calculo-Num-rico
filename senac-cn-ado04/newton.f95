PROGRAM NEWTON
	REAL :: J, P0,P=100000000, B, A
	CHARACTER(LEN =32) :: ARG
	
	CALL GETARG(1, ARG)
	READ(arg,*)J
	
	A=sqrt(j) -1
	B=sqrt(j) +1
	P0= (A+B)/2
	DO WHILE (P-P0 > 0.001)	
		P= P0 - (((P0*P0)-j)/2*P0)
		P0=P
		!WRITE(*,*)P
	END DO
	
	WRITE(*,*)P

END PROGRAM
