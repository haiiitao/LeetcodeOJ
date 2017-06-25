class Solution {
public:
    vector<string> restoreIpAddresses( string s ) {
        vector<string> result;
        dfs( s, 0, result, "", 0 );
        return result;
    }
    void dfs( string& s, int start, vector<string>& result, string path, int level ) {
        if ( level > 4 )
            return;
            
        if ( start == s.size() && level == 4 ) {
            path.pop_back();
            result.push_back( path );
            return;
        }
        for ( int i = start + 1; i <= s.size() &&  i <= start + 3; i++ ) {
            string candidate = s.substr( start, i - start );
            if ( candidate.size() > 1 && candidate[0] == '0' )
                continue;
            
            int num = atoi( candidate.c_str() );
            if ( num > 255 )
                continue;
            
            dfs( s, i, result, path + candidate + ".", level + 1 );
        }
    }
};