/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers
*/

#include <stdio.h>
#include <alloca.h>
#include <string.h>

// Permutation
#include "util.h"
#include "perm_norep_almost.h"

// Demo
    /*
        Map unique id to permutation with 'almost'

            Dec  Bin  Elem
            #0   00   A
            #1   01   B
            #2   10   C
            #3   11   D

        Ouput:
            P#  set
            # 0 ABC
            # 1 ACD
            # 2 ADB
            # 3 ABD
            # 4 ACB
            # 5 ADC
            # 6 BCD
            # 7 BDA
            # 8 BAC
            # 9 BCA
            #10 BDC
            #11 BAD
            #12 CDA
            #13 CAB
            #14 CBD
            #15 CDB
            #16 CAD
            #17 CBA
            #18 DAB
            #19 DBC
            #20 DCA
            #21 DAC
            #22 DBA
            #23 DCB
    */
    void demo_perm_almost()
    {
        char *output;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";

        printf( "= Permutation (almost) =\n" );
        printf( "P#  set\n" );

        for( int i = 0; i < 24; i++ )
        {
            output = itoa_perm_norep_almost( i, base, digits, set );
            printf( "#%2d %s\n", i, output );
        }

        printf( "\n" );
    }

int main()
{
    demo_perm_almost();

    return 0;
}

