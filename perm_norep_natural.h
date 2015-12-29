    // Forward mapping: # -> $
    char* itoa_perm_norep_natural( unsigned int n, int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        const int        MAX_BASE = 16;
        static char tmp[ MAX_BASE ]; // variable length array: set[ base ]
        memcpy( tmp, SET, base );    // Optimization: strlen( SET ) == base

        int   r; // remainder
        char *dst = output;
        int  fact = factorial( base - 1 );

        do
        {
            r  = n / fact; // Normally would be: n % base
            n -= r * fact; // Normally would be: n / base // Optimization: n %= f;
            *dst++ = tmp[ r ];

            --base;
            memcpy( tmp + r, tmp + r + 1, base - r ); // Remove set[r] element
            fact /= base; // Optimization: Calculate previous factorial(base-1)
        } while (--length > 0);

        *dst++ = tmp[ n % base ];
        *dst = 0;
        return output;
    }

    // Reverse mapping: $ -> #
    int atoi_perm_norep_natural( const char *input, int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n = 0, r, b = 1, base = BASE; // default to base

        const int        MAX_BASE = 16;
        static char set[ MAX_BASE ];
        memcpy( set, SET, base );

        for(int length = 0; length < digits; length++ )
        {
            r = find( base, set, *text++ );
        }

        return n;
    }

