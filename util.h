    // Usage: const int fact = factorial( n );
    int factorial( int n )
    {
        int product = 1;
        while( n > 1 )
           product *= n--;
        return product;
    }

    /** Search for key in array of val
     * @param size     The size of the array to search
     * @param haystack The array (vals) to search
     * @param needle   They key to find
     */
    int find( const size_t size, const char *haystack, const char needle )
    {
        const char *dst = haystack;
        const char *end = haystack + size;

        while( dst < end )
        {
            if( *dst == needle )
                return (dst - haystack);
            dst++;
        }
        return -1; // not found
    }

