class Solution {
public:
    vector<int> getModifiedArray( int length, vector<vector<int>>& updates ) {
        vector<int> result( length, 0 );
        for ( int i = 0, len = updates.size(); i < len; i++ ) {
            result[updates[i][0]] += updates[i][2];
            if ( updates[i][1] + 1 < length )
                result[updates[i][1] + 1] -= updates[i][2];
        }
        for ( int i = 1; i < length; i++ )
            result[i] += result[i - 1];
        
        return result;
    }
};