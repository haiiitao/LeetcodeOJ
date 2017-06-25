/**
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
 */
class Solution {
public:
    vector<vector<string>> findLadders( string start, string end, unordered_set<string>& dict) {
        queue<string> current;
        unordered_set<string> visit, set_next;
        unordered_map<string, vector<string>> tree;
        current.push( start );
        bool found = false;
        while ( !current.empty() && !found ) {
            while ( !current.empty() ) {
                string& word = current.front();
                queue<string> temp;
                GenNextStates( temp, word, dict, visit );
                while ( !temp.empty() ) {
                    set_next.insert( temp.front() );
                    tree[temp.front()].push_back( word );
                    if ( temp.front() == end )
                        found = true;
                        
                    temp.pop();
                }
                current.pop();
            }
            for ( auto& str : set_next ) {
                current.push( str );
                visit.insert( str );
            }
            set_next.clear();
        }
        vector<vector<string>> result;
        vector<string> path;
        if ( found )
            gen_path( tree, path, start, end, result );

        return result;
    }
    
private:
    void gen_path( unordered_map<string, vector<string>>& father,
            vector<string>& path, const string& start, const string& word,
            vector<vector<string>>& result ) {
        path.push_back( word );
        if ( word == start ) {
            result.push_back( path );
            reverse( result.back().begin(), result.back().end() );
        } else 
            for ( const auto& f : father[word] ) 
                gen_path( father, path, start, f, result );
        
        path.pop_back();
    }
    
    void GenNextStates( queue<string>& next, string& s, unordered_set<string>& dict, unordered_set<string>& visit ) {
        for ( size_t i = 0, len = s.size(); i < len; ++i ) {
            for ( char c = 'a'; c <= 'z'; c++ ) {
                if ( c == s[i] ) 
                    continue;
                
                swap( c, s[i] );
                if ( dict.count( s ) && !visit.count( s ) ) 
                    next.push( s );
                
                swap( c, s[i] );
            }
        }
    }
};