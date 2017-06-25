class Solution {
public:
    int strStr( string haystack, string needle ) {
        const int m = haystack.size(), n = needle.size();
        if ( !n ) 
            return 0;
            
        int f[n] = {};
        computekmp( needle, f );
        for ( int i = 0, j = 0; i < m; ) {
            if ( haystack[i] == needle[j] ) {
                i++;
                j++;
            } 
            if ( j == n )
                return i - j;
            
            if ( i < m && haystack[i] != needle[j] ) {
                if ( j )
                    j = f[j - 1];
                else
                    i++;
            }
        } 
        return -1;
    }
    void computekmp( string& str, int f[] ) {
        int len = str.size();
        for ( int i = 1, j = 0; i < len; ) {
            if ( str[i] == str[j] ) {
                f[i++] = ++j;
            } else if ( j )
                j = f[j - 1];
            else
                i++;
        }
    }
};