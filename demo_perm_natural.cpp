/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers
*/

#include <stdio.h>
#include <alloca.h>
#include <string.h>

// Combinations
#include "util.h"
#include "perm_norep_natural.h"

// Demo
    /*
        Map unique id to permutation with natural

            Dec  Bin  Elem
            #0   00   A
            #1   01   B
            #2   10   C
            #3   11   D

        Ouput:
            Id# natural
            # 0 ABC
            # 1 ABD
            # 2 ACB
            # 3 ACD
            # 4 ADB
            # 5 ADC

            # 6 BAC
            # 7 BAD
            # 8 BCA
            # 9 BCD
            #10 BDA
            #11 BDC

            #12 CAB
            #13 CAD
            #14 CBA
            #15 CBD
            #16 CDA
            #17 CDB

            #18 DAB
            #19 DAC
            #20 DBA
            #21 DBC
            #22 DCA
            #23 DCB
    */
    void demo_perm_natural()
    {
        char *output;
        int   base   = 4;
        int   digits = 3;
        char  set[]  = "ABCD";

        printf( "= Permtuation (natural) =\n" );
        printf( "P#  natural\n" );

        for( int i = 0; i < 24; i++ )
        {
            output = itoa_perm_norep_natural( i, base, digits, set );
            printf( "#%2d %s\n", i, output );
        }

        printf( "\n" );
    }

int main()
{
    demo_perm_natural();

    return 0;
}

