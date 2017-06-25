class Solution {
public:
    bool validWordSquare( vector<string>& words ) {
        for ( size_t i = 0; i < words.size(); i++ ) {
            for ( size_t j = 0; j < words[i].size(); j++ ) {
                if ( j >= words.size() || words[j].size() <= i || words[i][j] != words[j][i])
                    return false;
            }
        }
        return true;
   }
};