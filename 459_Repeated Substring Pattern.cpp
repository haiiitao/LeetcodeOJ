class Solution {
public:
    bool repeatedSubstringPattern( string str ) {
        const int len = str.size();
        int f[len] = { 0 };
        for ( int i = 1, j = 0; i < len; i++ ) {
            while( j && str[j] != str[i] )
                j = f[j - 1];
            
            if ( str[i] == str[j] ) 
                f[i] = ++j;
        }
        return f[len - 1] && len % (len - f[len-1]) == 0;
    }
};