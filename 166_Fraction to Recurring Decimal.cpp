/**
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
 */
class Solution {
public:
    string fractionToDecimal( int numerator, int denominator ) {
        long long_numerator = labs( numerator );
        long long_denominator = labs( denominator );
        long above = long_numerator / long_denominator;
        long below = long_numerator % long_denominator;
        
        bool sign = (numerator >> 31) ^ (denominator >> 31);
        string result = to_string( above );
        if ( sign && long_numerator ) result.insert( result.begin(), '-' );
        if ( below ) result.push_back( '.' );
            
        unordered_map<long, int> map_Quotient2Index;
        int idx = 0;
        while ( below ) {
            below *= 10;
            if ( map_Quotient2Index.count( below ) )
                break;
                
            map_Quotient2Index[below] = idx++;
            result.push_back( '0' + below / long_denominator );
            below %= long_denominator;
        }

        if ( below ) {
            int idx_left = map_Quotient2Index[below];
            int length = idx - idx_left;
            result.insert( result.end() - length, '(' );
            result.push_back( ')' );
        }
        return result;
    }
};