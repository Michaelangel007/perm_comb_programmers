    char* itoa_comb_fastswap( unsigned int n, int base, int length, const char MASTER_SET[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ]; // base=2 output in binary is 32 digits

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        static char set[ 16 ]; // variable length array: set[ base ]
        memcpy( set, MASTER_SET, base ); // Optimization: strlen( MASTER_SET ) == base

        int   r; // remainder
        char *dst = output;

        do
        {
            r = n % base;
            n = n / base;
            *dst++ = set[ r      ];
            set[r] = set[ --base ]; 
            // Optimization: instead of shifting workset over by one character
            // We move the last element into the slot that was just used
        } while (--length > 0);

        *dst = 0;
        return output;
    }