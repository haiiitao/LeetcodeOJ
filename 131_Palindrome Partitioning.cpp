class Solution {
public:
    void getPartition( string& s, int idx, vector<string>& path, 
            vector<vector<string>>& result, bool p[] ) {
        const int len = s.size();
        if ( idx == len ) {
            result.push_back( path );
            return;
        }
        
        int base = idx * len;
        for ( int j = idx; j < len; j++ ) {
            if ( p[base + j] ) {
                path.push_back( s.substr( idx, j - idx + 1 ) );
                getPartition( s, j + 1, path, result, p );
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition( string s ) {
        const int len = s.size();
        bool p[len * len];
        fill_n( p, len * len, false );
                
        for ( int i = len - 1; i >= 0; i-- ) {
            for ( int j = i; j < len; j++ ) {
                if ( s[i] == s[j] && ((j - i < 2) || p[(i + 1) * len + (j - 1)]) ) {
                    p[i * len + j] = true;
                }
            }
        }
            
        vector<vector<string>> result;
        vector<string> path;
        getPartition( s, 0, path, result, p );
        
        return result;
    }
};

// ==> another Solution
class Solution {
public:
    vector<vector<string>> partition( string s ) {
        vector<vector<string>> result;
        vector<string> path;
        getPartition( s, 0, path, result );
        
        return result;
    }
private: 
    void getPartition( string& s, int idx, vector<string>& path, vector<vector<string>>& result ) {
        const int len = s.size();
        if ( idx == len ) {
            result.push_back( path );
            return;
        }
        for ( int i = idx; i < len; i++ ) {
            int l = idx, r = i;
            while ( l < r && s[l] == s[r] ) 
                l++, r--;
            
            if ( l >= r ) {
                path.push_back( s.substr( idx, i - idx + 1 ) );
                getPartition( s, i + 1, path, result );
                path.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> partition( string s ) {
        int len = s.size();
        bool f[len * len] = {};
        for ( int i = 0; i < len; i++ ) {
            for ( int j = i; j >= 0; j-- ) {
                if ( (i - j < 2 || f[len * (j + 1) + i - 1]) && s[i] == s[j] )
                    f[j * len + i] = true;
            }
        }
        vector<vector<string>> result;
        vector<string> path;
        getPartition( s, 0, path, result, f );
        
        return result;
    }
    void getPartition( string& s, int start, vector<string>& path, vector<vector<string>>& result, bool f[] ) {
        const int len = s.size();
        if ( start == len ) {
            result.push_back( path );
            return;
        }
        for ( int i = start + 1; i <= len; i++ ) {
            if ( f[start * len + i - 1] ) {
                path.push_back( s.substr( start, i - start ) );
                getPartition( s, i, path, result, f );
                path.pop_back();
            }
        }
    }
};