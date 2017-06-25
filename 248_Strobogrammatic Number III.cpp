/**
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
 */
class Solution {
public:
    int strobogrammaticInRange( string low, string high ) {
        int result = 0;
        const int lenL = low.size(), lenH = high.size();
        if ( lenL > lenH || (lenL == lenH && high < low) )
            return result;

        vector<string> result1, result2;
        rec( result1, lenL );
        if ( lenH > lenL ) rec( result2, lenH );
        
        for ( int i = lenL + 1; i < lenH; i++ )
            result += getCount( i );
            
        for ( auto& str : result1 )
            if ( lenL == lenH && low <= str && str <= high )
                result++;
            else if ( lenL != lenH && low <= str )
                result++;
                
        for ( auto& str : result2 )
            if ( lenL == lenH && low <= str && str <= high )
                result++;
            else if ( lenL != lenH && str <= high )
                result++;
        
        return result;
    }

private:
    int getCount( int n ) {
        int result = n % 2 ? 3 : 1;
        n /= 2;
        for ( int i = 1; i < n; i++ )
            result *= 5;
            
        return result * 4;
    }
    
    void rec( vector<string>& result, int n, bool first = true ) {
        if ( n <= 0 ) {
            result.push_back( "" );
            return;
        } else if ( n == 1 ) {
            result.push_back( "0" );
            result.push_back( "1" );
            result.push_back( "8" );
            return;
        }
        vector<string> tmpRes;
        rec( tmpRes, n - 2, false );
        for ( auto& str : tmpRes ) {
            str = "0" + str + "0";
            if ( !first ) result.push_back( str );
                
            str[0] = '1', str.back() = '1'; result.push_back( str );
            str[0] = '8', str.back() = '8'; result.push_back( str );
            str[0] = '9', str.back() = '6'; result.push_back( str );
            str[0] = '6', str.back() = '9'; result.push_back( str );
        }
    }
};