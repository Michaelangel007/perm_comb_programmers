/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers

Alt. Title: The secret to understanding Permutations and Combinations for Programmers
3rd. Title: Programmer's Guide to Combinations and Permutations
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Utility

    // Usage: const int fact = factorial( n );
    int factorial( int n )
    {
        int product = 1;
        while( n > 1 )
           product *= n--;
        return product;
    }

    /** Search for key in vals
     * @param size     The size of the array to search
     * @param haystack The array (vals) to search
     * @param needle   They key to find
     */
    int find( const size_t size, const char *haystack, const char needle )
    {
        const char *src = haystack;
        const char *end = haystack + size;

        while( src < end )
        {
            if( *src == needle )
                return (src - haystack);
            src++;
        }
        return -1; // not found
    }

// Permutations
    char* itoa_perm( uint32_t n, int base, int length, const char set[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        int r;
        char *dst = output + MAX_DIGITS;
        *dst-- = 0;

        do
        {
            r = n % base;
            n = n / base;
            *dst-- = set[ r ];
        } while (--length > 0);

        return dst+1;
    }

    int atoi_perm( const char *input, const int base, const char set[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r;

        for(int length = 0; length < digits; length++ )
        {
            r = find( base, set, *text++ );

            if( r < 0 )
                return n;

            n *= base;
            n += r;
        }

        return n;
    }

// Combinations
    /*
            // Remove 'r'th element
            // http://stackoverflow.com/questions/3751797/can-i-call-memcpy-and-memmove-with-number-of-bytes-set-to-zero
            // C99 standard (7.21.1/2):
            //    Where an argument declared as size_t n specifies the length of the array for a function, n can have the value zero on a call to that function. Unless explicitly stated otherwise in the description of a particular function in this subclause, pointer arguments on such a call shall still have valid values, as described in 7.1.4. On such a call, a function that locates a character finds no occurrence, a function that compares two character sequences returns zero, and a function that copies characters copies zero characters.
            //int digits = base - r;
            //if( digits > 0 )
            base--; // Combination = decreasing base
            memcpy( set + r, set + r + 1, base - r ); // Remove set[r] element
    */
    char* itoa_comb( uint32_t n, int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int  MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        static char set[ MAX_DIGITS ];
        memcpy( set, SET, base ); // Optimization: strlen( SET )= base

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        int r;
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

    int atoi_comb( const char *input, const int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r;
        /* */ int   b      = 1, base = BASE; // default to base

        static char set[] = "0123456789ABCDEF";
        memcpy( set, SET, base );

        for(int length = 0; length < digits; length++ )
        {
            r = find( base, set, *text++ );
            if( r < 0 )
                return n;

            n += (r * b);
            b *= base;
            --base;
            memcpy( set + r, set + r + 1, base - r ); // Remove set[r] element
        }

        return n;
    }



    char* itoa_comb_fast( uint32_t n, int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int  MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        static char set[ MAX_DIGITS ];
        memcpy( set, SET, base ); // Optimization: strlen( SET )= base

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        int r;
        char *dst = output;

        do
        {
            r = n % base;
            n = n / base;
            *dst++ = set[ r ];
            set[r] = set[ --base ];
        } while (--length > 0);

        *dst = 0;
        return output;
    }

    int atoi_comb_fast( const char *input, int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n = 0, r, b = 1, base = BASE; // default to base

        static char set[] = "0123456789ABCDEF";
        memcpy( set, SET, base );

        for(int length = 0; length < digits; length++ )
        {
            r = find( base, set, *text++ );
            if( r < 0 )
                return n;

            n += (r * b);
            b *= base;
            set[ r ] = set[ --base ];
        }

        return n;
    }

    /* C(n,r) =

       ( n ) = n!
       (   )   ---
       ( r )   r!(n-r!)
    */

    char* itoa_comb_natural( uint32_t n, int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int  MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        static char set[ MAX_DIGITS ];
        memcpy( set, SET, base ); // Optimization: strlen( SET )= base

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        int   r;
        char *dst  = output;
        int   fact = factorial( base - 1 );

        do
        {
            r = n / factorial( base - 1 );
            n -= r;
            n /= base;

            fact /= base;
            *dst++ = set[ r ];
            --base;
            memcpy( set + r, set + r + 1, base - r ); // Remove set[r] element
        } while (--length > 0);

        *dst = 0;
        return output;
    }

// Demo
    // Print Permutations & Combinations
    void permutations()
    {
        char *expect, *actual;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";

        printf( "= Permutations =\n" );
       
        for( int i = 0; i < 64; i++ )
        {
            expect = itoa_perm( i, base, digits, set );
            printf( "#%2d: %s", i, expect );

            int n  = atoi_perm( expect, base, set );
            actual = itoa_perm( n, base, digits, set );

            printf( " -> %2d -> %s\n", n, actual );
        }

        printf( "\n" );
    }

    /* Mapping unique id to combination

      Dec  Bin  Elem
       #0   00   A
       #1   01   B
       #2   10   C
       #3   11   D

    Id   memcpy()   set[r] Different   Natural
    # 0: ABC        ADC    *20         ABC 0 0 0
    # 1: BAC        BAC                ABD 0 0 1
    # 2: CAB        CAD    *14         ACB 0 1 0
    # 3: DAB        DAC    *15         ACD 0 1 2
    # 4: ACB        ABD    *12         ADB 0 2 0
    # 5: BCA        BDA    *9          ADC 0 2 1
    # 6: CBA        CBA                BAC 1 0 0
    # 7: DBA        DBA                BAD 1 0 1
    # 8: ADB        ACD    *16         BCA 1 
    # 9: BDA        BCA    *5          BCD 1
    #10: CDA        CDA                BDA 1
    #11: DCA        DCA                BDC 1
    #12: ABD        ADB    *8          CAB 2
    #13: BAD        BAD                CAD 2
    #14: CAD        CAB    *2          CBA 2
    #15: DAC        DAB    *3          CBD 2
    #16: ACD        ABC    *0          CDA 2
    #17: BCD        BDC    *21         CDB 2
    #18: CBD        CBD                DAB 3
    #19: DBC        DBC                DAC 3
    #20: ADC        ACB    *4          DBA 3
    #21: BDC        BCD    *17         DBC 3
    #22: CDB        CDB                DCA 3
    #23: DCB        DCB                DCB 3 2 1
    */
    void combinations()
    {
        char *expect, *actual;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";

        printf( "= Combinations =\n" );
        printf( "Id   memcpy()   set[r] Different   Natural\n" );

        for( int i = 0; i < 24; i++ )
        {
            expect = itoa_comb( i, base, digits, set );
            printf( "#%2d: %s", i, expect );

            int n  = atoi_comb( expect, base, set );
            actual = itoa_comb( n, base, digits, set );

            printf( " -> %2d -> %s", n, actual );

            expect = itoa_comb_fast( i, base, digits, set );
            printf( "   FAST #%2d: %s", i, expect );
                n  = atoi_comb_fast( expect, base, set );
            actual = itoa_comb_fast( n, base, digits, set );
            printf( " -> %2d -> %s", n, actual );

            expect = itoa_comb_natural( i, base, digits, set );
            printf( "   NATURAL #%2d: %s", i, expect );
            printf( "\n" );
        }

        printf( "\n" );
    }

int main()
{
    permutations();
    combinations();

    return 0;
}
