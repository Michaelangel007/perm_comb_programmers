/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers
*/

#include <stdio.h>
#include <alloca.h>
#include <string.h>

// Permutation
#include "util.h"
#include "perm_norep_fastswap.h"

// Demo
    /*
        Map unique id to permutation with fast swap

            Dec  Bin  Elem
            #0   00   A
            #1   01   B
            #2   10   C
            #3   11   D

        Ouput:
            Id# set
            # 0 ADC
            # 1 BAC
            # 2 CAD
            # 3 DAC
            # 4 ABD
            # 5 BDA
            # 6 CBA
            # 7 DBA
            # 8 ACD
            # 9 BCA
            #10 CDA
            #11 DCA
            #12 ADB
            #13 BAD
            #14 CAB
            #15 DAB
            #16 ABC
            #17 BDC
            #18 CBD
            #19 DBC
            #20 ACB
            #21 BCD
            #22 CDB
            #23 DCB
    */
    void demo_perm_fastswap()
    {
        char *output;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";

        printf( "= Permtuation (Fast Swap) =\n" );
        printf( "Id# set\n" );

        for( int i = 0; i < 24; i++ )
        {
            output = itoa_perm_norep_fastswap( i, base, digits, set );
            printf( "#%2d %s\n", i, output );
        }

        printf( "\n" );
    }

int main()
{
    demo_perm_fastswap();

    return 0;
}
