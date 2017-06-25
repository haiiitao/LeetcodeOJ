/**
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
 */
class Solution {
public:
    int minDistance( string str1, string str2 ) {
        const int len1 = str1.size(), len2 = str2.size();
        int f[len2 + 1];
        for ( int i = 0; i <= len2; i++ )
            f[i] = i;
        
        for ( int i = 1; i <= len1; i++ ) {
            int upper_left = i - 1;
            f[0] = i;
            for ( int j = 1; j <= len2; j++ ) {
                int temp = f[j];
                if ( str1[i - 1] == str2[j - 1] )
                    f[j] = upper_left;
                else
                    f[j] = 1 + min( upper_left, min( f[j], f[j - 1] ) );
                
                upper_left = temp;
            }
        }
        return f[len2];
    }
};