PROGRAM EQ
    REAL :: A,B,C,DELTA,RESULTADO1, RESULTADO2, valorB,VETOR(3) 
    INTEGER :: I=1
    CHARACTER(LEN=32) :: ARG

    DO WHILE (I<4)
        CALL GETARG(I,ARG)
        READ(ARG,*)VETOR(I)
        i=i+1
    END DO

    A=VETOR(1)
    B=VETOR(2)
    C=VETOR(3)

    DELTA= B*B -4*A*C

    IF (DELTA>0) THEN
        RESULTADO1 = (-B + SQRT(DELTA))/2*a
        RESULTADO2 = (-B - SQRT(DELTA))/2*a
        print*,"R1=",RESULTADO1
        print*,"R2=",RESULTADO2
    END IF

    IF(DELTA<0) THEN
        valorB=-B/2*A
        RESULTADO1 = SQRT(delta*(-1))/2*A 
        print "('R1 = ',F0.5,' + ',F0.5,'i')",valorB,RESULTADO1
        print*,"R2=",valorB,"-",RESULTADO1,"i"
    END IF

    IF(DELTA==0) THEN
    RESULTADO1 = (-B + SQRT(DELTA))/2*a
    print*,"R1=",RESULTADO1
    print*,"R2=",RESULTADO1
    END IF
END PROGRAM