class Solution {
public:
    int findSubstringInWraproundString( string p ) {
        int f[128] = { 0 };
        int result = 0;
        for ( int i = 0, len = p.size(), temp = 0, prev = 0; i < len; i++ ) {
            int cur = p[i] - 'a';
            if ( cur != (prev + 1) % 26 )
                temp = 0;
            
            if ( ++temp > f[p[i]] ) {
                result += temp - f[p[i]];
                f[p[i]] = temp;
            }
            prev = cur;
        }
        return result;
    }
};