/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers
*/

#include <stdio.h>
#include <alloca.h>
#include <string.h>

// Combinations

    char* itoa_comb_fast( unsigned int n, int base, int length, const char MASTER_SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ]; // base=2 output in binary is 32 digits

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        static char set[ 16 ]; // variable length array: set[ base ]
        memcpy( set, MASTER_SET, base ); // Optimization: strlen( MASTER_SET ) == base

        int   r; // remainder
        char *dst = output;

        do
        {
            r = n % base;
            n = n / base;
            *dst++ = set[ r      ];
            set[r] = set[ --base ]; 
            // Optimization: instead of shifting workset over by one character
            // We move the last element into the slot that was just used
        } while (--length > 0);

        *dst = 0;
        return output;
    }

// Demo
    /*
        Map unique id to combination with fast swap

            Dec  Bin  Elem
            #0   00   A
            #1   01   B
            #2   10   C
            #3   11   D

        Ouput:
            Id# set[r]
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
    void demo_comb_fastswap()
    {
        char *output;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";

        printf( "= Combinations (Fast Swap) =\n" );
        printf( "Id# set[r]\n" );

        for( int i = 0; i < 24; i++ )
        {
            output = itoa_comb_fast( i, base, digits, set );
            printf( "#%2d %s\n", i, output );
        }

        printf( "\n" );
    }

int main()
{
    demo_comb_fastswap();

    return 0;
}
