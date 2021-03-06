    // Forward mapping: # -> $
    char* itoa_perm_norep_natural( unsigned int n, unsigned int base, int length, const char SET[] = "0123456789ABCDEF" )
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
        int  fact = factorial( base - 1 );

        do
        {
            r  = n / fact; // Normally would be: n % base
            n -= r * fact; // Normally would be: n / base // Optimization: n %= fact;
            *dst++ = tmp[ r ];

            --base;
            memcpy( tmp + r, tmp + r + 1, base - r ); // Remove set[r] element

            fact /= base; // Optimization: Calculate previous factorial(base-1)
        } while (--length > 1);

        *dst++ = tmp[ n % base ];
        *dst = 0;
        return output;
    }

    // Reverse mapping: $ -> #
    int atoi_perm_norep_natural( const char *input, int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r, fact = factorial( BASE - 1 ), base = BASE;

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

            n += (r * fact);
            if( base > 1) // when length == digit-1 we can skip these last instructions to update the working set
            {
                --base;
                fact /= base;
                memcpy( tmp + r, tmp + r + 1, base - r ); // Remove set[r] element
            }
        }

        return n;
    }

