/**
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd"
 */
class Solution {
private:
    int longest_palindrome_prefix( const string &s ) const {
        string kmprev = s;
        std::reverse( kmprev.begin(), kmprev.end() );
        string kmp = s + "#" + kmprev;
        const int len = kmp.size();
        vector<int> lps( len, 0 ); 
        for ( int i = 1; i < len; ++i ) {
            int prev_idx = lps[i - 1];
            while ( prev_idx > 0 && kmp[i] != kmp[prev_idx] )
                prev_idx = lps[prev_idx - 1];

            lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
        }
        return lps[len - 1];
    }

public:
    string shortestPalindrome( const string& s ) {
        int k = longest_palindrome_prefix( s );
        string the_rest = s.substr( k );
        std::reverse( the_rest.begin(), the_rest.end() );

        return the_rest + s;
    }
};