class Solution {
public:
    vector<string> removeInvalidParentheses( string str ) {
        vector<string> res;
        int left = 0, right = 0;
        for ( char ch : str ) {
            if ( ch == '(' ) {
                ++left;
            } else if ( ch == ')' ) {
                if ( left > 0 ) --left;
                else ++right;
            }
        }
        dfs( res, str, 0, left, right, 0, "" );
        return res;
  }
  
private:
    void dfs( vector<string>& res, const string& s, int start, int left, int right, int open, string path ) {
        const int len = s.size();
        if ( start == len || left < 0 || right < 0 || open < 0 ) {
            if ( left == 0 && right == 0 && open == 0 ) 
                res.push_back(path);
            
            return;
        }
        char c = s[start];
        if ( c == '(' ) {
            if ( start == 0 || s[start - 1] != c ) {
                for ( int i = 0; start + i < len && s[start + i] == c; ++i )
                    dfs( res, s, start + i + 1, left - i - 1, right, open, path );
            }
            dfs( res, s, start + 1, left, right, open + 1, path + c );
        } else if ( c == ')' ) {
            if ( start == 0 || s[start - 1] != c ) {
                for ( int i = 0; start + i < len && s[start + i] == c; ++i )
                    dfs( res, s, start + i + 1, left, right - i - 1, open, path );
            }      
            dfs( res, s, start + 1, left, right, open - 1, path + c );
        } else 
            dfs( res, s, start + 1, left, right, open, path + c );
    }
};

class Solution {
public:
    vector<string> removeInvalidParentheses( string s ) {
        unordered_set<string> res;
        int left_count = 0, right_count = 0;
        for ( int i = 0, len = s.size(); i < len; i++ ) {
            if ( s[i] == '(' ) {
                left_count++;
            } else if ( s[i] == ')' ) {
                if ( left_count )
                    left_count--;
                else
                    right_count++;
            }
        }
        dfs( res, s, 0, left_count, right_count, 0, "" );
        return vector<string>( res.begin(), res.end() );
    }
    
    void dfs( unordered_set<string>& result, string& s, int start, int left_count, int right_count, int open_count, string path ) {
        const int len = s.size();
        if ( start == len || left_count < 0 || right_count < 0 || open_count < 0 ) {
            if ( left_count == 0 && right_count == 0 && open_count == 0 )
                result.insert( path );
            
            return;
        }
        char ch = s[start++];
        if ( ch == '(' ) {
            dfs( result, s, start, left_count - 1, right_count, open_count, path );
            dfs( result, s, start, left_count, right_count, open_count + 1, path + ch );
        } else if ( ch == ')' ) {
            dfs( result, s, start, left_count, right_count - 1, open_count, path );
            dfs( result, s, start, left_count, right_count, open_count - 1, path + ch );
        } else 
            dfs( result, s, start, left_count, right_count, open_count, path + ch );
    }
};