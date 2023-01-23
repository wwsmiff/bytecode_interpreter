# A simple test program to test the operations
# and getting values from registers

MOV R1, 20; # Moving 20 into R1
MOV R2, 50; # Moving 50 into R2
ADD R1, $R2; # Adding the value held by R2 to R1
RPRINT R1;

# Same thing but for floats
FMOV FPR1, 5.0;
FMOV FPR2, 2.0;
FADD FPR1, $FPR2;
FPRINT FPR1;
