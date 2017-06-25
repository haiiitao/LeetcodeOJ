/**
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
 */
class Solution {
public:
    vector<string> addOperators( string num, int target ) {
        const int len = num.size();
        vector<string> result;
        for ( int i = 1; i <= len; i++ ) {
            string e = num.substr( 0, i );
            if ( e.size() > 1 && e[0] == '0' )
                break;

            dfs( result, e, i, atol( e.c_str() ), 0, target, num );
        }
        return result;
    }
    void dfs ( vector<string>& result, string path, int start, long pre_commit, long commit, int target, string& num ) {
        const int len = num.size();
        if ( start == len && (pre_commit + commit) == target ) {
            result.push_back( path );
            return;
        } 
        for ( int i = start + 1; i <= len; i++ ) {
            string e = num.substr( start, i - start );
            if ( e.size() > 1 && e[0] == '0' )
                break;
                    
            int temp = atol( e.c_str() );
            dfs( result, path + "+" + e, i, temp, pre_commit + commit, target, num );
            dfs( result, path + "-" + e, i, -temp, pre_commit + commit, target, num );
            dfs( result, path + "*" + e, i, pre_commit * temp, commit, target, num );
        }            
    };
};