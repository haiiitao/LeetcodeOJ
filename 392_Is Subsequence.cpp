class Solution {
public:
    bool isSubsequence( string s, string t ) {
        reverse( s.begin(), s.end() );
        for ( int i = 0, len = t.size(); !s.empty() && i < len; i++ ) {
            if ( t[i] == s.back() )
                s.pop_back();
        }
        return s.empty();
    }
};

class Solution {
public:
    bool isSubsequence( string s, string t ) {
        size_t pos = 0;
        for ( size_t i = 0, len = s.size(); i < len; i++ ) {
            pos = t.find( s[i] , pos );
            if ( pos == string::npos )
                return false;
            
            pos++;
            if ( pos == len && i == len - 1)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isSubsequence( string s, string t ) {
        int idxs = 0, idxt = 0;
        const int lens = s.size(), lent = t.size();
        while ( idxs < lens && idxt < lent ) {
            if ( s[idxs] == t[idxt] ) {
                idxs++;
                idxt++;
            } else
                idxt++;
        }
        return idxs == lens;
    }
};