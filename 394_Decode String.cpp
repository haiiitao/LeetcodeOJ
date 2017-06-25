class Solution {
public:
    string decodeString( string s ) {
        stringstream ss;
        size_t pos = 0;
        dfs( s, ss, pos );
        return ss.str();
    }
    
    void dfs( string& s, stringstream& ss, size_t& i ) {
        for ( size_t len = s.size(); i < len; i++ ) {
            if ( ::isalpha( s[i] ) )
                ss << s[i];
            else if ( ::isdigit( s[i] ) ) {
                int num = 0;
                do {
                    num = num * 10 + (s[i] - '0');
                } while( ::isdigit( s[++i] ) );
                stringstream ss_next;
                ++i; // skip [
                dfs( s, ss_next, i );
                for ( int j = 0; j < num; j++ )
                    ss << ss_next.str();
            } else if ( s[i] == ']' ) 
                return;
        }
    }
};