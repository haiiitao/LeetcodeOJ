class Solution {
public:
    vector<vector<int>> combine( int n, int k ) {
        vector<int> path;
        vector<vector<int>> result;
        dfs( result, path, 1, n, k );
        
        return result;
    }
    
private:
    void dfs( vector<vector<int>>& result, vector<int>& path, int j, int n, int k ) {
        if ( path.size() == k ) {
            result.push_back( path );
            return;
        }
        for ( int i = j; i <= n; i++ ) {
            path.push_back( i );
            dfs( result, path, i + 1, n, k );
            path.pop_back();
        }
    }
};