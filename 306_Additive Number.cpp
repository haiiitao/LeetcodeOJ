/**
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. 
Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
 */
class Solution {
public:
    bool isAdditiveNumber( string num ) {
        for ( int i = 1, len = num.size(); i < len; i++ ) {
            for ( int j = 1; i + j < len; j++ ) {
                if ( dfs( num.substr( 0, i ), num.substr( i, j ), num, i + j ) )
                    return true;
            }
        }
        return false;
    }
    bool dfs( string num1, string num2, string& num, int start ) {
        if ( start == num.size() )
            return true;
            
        const int len1 = num1.size(), len2 = num2.size();
        if ( (len1 > 1 && num1[0] == '0') || (len2 > 1 && num2[0] == '0') )
            return false;
        
        string result;
        add( result, num1, num2 );
        if ( start + result.size() > num.size() || num.substr( start, result.size() ) != result )
            return false;

        return dfs( num2, result, num, start + result.size() );
    }
    void add( string& result, string num1, string num2 ) {
        reverse( num1.begin(), num1.end() );
        reverse( num2.begin(), num2.end() );
        const int len1 = num1.size(), len2 = num2.size();
        int c = 0;
        for ( int i = 0, len = max( len1, len2 ); i < len; i++ ) {
            int v1 = i < len1 ? num1[i] - '0' : 0;
            int v2 = i < len2 ? num2[i] - '0' : 0;
            result.push_back( '0' + ((c + v1 + v2) % 10) );
            c = (c + v1 + v2) / 10;
        }
        if ( c )
            result.push_back( '0' + c );
        
        reverse( result.begin(), result.end() );
    }
};