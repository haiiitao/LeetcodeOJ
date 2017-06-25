class Solution {
public:
    vector<int> findAnagrams( string s, string p ) {
        int f[128] = { 0 }, lenp = p.size(), lens = s.size();
        for ( auto ch : p )
            f[ch]++;
        
        vector<int> result;
        for ( int i = 0, j = 0; j < lens; ) {
            f[s[j]]--;
            while ( i <= j && f[s[j]] < 0 )
                f[s[i++]]++;
            
            if ( ++j - i == lenp )
                result.push_back(i);
        }
        return result;
    }
};