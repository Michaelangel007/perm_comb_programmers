    // Forward mapping: # -> $
    char* itoa_comb_shift( unsigned int n, int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        const int        MAX_BASE = 16;
        static char set[ MAX_BASE ]; // variable length array: set[ base ]
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

    // Reverse mapping: $ -> #
    int atoi_comb_shift( const char *input, const int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r;
        /* */ int   b      = 1, base = BASE; // default to base

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        const int        MAX_BASE = 16;
        static char set[ MAX_BASE ];
        memcpy( set, SET, base );

        for( int length = 0; length < digits; length++ )
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

