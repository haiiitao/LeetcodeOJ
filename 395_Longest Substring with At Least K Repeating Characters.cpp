class Solution {
public:
    int longestSubstring( string s, int k ) {
        const int len = s.size();
        if ( !len || k > len )   
            return 0;

        int counter[128] = { 0 };
        for ( int i = 0; i < len; i++ ) 
            counter[s[i]]++;
        
        int idx =0;
        while ( idx < len && counter[s[idx]] >= k )    
            idx++;
            
        if ( idx == len ) 
            return len;
        
        int left = longestSubstring( s.substr( 0 , idx ) , k );
        int right = longestSubstring( s.substr( idx + 1 ) , k );
        return max( left, right );
    }
};