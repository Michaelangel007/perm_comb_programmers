/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers
*/

#include <stdio.h>
#include <alloca.h>
#include <string.h>

// Combinations

    char* itoa_comb_natural( unsigned int n, int base, int length, const char SET[] = "0123456789ABCDEF" )
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
// TODO: FIXME:
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
    void demo_comb_natural()
    {
        char *output;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";

        printf( "= Combinations (Shift) =\n" );
        printf( "Id# memcpy()\n" );

        for( int i = 0; i < 24; i++ )
        {
            output = itoa_comb_natural( i, base, digits, set );
            printf( "#%2d %s\n", i, output );
        }

        printf( "\n" );
    }

int main()
{
    demo_comb_natural();

    return 0;
}

