/**
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, 
it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) 
that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences( string s ) {
        unordered_map<int, int> counter;
        vector<string> result;
        int mask = 0x0003ffff, cur = 0;
        for ( int i = 0, len = s.size(); i < len; i++ ) {
            cur &= mask;
            cur <<= 2;
            if ( s[i] == 'A') cur |= 0;
            else if ( s[i] == 'C') cur |= 1;
            else if ( s[i] == 'G') cur |= 2;
            else if ( s[i] == 'T') cur |= 3;
            if ( i >= 9 && ++counter[cur] == 2 )
                result.push_back( s.substr( i - 9, 10 ) );
        }
        return result;
    }
};