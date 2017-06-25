class Solution {
public:
    vector<int> plusOne( vector<int> &digits ) {
        int c = 1;
        for ( auto it = digits.rbegin(); it != digits.rend(); it++ ) {
            *it += c;
            c = *it / 10;
            *it %= 10;
        }
        
        if ( c ) 
            digits.insert( digits.begin(), 1 );

        return digits;
    }
};