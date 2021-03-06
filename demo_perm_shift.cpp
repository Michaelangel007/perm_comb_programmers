/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers
*/

#include <stdio.h>
#include <alloca.h>
#include <string.h>

// Permutation
#include "util.h"
#include "perm_norep_shift.h"

// Demo
    /*
        Map unique id to permutation with 'shift'

            Dec  Bin  Elem
            #0   00   A
            #1   01   B
            #2   10   C
            #3   11   D

        Ouput:
            P#  set
            # 0 ABC
            # 1 BAC
            # 2 CAB
            # 3 DAB
            # 4 ACB
            # 5 BCA
            # 6 CBA
            # 7 DBA
            # 8 ADB
            # 9 BDA
            #10 CDA
            #11 DCA
            #12 ABD
            #13 BAD
            #14 CAD
            #15 DAC
            #16 ACD
            #17 BCD
            #18 CBD
            #19 DBC
            #20 ADC
            #21 BDC
            #22 CDB
            #23 DCB
    */
    void demo_perm_shift()
    {
        char *output;
        int   base   = 4;
        int   digits = 3;
        char  set[]  = "ABCD";

        printf( "= Permutation (shift) =\n" );
        printf( "P#  set\n" );

        for( int i = 0; i < 24; i++ )
        {
            output = itoa_perm_norep_shift( i, base, digits, set );
            printf( "#%2d %s\n", i, output );
        }

        printf( "\n" );
    }

int main()
{
    demo_perm_shift();

    return 0;
}

