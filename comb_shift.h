    char* itoa_comb_shift( unsigned int n, int base, int length, const char SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        static char set[ 16 ]; // variable length array: set[ base ]
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
