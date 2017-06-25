/**
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
 */
class Solution {
public:
    string convertToTitle( int n ) {
        if ( n < 1 ) return "";
        
        stringstream ss;
        do {
            n--;
            ss << char('A' + n % 26);
            n = n / 26;
        } while( n );
        
        string res = ss.str();
        reverse( res.begin(), res.end() );
        return res;
    }
};