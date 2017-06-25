class Solution {
public:
    int splitArray( vector<int>& nums, int m ) {
        int lower_bound = 0; long sum = 0;
        for ( int num : nums ) {
            lower_bound = max( lower_bound, num );
            sum += num;
        }
        long l = max( (long)lower_bound, sum / m ), r = sum;
        while ( l < r ) {
            int mid = (l + r) / 2;
            if ( valid( mid, nums, m ) ) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int)l;   
    }
    
    bool valid( long target, vector<int>& nums, int m ) {
        int count = 1;
        long total = 0;
        for ( int num : nums ) {
            total += num;
            if ( total > target ) {
                total = num;
                count++;
                if ( count > m ) 
                    return false;
            }
        }
        return true;
    }
};