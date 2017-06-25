/**
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
 */
class Solution {
public:
    vector<string> generatePalindromes( string s ) {
        int counter[128] = {};
        if ( !canPermutePalindrome( s, counter ) )
            return {};
        
        vector<string> result;
        string temp;
        char odd = 0;
        for ( int i = 0; i < 128; i++ ) {
            if ( counter[i] )
                temp.append( counter[i] / 2, char( i ) );
            
            if ( counter[i] % 2 == 1)
                odd = i;
        }
        do {
            result.push_back( temp );
        } while( next_permutation( temp.begin(), temp.end() ) );
        for ( int i = 0; i < result.size(); i++ ) {
            string rev = result[i];
            reverse( rev.begin(), rev.end() );
            if ( odd )
                result[i] = result[i] + odd + rev;
            else
                result[i] = result[i] + rev;
        }
        return result;
    }
    bool canPermutePalindrome( string& s, int counter[] ) {
        for ( auto ch : s )
            counter[ch]++;
        
        int odd = 0;
        for ( int i = 0; i < 128; i++ )
            if ( counter[i] % 2 == 1 )
                odd++;
    
        return odd <= 1;
    }
};