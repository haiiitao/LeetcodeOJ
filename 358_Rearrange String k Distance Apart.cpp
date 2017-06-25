class Solution {
public:
    string rearrangeString( string str, int k ) {
        int counter[128] = {0};
        int valid[128] = {0};
        for ( auto ch : str )
            counter[ch]++;
            
        string result;
        for ( int i = 0, len = str.size(); i < len; i++ ) {
            int candidate = findCandidate( i, counter, valid );
            if ( candidate == -1 )
                return "";
            
            result.push_back( char(candidate) );
            counter[candidate]--;
            valid[candidate] = i + k;
        }
        return result;
    }
    int findCandidate( int idx,  int counter[], int valid[] ) {
        int candidate = -1;
        int max_count = INT_MIN;
        for ( int i = 0; i < 128; i++ ) {
            if ( counter[i] && counter[i] > max_count && idx >= valid[i] ) {
                max_count = counter[i];
                candidate = i;
            }
        }
        return candidate;
    }
};