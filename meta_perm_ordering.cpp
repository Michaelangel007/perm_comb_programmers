/*
Understanding Permutations and Combinations for Programmers
https://github.com/Michaelangel007/perm_comb_programmers
*/

// Standard
    #include <stdio.h>  // printf()
    #include <stdint.h> // 
    #include <string.h> // strcpy()
    #include <stdlib.h> // malloc() free()

// Utility
    #include "util.h"

// Permutation
    #include "perm_norep_fastswap.h"
    #include "perm_norep_natural.h"
    #include "perm_norep_shift.h"

/*
    Given:

        set S = { ABC }

    Which has n = 3 elements

    There are n! = 3! = 6 possible permutations (without repetitions):

        ABC
        ACB 
        BAC
        BCA
        CAB
        CBA

    If we assign an unique id to each of the arrangements,
    how many different ways could we do this?

    For example, we could assign the permutations {ABC,ACB,...,CAB,CBA} the order:

        0,1,2,3,4,5 = { ABC, ACB, ..., CAB, CBA }
        0,1,2,3,5,4 = { ABC, ACB, ..., CBA, CAB }
             :
        5,4,3,2,1,0 = { CBA, CAB, ..., ACB, ABC }

    We could assign unique ids to the arrangements in:

        n!! = 3!! = 6! = 720 different ways.

    A few ways we could do this mapping (assigning names):

              Pn$  Ps#  Pf#
        ABC   $0   #0   #3
        ACB   $1   #3   #0
        BAC   $2   #1   #1
        BCA   $3   #4   #4
        CAB   $4   #2   #2
        CBA   $5   #5   #5
              ^    ^    ^fast swap
              |    shift
              natural

    Example of 'shift' mapping:

        Ps# shift    Pn# natural
        # 0 ABC  ==  # 0 ABC
        # 1 BAC  ==  # 2 BAC
        # 2 CAB  ==  # 4 CAB
        # 3 ACB  ==  # 1 ACB
        # 4 BCA  ==  # 3 BCA
        # 5 CBA  ==  # 5 CBA

    Example of 'fastswap' mapping:

        Pf# fastswap Pn# natural
        # 0 ACB  ==  # 1 ACB
        # 1 BAC  ==  # 2 BAC
        # 2 CAB  ==  # 4 CAB
        # 3 ABC  ==  # 0 ABC
        # 4 BCA  ==  # 3 BCA
        # 5 CBA  ==  # 5 CBA
*/
void perm_ordering()
{
    char *output;
    char  set[]  = "ABC";
    int   base   = strlen( set );
    int   digits = 3;
    int   i, n;
    int   fact   = factorial( base );

    printf( "Set: %s\n", set );
    printf( "\n" );

    printf( "Permutations without repetitions ('natural' order):\n" );
    for( i = 0; i < fact; i++ )
    {
        output = itoa_perm_norep_natural( i, base, digits, set );
        printf( "  $%d = %s\n", i, output );
    }
    printf( "\n" );

    int  meta_perms  = factorial( fact );
    char meta_set[]  = "012345";
    int  meta_base   = fact;
    int  meta_digits = fact;
    char*meta_output = (char*) malloc( fact+1 );

    int  natural     = 0;
    int  match       = 0;
    int  temp        = 0;

    printf( "All possible ways to assign unique numbers to the %d permutations\n", fact );
    printf( "Meta permutation @:\n" );
    for( i = 0; i < meta_perms; i++ )
    {
        if (i && ((i % 5) == 0))
            printf( "\n" );

        if (i && ((i % 120) == 0))
            printf( "- - -\n" );

        output = itoa_perm_norep_natural( i, meta_base, meta_digits, meta_set );
        printf( "@%3d: %s  ", i, output );
    }
    printf( "\n\n" );

// Shift -> Natural -> Shift
    printf( "Example of 'shift' mapping:\n" );
    printf( "    Ps# shift    Pn# -- natural --    Ps# shift\n" );

    temp = 0;
    for( i = 0; i < fact; i++ )
    {
        output = itoa_perm_norep_natural( i, base, digits, set );
        temp  *= 10;
        temp  += atoi_perm_norep_shift( output, base, set );
    }

    for( i = 0; i < fact; i++ )
    {
        output  = itoa_perm_norep_shift( i, base, digits, set );
        natural = atoi_perm_norep_natural( output, base, set );
        printf( "    #%2d %s  ==  # %d", i, output, natural );

        output = itoa_perm_norep_natural( natural, base, digits, set );
        printf( " %s", output );

        output = itoa_perm_norep_natural( i, base, digits, set );
        strcpy( meta_output, output );
        n      = atoi_perm_norep_shift( output, base, set );
        output = itoa_perm_norep_natural( n, base, digits, set );
        printf( "   #%2d %s == # %d %s", i, meta_output, n, output );

        printf( "\n" );
    }

    printf( "Re-arranging the permutations of 'shift' in the order: %0*d\n", fact, temp );
    printf( "will have the same mapping as 'natural'\n" );

    // We don't know which 720 permutations the shift ordering matches
    // Treat the number 031425 as a set to find which meta it matches: @50
    for( i = 0; i < fact; i++, temp /= 10 )
        meta_output[ fact-i-1 ] = '0' + (temp % 10);
    meta_output[ fact ] = 0;

    match = atoi_perm_norep_natural( meta_output, meta_base, meta_set );
    printf( "Matches meta permutation: @%d\n", match );

    //output = itoa_perm_norep_natural( match, meta_base, meta_digits, meta_set );
    //printf( "DEBUG: %s\n", output ); // 024135
    printf( "\n" );

// Fast Swap -> Natural -> Fast Swap
    printf( "Example of 'fastswap' mapping:\n" );
    printf( "    Pf# fastswap Pn# -- natural --    Pf# fastswap\n" );

    temp = 0;
    for( i = 0; i < fact; i++ )
    {
        output = itoa_perm_norep_natural( i, base, digits, set );
        temp  *= 10;
        temp  += atoi_perm_norep_fastswap( output, base, set );
    }

    for( i = 0; i < fact; i++ )
    {
        output  = itoa_perm_norep_fastswap( i, base, digits, set );
        natural = atoi_perm_norep_natural( output, base, set );
        printf( "    #%2d %s  ==  # %d", i, output, natural );

        output = itoa_perm_norep_natural( natural, base, digits, set );
        printf( " %s", output );

        output = itoa_perm_norep_natural( i, base, digits, set );
        strcpy( meta_output, output );
        n      = atoi_perm_norep_fastswap( output, base, set );
        output = itoa_perm_norep_natural( n, base, digits, set );
        printf( "   #%2d %s == # %d %s", i, meta_output, n, output );

        printf( "\n" );
    }
    printf( "Re-arranging the permutations of 'fastswap' in the order: %0*d\n", fact, temp );
    printf( "will have the same mapping as 'natural'\n" );

    // We don't know which 720 permutations the shift ordering matches
    // Treat the number 301425 as a set to find which meta it matches: @362
    for( i = 0; i < fact; i++, temp /= 10 )
        meta_output[ fact-i-1 ] = '0' + (temp % 10);
    meta_output[ fact ] = 0;

    match = atoi_perm_norep_natural( meta_output, meta_base, meta_set );
    printf( "Matches meta permutation: @%d\n", match );

    //output = itoa_perm_norep_natural( match, meta_base, meta_digits, meta_set );
    //printf( "DEBUG: %s\n", output ); // 124035
    printf( "\n" );

// Summary

    printf( "= = =\n" );
    printf( "\n" );
    printf( "What this means:\n" );
    printf( "\n" );
    printf( "Given:\n" );
    printf( "\n" );
    printf( "    set S = { %s }\n", set );
    printf( "\n" );
    printf( "Which has n = %d elements\n", base );
    printf( "\n" );
    printf( "There are %d! = %d possible permutations (without repetitions):\n", base, fact );
    printf( "\n" );
    for( i = 0; i < fact; i++ )
    {
        output = itoa_perm_norep_natural( i, base, digits, set );
        printf( "    %s\n", output );
    }
    printf( "\n" );
    printf( "If we assign an unique id to each of the arrangements,\n" );
    printf( "how many different ways could we do this?\n" );
    printf( "\n" );
    printf( "For example, we could assign the permutations {ABC,ACB,...,CAB,CBA} the order:\n" );
    printf( "\n" );
    printf( "    0,1,2,3,4,5 = { ABC, ACB, ..., CAB, CBA }\n" );
    printf( "    0,1,2,3,5,4 = { ABC, ACB, ..., CBA, CAB }\n" );
    printf( "         :\n" );
    printf( "    5,4,3,2,1,0 = { CBA, CAB, ..., ACB, ABC }\n" );
    printf( "\n" );
    printf( "We could assign unique ids to the arrangements in:\n" );
    printf( "\n" );
    printf( "    n!! = %d!! = %d! = %d different ways.\n", base, fact, meta_perms );
    printf( "\n" );
    printf( "A few ways we could do this mapping (assigning names):\n" );
    printf( "\n" );

    int j, k;
    printf( "          Pn$  Ps#  Pf#\n" );
    for( i = 0; i < fact; i++ )
    {
        output = itoa_perm_norep_natural( i, base, digits, set );
        j      = atoi_perm_norep_shift   ( output, base, set );
        k      = atoi_perm_norep_fastswap( output, base, set );
        printf( "    %s   $%d   #%d   #%d\n", output, i, j, k );
    }
    printf( "          ^    ^    ^fast swap\n" );
    printf( "          |    shift\n" );
    printf( "          natural\n" );

    free( meta_output );
}

int main()
{
    perm_ordering();

    return 0;
}
