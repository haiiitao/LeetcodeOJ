class Solution {
public:
    bool sequenceReconstruction( vector<int>& org, vector<vector<int>>& seqs ) {
        if ( seqs.empty() ) 
            return false;
            
        const int len = org.size();
        vector<int> pos( len + 1 );
        for ( int i = 0; i < len; ++i ) 
            pos[org[i]] = i;
        
        vector<char> flags( len + 1, 0 );
        int toMatch = len - 1;
        for ( const auto& v : seqs ) {
            for ( int i = 0; i < v.size(); ++i ) {
                if ( v[i] <= 0 || v[i] > len )
                    return false;
                
                if ( i == 0 )
                    continue;
                
                int x = v[i - 1], y = v[i];
                if ( pos[x] >= pos[y] ) 
                    return false;
                    
                if ( flags[x] == 0 && pos[x] + 1 == pos[y] ) { 
                    flags[x] = 1;
                    --toMatch;
                }
            }
        }
        return toMatch == 0;
    }
};