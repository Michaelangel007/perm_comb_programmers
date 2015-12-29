    // Forward mapping: # -> $
    char* itoa_comb_almost( unsigned int n, unsigned int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        const int        MAX_BASE = 16;
        static char tmp[ MAX_BASE ]; // variable length array: set[ base ]
        memcpy( tmp, SET, base ); // Optimization: strlen( SET ) == base
        int   f   = factorial( base - 1 );
        int   r   = n / f;
        char *dst = output;

        do
        {
            *dst++ = tmp[ r ];

            --base;
            memcpy( tmp + r, tmp + r + 1, base - r ); // Remove set[r] element

            r += n % base;
            n  = n / base;
            if (r >= base)
                r %= base;
        } while (--length > 0);

        *dst = 0;
        return output;
    }

    // Reverse mapping: $ -> #
    int atoi_comb_almost( const char *input, int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r;
        /* */ int   b      = 1, base = BASE; // default to base

        const int        MAX_BASE = 16;
        static char set[ MAX_BASE ];
        memcpy( set, SET, base );

// TODO: FIXME:
        r = 0;

        return n;
    }

