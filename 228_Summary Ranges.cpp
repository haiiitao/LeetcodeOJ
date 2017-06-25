/**
 * Description: Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */
class Solution {
public:
    vector<string> summaryRanges( vector<int>& nums ) {
        vector<string> result;
        for ( size_t i = 0, len = nums.size(); i < len; i++ ) {
            int start = nums[i];
            while ( i < len - 1 && nums[i] + 1 == nums[i + 1] )
                i++;

            stringstream ss;
            if ( start == nums[i] )
                ss << start;
            else
                ss << start << "->" << nums[i];
                
            result.push_back( ss.str() );
        }
        return result;
    }
};