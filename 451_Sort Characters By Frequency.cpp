class Solution {
public:
    string frequencySort( string s ) {
        int counter[128] = { 0 };
        for ( auto ch : s )
            counter[ch]++;
            
        map<int, vector<char>> cnt2char;
        for ( int i = 0; i < 128; i++ ) {
            if ( !counter[i] )
                continue;
            
            cnt2char[counter[i]].push_back( char(i) );
        }
        stringstream ss;
        for ( auto it = cnt2char.rbegin(), itEnd = cnt2char.rend(); it != itEnd; it++ ) {
            for ( int i = 0, len = it->second.size(); i < len; i++ ) {
                for ( int j = 0; j < it->first; j++ )
                    ss << it->second[i];
            }
        }
        return ss.str();
    }
};