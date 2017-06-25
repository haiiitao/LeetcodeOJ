class Solution {
public:
    string alienOrder( vector<string>& words ) {
        unordered_map<char, bool> visited;
        unordered_map<char, bool> rec;
        unordered_map<char, unordered_set<char>> g;
        const int len = words.size();
        for ( int i = 0; i < len; i++ ) {
            for ( int j = 0; j < words[i].size(); j++ ) {
                visited[words[i][j]] = false;
                rec[words[i][j]] = false;
            }
        }
        for ( int i = 1; i < len; i++ ) {
            int len1 = words[i - 1].size();
            int len2 = words[i].size();
            int len3 = min( len1, len2 );
            for ( int j = 0; j < len3; j++ )
                if( words[i][j] != words[i-1][j] ) {
                    g[words[i][j]].insert(words[i-1][j]);
                    break;
                }
                if ( len1 > len2 && words[i-1].substr( 0, len2 ) == words[i] )
                    return "";
        }
        string result;
        for ( auto it = visited.begin(); it != visited.end(); it++ ) {
            if ( hasCycle( it->first, result, visited, rec, g ) )
                return "";
        }
        return result;
    }
    bool hasCycle( char start, string& result, unordered_map<char, bool>& visited, 
            unordered_map<char, bool>& rec, unordered_map<char, unordered_set<char>>& g ) {
        if ( !visited[start] ) {
            visited[start] = true;
            rec[start] = true;
            auto& next_set = g[start];
            for ( auto it = next_set.begin(); it != next_set.end(); it++ ) {
                if ( hasCycle( *it, result, visited, rec, g ) || rec[*it] )
                    return true;
            }
            rec[start] = false;
            result.push_back(start);
        }   
        return false;
    }
};