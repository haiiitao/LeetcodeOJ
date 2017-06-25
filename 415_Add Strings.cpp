/**
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */
class Solution {
public:
    string addStrings( string num1, string num2 ) {
        const int len1 = num1.size(), len2 = num2.size();
        const int len = max( len1, len2 );
        reverse( num1.begin(), num1.end() );
        reverse( num2.begin(), num2.end() );
    
        stringstream ss;
        int c = 0;
        for ( size_t i = 0; i < len; i++ ) {
            const int v1 = i < len1 ? num1[i] - '0' : 0;
            const int v2 = i < len2 ? num2[i] - '0' : 0;
            ss << (v1 + v2 + c ) % 10;
            c = (v1 + v2 + c) / 10;
        }
        if ( c )
            ss << c;
        
        string result = ss.str();
        reverse( result.begin(), result.end() );
        return result;
    }
};