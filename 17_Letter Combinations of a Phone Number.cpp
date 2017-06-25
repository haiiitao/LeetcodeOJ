class Solution {
public:
    const vector<string> keyboard { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations( const string& digits ) {
        vector<string> result;
        dfs( digits, 0, "", result );
        
        return result;
    }
    
private:
    void dfs( const string& digits, size_t cur, string path, vector<string>& result ) { 
        if ( cur && cur == digits.size() ) {
            result.push_back( path );
            return;
        }
        
        for ( auto c : keyboard[digits[cur] - '0'] ) 
            dfs( digits, cur + 1, path + c, result );
    }
};