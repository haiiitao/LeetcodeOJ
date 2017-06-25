/**
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
 */
class Solution {
public:
    vector<string> findStrobogrammatic( int n ) {
        vector<string> result;
        rec( result, n );
        return result;
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