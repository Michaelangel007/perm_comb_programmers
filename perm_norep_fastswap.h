    // Forward mapping: # -> $
    char* itoa_perm_norep_fastswap( unsigned int n, unsigned int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ]; // base=2 max output in binary is 32 digits

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        const int        MAX_BASE = 16;
        static char tmp[ MAX_BASE ]; // variable length array: set[ base ]
        memcpy( tmp, SET, base );    // Optimization: strlen( SET ) == base

        int   r; // remainder
        char *dst = output;


        do
        {
            r = n % base;
            n = n / base;
            *dst++ = tmp[ r ];

            --base;
            tmp[r] = tmp[ base ]; // Optimization: instead of shifting workset over by one character
                                  // We move the last element into the slot that was just used

        } while (--length > 0);


        *dst = 0;
        return output;
    }

    // Reverse mapping: $ -> #
    int atoi_perm_norep_fastswap( const char *input, int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r, b = 1, base = BASE; // default to base

        if (base <  2) return -1; // Invalid base // Could also default to:
        if (base > 16) return -1; // Invalid base // strlen( SET ) == BASE

        const int        MAX_BASE = 16;
        static char set[ MAX_BASE ];
        memcpy( set, SET, base );

        for( int length = 0; length < digits; length++ )
        {
            r = find( base, set, *text++ );
            if (r < 0)
                return n;

            n += (r * b);
            b *= base;
            --base;
            set[ r ] = set[ base ];
        }

        return n;
    }

