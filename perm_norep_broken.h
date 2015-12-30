    // Reverse mapping: $ -> #
    int atoi_perm_norep_broken( const char *input, int BASE, const char SET[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r, b = 1, base = BASE, fact = factorial( base - 1 ); // default to base

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
            n += (r * fact);
            b *= (BASE - length -1 );
            --base; fact /= base;
            memcpy( set + r, set + r + 1, base - r ); // Remove set[r] element
        }

        return n;
    }

