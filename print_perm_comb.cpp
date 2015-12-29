/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers

Alt. Title: The secret to understanding Permutations and Combinations for Programmers
3rd. Title: Programmer's Guide to Combinations and Permutations
4th. Title: What every programmer should know about permutations and combinations
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Utility
    #include "util.h"

/*
    | Ordered? | Repetition? | Type                                   |
    | no       | no          | Combination = n! / ((n-r)! * r!)       |
    | no       | yes         | Combination = (n+r-1)! / ((n-1)! * r!) |
    | yes      | no          | Permutation = n! / (n-r)!              |
    | yes      | yes         | Permutation = n^r                      |

    Without repetitions:

             ( n )     n!
    P(n,r) = (   ) = ------
             ( r )   (n-r)!

             ( n )      n!
    C(n,r) = (   ) = --------
             ( r )   r!(n-r!)
*/

// Permutations

    #include "perm_rep.h"
    #include "perm_norep_shift.h"
    #include "perm_norep_fastswap.h"
    #include "perm_norep_almost.h"
    #include "perm_norep_natural.h"

/*
*/
    void permutations_rep()
    {
        char *expect, *actual;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";

        printf( "= Permutations (with repetitions) =\n" );
       
        for( int i = 0; i < 64; i++ )
        {
            expect = itoa_perm_rep( i, base, digits, set );
            printf( "#%2d: %s", i, expect );

            int n  = atoi_perm_rep( expect, base, set );
            actual = itoa_perm_rep( n, base, digits, set );

            printf( " -> %2d -> %s\n", n, actual );
        }

        printf( "\n" );
    }

/*
    Mapping unique id to permutation (without repetition)

        Dec  Bin  Element
        #0   00   A
        #1   01   B
        #2   10   C
        #3   11   D

    # 0   ABC        ADC    *20         ABC 0 0 0
    # 1   BAC        BAC                ABD 0 0 1
    # 2   CAB        CAD    *14         ACB 0 1 0
    # 3   DAB        DAC    *15         ACD 0 1 2
    # 4   ACB        ABD    *12         ADB 0 2 0
    # 5   BCA        BDA    *9          ADC 0 2 1
    # 6   CBA        CBA                BAC 1 0 0
    # 7   DBA        DBA                BAD 1 0 1
    # 8   ADB        ACD    *16         BCA 1 
    # 9   BDA        BCA    *5          BCD 1
    #10   CDA        CDA                BDA 1
    #11   DCA        DCA                BDC 1
    #12   ABD        ADB    *8          CAB 2
    #13   BAD        BAD                CAD 2
    #14   CAD        CAB    *2          CBA 2
    #15   DAC        DAB    *3          CBD 2
    #16   ACD        ABC    *0          CDA 2
    #17   BCD        BDC    *21         CDB 2
    #18   CBD        CBD                DAB 3
    #19   DBC        DBC                DAC 3
    #20   ADC        ACB    *4          DBA 3
    #21   BDC        BCD    *17         DBC 3
    #22   CDB        CDB                DCA 3
    #23   DCB        DCB                DCB 3 2 1
*/
    
    void permutations_norep()
    {
        char *expect, *actual;
        int  base   = 4;
        int  digits = 3;
        char set[]  = "ABCD";
        int  n;

        printf( "= Permutations (without repetition) =\n" );
        printf( "P#    shift: memcpy()    fast: set[r]       Almost             Natural\n" );

        for( int i = 0; i < 24; i++ )
//int i = 19;
        {
            printf( "#%2d", i );

            expect = itoa_comb_shift( i, base, digits, set );
            printf( "   %s", expect );
                n  = atoi_comb_shift( expect, base, set );
            actual = itoa_comb_shift( n, base, digits, set );
            printf( " -> %2d -> %s", n, actual );

            expect = itoa_comb_fastswap( i, base, digits, set );
            printf( "   %s", expect );
                n  = atoi_comb_fastswap( expect, base, set );
            actual = itoa_comb_fastswap( n, base, digits, set );
            printf( " -> %2d -> %s", n, actual );

            expect = itoa_comb_almost( i, base, digits, set );
            printf( "   %s", expect );
                n  = atoi_comb_almost( expect, base, set );
            actual = itoa_comb_almost( n, base, digits, set );
            printf( " -> %2d -> %s", n, actual );

            expect = itoa_comb_natural( i, base, digits, set );
            printf( "   %s", expect );

            printf( "\n" );
        }

        printf( "\n" );
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

    void combinations_rep()
    {
        printf( "= Combinations (with repetitions) =\n" );
    }

    void combinations_norep()
    {
        printf( "= Combinations (without repetition) =\n" );
    }

int main()
{
    permutations_rep();
    permutations_norep();
    combinations_rep();
    combinations_norep();

    return 0;
}

