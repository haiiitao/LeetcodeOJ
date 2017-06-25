class Solution {
public:
    int numDecodings( string s ) {
        int prev2 = 0, prev1 = 1, cur = 0;
        for ( int i = 1, len = s.size(); i <= len; i++ ) {
            if ( s[i - 1] == '0' ) {
                if ( i > 1 && s[i - 2] == '1' || s[i - 2] == '2' )
                    cur = prev2;
                else
                    return 0;
            } else {
                if ( i > 1 && s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6' )
                    cur = prev1 + prev2;
                else
                    cur = prev1;
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};

class Solution {
public:
    int numDecodings( string s ) {
        const int len = s.size();
        if ( !len )
            return 0;
            
        int f[len + 1] = { 1 };
        for ( int i = 1; i <= len; i++ ) {
            if ( s[i - 1] == '0' ) {
                if ( i >= 2 && (s[i - 2] == '1' || s[i - 2] == '2') )
                    f[i] = f[i - 2];
                else
                    return 0;
            } else if ( i >= 2 && ((s[i - 1] <= '6' && s[i - 2] == '2') || s[i - 2] == '1') ) {
                f[i] = f[i - 2] + f[i - 1];
            } else
                f[i] = f[i - 1];
        }
        return f[len];
    }
};