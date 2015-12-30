    // Forward mapping: # -> $
    char* itoa_perm_norep_almost( unsigned int n, unsigned int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        const int        MAX_BASE = 16;
        static char tmp[ MAX_BASE ]; // variable length array: set[ base ]
        memcpy( tmp, SET, base );    // Optimization: strlen( SET ) == base
        int   f   = factorial( base - 1 );
        int   r   = n / f;
        char *dst = output;


        do
        {


            *dst++ = tmp[ r ];

            --base;
            memcpy( tmp + r, tmp + r + 1, base - r ); // Remove set[r] element, shift remaining elements
            r += n; r %=     base;
                    n  = n / base;
        } while (--length > 0);


        *dst = 0;
        return output;
    }

    // Reverse mapping: $ -> #
    int atoi_perm_norep_almost( const char *input, int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r, b = 1, base = BASE, fact = factorial( base - 1 ); // default to base

        if (base <  2) return -1; // Invalid base // Could also default to:
        if (base > 16) return -1; // Invalid base // strlen( SET ) == BASE

        const int        MAX_BASE = 16;
        static char tmp[ MAX_BASE ];
        memcpy( tmp, SET, base );

        for( int length = 0; length < digits; length++ )
        {
            r = find( base, tmp, *text++ );
            if (r < 0)
                return n;
//printf( "\nr: %d   n: %d   fact: %d   b: %d\n", r, n, fact, b ); // TODO: FIXME: Incorrect implementation
            n += (r * fact);
            b *= (BASE - length -1 );
            --base; fact /= base;
            memcpy( tmp + r, tmp + r + 1, base - r ); // Remove set[r] element
        }

        return n;
    }

