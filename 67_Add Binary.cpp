class Solution
{
public:
    string addBinary( string a, string b ) {
        const int len1 = a.size(), len2 = b.size();
        const int len = max( len1, len2 );
        string result( len, '0' );
        
        int c = 0, i = len1 - 1, j = len2 - 1, k = len - 1;
        while ( i >= 0 || j >= 0 ) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            result[k--] += c % 2;
            c /= 2;
        }
        if ( c )
            result.insert( result.begin(), char('0' + c) );
            
        return result;
    }
};

class Solution {
public:
    string addBinary( string a, string b ) {
        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );
        const int len1 = a.size(), len2 = b.size();
        string result;
        int c = 0;
        for ( size_t i = 0; i < len1 || i < len2; i++ ) {
            int v1 = i < len1 ? a[i] - '0' : 0;
            int v2 = i < len2 ? b[i] - '0' : 0;
            result.append( 1, '0' + (v1 + v2 + c) % 2 );
            c = (v1 + v2 + c) / 2;
        }
        
        if ( c )
            result.append( 1, '1' );
            
        reverse( result.begin(), result.end() );
        
        return result;
    }
};