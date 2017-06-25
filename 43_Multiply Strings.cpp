/**
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
 */
class Solution {
public:
    string multiply( string num1, string num2 ) {
        const int len1 = num1.size(), len2 = num2.size();
        reverse( num1.begin(), num1.end() );
        reverse( num2.begin(), num2.end() );
        string result;
        result.append( len1 + len2, 0 );
        for ( size_t i = 0; i < len1; i++ ) {
            const int v1 = num1[i] - '0';
            for ( size_t j = 0; j < len2; j++ ) {
                const int v2 = num2[j] - '0';
                char& r1 = result[i + j], &r2 = result[i + j + 1];
                r1 += v1 * v2;
                r2 += r1 / 10;
                r1 %= 10;
            }
        }
        transform( result.begin(), result.end(), result.begin(), []( char ch ) { return ch + '0'; } );
        reverse( result.begin(), result.end() );
        result.erase( 0, result.find_first_not_of( '0' ) );
        return result.empty() ? "0" : result;
    }
};