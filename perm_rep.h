    char* itoa_perm_rep( unsigned int n, unsigned int base, int length, const char set[] = "0123456789ABCDEF" )
    {
        const  int          MAX_DIGITS = 32;
        static char output[ MAX_DIGITS + 1 ];

        if (base <  2) base =  2;
        if (base > 16) base = 16;

        int   r;
        char *dst = output + MAX_DIGITS;
        *dst-- = 0;

        do
        {
            r = n % base;
            n = n / base;
            *dst-- = set[ r ];
        } while (--length > 0);

        return dst+1;
    }

    int atoi_perm_rep( const char *input, const unsigned int base, const char set[] = "0123456789ABCDEF" )
    {
        const char *text   = input;
        /* */ int   digits = strlen( input );
        /* */ int   n      = 0, r;

        for( int length = 0; length < digits; length++ )
        {
            r = find( base, set, *text++ );

            if( r < 0 )
                return n;

            n *= base;
            n += r;
        }

        return n;
    }


