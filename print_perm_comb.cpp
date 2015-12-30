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
    #include "perm_norep_almost.h"
    #include "perm_norep_fastswap.h"
    #include "perm_norep_natural.h"
    #include "perm_norep_shift.h"

/*
*/
    void permutations_rep()
    {
        char *expect, *actual;
        int   base   = 4;
        int   digits = 3;
        char  set[]  = "ABCD";

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

NOTE: Almost is still broken

    = Permutations (without repetition) =
    P#    shift: memcpy()    fast: set[r]       Almost             Natural
    # 0   ABC ->  0 -> ABC   ADC ->  0 -> ADC   ABC ->  0 -> ABC   ABC ->  0 -> ABC
    # 1   BAC ->  1 -> BAC   BAC ->  1 -> BAC   ACD ->  3 -> ABD   ABD ->  1 -> ABD
    # 2   CAB ->  2 -> CAB   CAD ->  2 -> CAD   ADB ->  4 -> ACB   ACB ->  2 -> ACB
    # 3   DAB ->  3 -> DAB   DAC ->  3 -> DAC   ABD ->  1 -> ACD   ACD ->  3 -> ACD
    # 4   ACB ->  4 -> ACB   ABD ->  4 -> ABD   ACB ->  2 -> ADB   ADB ->  4 -> ADB
    # 5   BCA ->  5 -> BCA   BDA ->  5 -> BDA   ADC ->  5 -> ADC   ADC ->  5 -> ADC
    # 6   CBA ->  6 -> CBA   CBA ->  6 -> CBA   BCD ->  9 -> BCA   BAC ->  6 -> BAC
    # 7   DBA ->  7 -> DBA   DBA ->  7 -> DBA   BDA -> 10 -> BDC   BAD ->  7 -> BAD
    # 8   ADB ->  8 -> ADB   ACD ->  8 -> ACD   BAC ->  6 -> BCD   BCA ->  8 -> BCA
    # 9   BDA ->  9 -> BDA   BCA ->  9 -> BCA   BCA ->  8 -> BAC   BCD ->  9 -> BCD
    #10   CDA -> 10 -> CDA   CDA -> 10 -> CDA   BDC -> 11 -> BAD   BDA -> 10 -> BDA
    #11   DCA -> 11 -> DCA   DCA -> 11 -> DCA   BAD ->  7 -> BDA   BDC -> 11 -> BDC
    #12   ABD -> 12 -> ABD   ADB -> 12 -> ADB   CDA -> 16 -> CAD   CAB -> 12 -> CAB
    #13   BAD -> 13 -> BAD   BAD -> 13 -> BAD   CAB -> 12 -> CDA   CAD -> 13 -> CAD
    #14   CAD -> 14 -> CAD   CAB -> 14 -> CAB   CBD -> 15 -> CDB   CBA -> 14 -> CBA
    #15   DAC -> 15 -> DAC   DAB -> 15 -> DAB   CDB -> 17 -> CBA   CBD -> 15 -> CBD
    #16   ACD -> 16 -> ACD   ABC -> 16 -> ABC   CAD -> 13 -> CAB   CDA -> 16 -> CDA
    #17   BCD -> 17 -> BCD   BDC -> 17 -> BDC   CBA -> 14 -> CBD   CDB -> 17 -> CDB
    #18   CBD -> 18 -> CBD   CBD -> 18 -> CBD   DAB -> 18 -> DAB   DAB -> 18 -> DAB
    #19   DBC -> 19 -> DBC   DBC -> 19 -> DBC   DBC -> 21 -> DAC   DAC -> 19 -> DAC
    #20   ADC -> 20 -> ADC   ACB -> 20 -> ACB   DCA -> 22 -> DBA   DBA -> 20 -> DBA
    #21   BDC -> 21 -> BDC   BCD -> 21 -> BCD   DAC -> 19 -> DBC   DBC -> 21 -> DBC
    #22   CDB -> 22 -> CDB   CDB -> 22 -> CDB   DBA -> 20 -> DCA   DCA -> 22 -> DCA
    #23   DCB -> 23 -> DCB   DCB -> 23 -> DCB   DCB -> 23 -> DCB   DCB -> 23 -> DCB
*/
    
    void permutations_norep()
    {
        char *expect, *actual;
        int   base   = 4;
        int   digits = 3;
        char  set[]  = "ABCD";
        int   n;

        printf( "= Permutations (without repetition) =\n" );
        printf( "P#    shift: memcpy()    fast: set[r]       Almost             Natural\n" );

        for( int i = 0; i < 24; i++ )
        {
            printf( "#%2d", i );

            expect = itoa_perm_norep_shift( i, base, digits, set );
            printf( "   %s", expect );
                n  = atoi_perm_norep_shift( expect, base, set );
            actual = itoa_perm_norep_shift( n, base, digits, set );
            printf( " -> %2d -> %s", n, actual );

            expect = itoa_perm_norep_fastswap( i, base, digits, set );
            printf( "   %s", expect );
                n  = atoi_perm_norep_fastswap( expect, base, set );
            actual = itoa_perm_norep_fastswap( n, base, digits, set );
            printf( " -> %2d -> %s", n, actual );

            expect = itoa_perm_norep_almost( i, base, digits, set );
            printf( "   %s", expect );
                n  = atoi_perm_norep_almost( expect, base, set );
            actual = itoa_perm_norep_almost( n, base, digits, set );
            printf( " -> %2d -> %s", n, actual );

            expect = itoa_perm_norep_natural( i, base, digits, set );
            printf( "   %s", expect );
                n  = atoi_perm_norep_natural( expect, base, set );
            actual = itoa_perm_norep_natural( n, base, digits, set );
            printf( " -> %2d -> %s", n, actual );

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

