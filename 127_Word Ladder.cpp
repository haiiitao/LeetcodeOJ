class Solution {
public:
    int ladderLength( string beginWord, string endWord, vector<string>& wordList ) {
        unordered_set<string> dict;
        for ( auto& str : wordList )
            dict.insert( str );
        
        queue<string> q;
        unordered_set<string> visited;
        visited.insert( beginWord );
        q.push( beginWord );
        
        int level = 1;
        while ( !q.empty() ) {
            queue<string> next_q;
            while ( !q.empty() ) {
                string cur = q.front();
                if ( cur == endWord )
                    return level;
                    
                q.pop();
                GenNextStates( next_q, cur, visited, dict );
            }
            swap( q, next_q );
            level++;
        }
        return 0;
    }
    
    void GenNextStates( queue<string>& next_q, string& word, unordered_set<string>& visited, unordered_set<string>& dict ) {
        for ( int i = 0, len = word.size(); i < len; i++ ) {
            char temp = word[i];
            for ( char ch = 'a'; ch <= 'z'; ch++ ) {
                if ( ch == temp )
                    continue;
                
                word[i] = ch;
                if ( dict.count( word ) && visited.insert( word ).second ) 
                    next_q.push( word );
            }
            word[i] = temp;
        }
    }
};