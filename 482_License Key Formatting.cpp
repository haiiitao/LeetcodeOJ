class Solution {
public:
    string licenseKeyFormatting( string S, int K ) {
        int count = 0, len = S.size();
        string result;
        for ( int i = 0; i < len; i++ ) {
            if ( S[i] != '-' ) {
                count++;
                if ( S[i] >= 'a' && S[i] <= 'z' )
                    S[i] -= 32;
            }
        }
        
        int mod = count % K;
        int i = 0;
        while ( mod >= 1 ) {
            if ( S[i] == '-' ) {
                i++;
                continue;
            }
            mod--;
            result.push_back( S[i++] );
        }
        result.push_back( '-' );
        
        for ( ; i < len; ) {
            if ( S[i] == '-' ) {
                i++;
                continue;
            }
            int count = K;
            while ( count >= 1 ) {
                if ( S[i] == '-' ) {
                    i++;
                    continue;
                }
                count--;
                result.push_back( S[i++] );
            }
            result.push_back( '-' );
        }
        
        result.pop_back();
        if ( result.size() > 1 && result[0] == '-' )
            result.erase( result.begin() );
            
        return result;
    }
};