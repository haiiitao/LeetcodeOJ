/**
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
 */
class Solution {
public:
    bool isInterleave( string s1, string s2, string s3 ) {
        const int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if ( len1 + len2 != len3 )
            return false;
            
        bool f[len2 + 1] = { false };
        f[0] = true;
        for ( int i = 1; i <= len2; i++ )
            f[i] = f[i - 1] && ( s2[i - 1] == s3[i - 1] );
            
        for ( int i = 1; i <= len1; i++ ) {
            f[0] = s1[i - 1] == s3[i - 1] && f[0]; // haven't use any char in s2 yet
            for ( int j = 1; j <= len2; j++ )
                f[j] = ( f[j] && s1[i - 1] == s3[i + j - 1] ) // [i-1][j]
                || ( f[j - 1] && s2[j - 1] == s3[i + j - 1] ); // [i][j-1]
        }
        return f[s2.size()];
    }
};

// recursion, time exceed
class Solution {
public:
    bool isInterleave( string s1, string s2, string s3 ) {
        if ( s1.size() + s2.size() != s3.size() )
            return false;
            
        return check( s1, 0, s2, 0, s3, 0 );
    }
private:
    bool check( string& s1, int idx1, string& s2, int idx2, string& s3, int idx3) {
        if ( idx3 == s3.size() )
            return true;
        
        if ( s1[idx1] == s3[idx3] && check( s1, idx1 + 1, s2, idx2, s3, idx3 + 1 ) ) 
            return true;
    
        if ( s2[idx2] == s3[idx3] && check( s1, idx1, s2, idx2 + 1, s3, idx3 + 1 ) ) 
            return true;
        
        return false;
    }
};