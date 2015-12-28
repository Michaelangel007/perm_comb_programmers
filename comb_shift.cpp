/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers
*/

#include <stdio.h>
#include <alloca.h>
#include <string.h>

// Combinations

    char* itoa_comb_shift( unsigned int n, int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        static char set[ 16 ]; // variable length array: set[ base ]
        memcpy( set, SET, base ); // Optimization: strlen( SET )= base

        int   r; // remainder
        char *dst = output;

        do
        {
            r = n % base;
            n = n / base;
            *dst++ = set[ r ];

            --base;
            memcpy( set + r, set + r + 1, base - r ); // Remove set[r] element
        } while (--length > 0);

        *dst = 0;
        return output;
    }

// Demo
    /*
        Map unique id to combination with natural

            Dec  Bin  Elem
            #0   00   A
            #1   01   B
            #2   10   C
            #3   11   D

        Ouput:
            Id# shift
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
    void demo_comb_shift()
    {
        char *output;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";

        printf( "= Combinations (Shift) =\n" );
        printf( "Id# shift\n" );

        for( int i = 0; i < 24; i++ )
        {
            output = itoa_comb_shift( i, base, digits, set );
            printf( "#%2d %s\n", i, output );
        }

        printf( "\n" );
    }

int main()
{
    demo_comb_shift();

    return 0;
}

