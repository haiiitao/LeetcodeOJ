class Solution {
public:
    bool PredictTheWinner( vector<int>& nums ) {
        const int len = nums.size();
        vector<vector<int>> f( len, vector<int>( len, 0 ) ); // use to keep the score gap between player1 and player2
        for ( int i = 0; i < len; i++ ) 
            f[i][i] = nums[i];
            
        for ( int i = 1; i < len; i++ ) {
            for ( int j = 0; j + i < len; j++ ) {
                f[j][j + i] = max( nums[j + i] - f[j][j + i - 1], nums[j] - f[j + 1][j + i] );
            }
        }
        return f[0][len - 1] >= 0; // player1 get more score points than player2
    }
};