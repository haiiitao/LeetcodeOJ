class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if ( nums.empty() )
            return { -1, -1 };
        return vector<int> { lower_bound( nums, target ), upper_bound( nums, target ) };
    }
    
private:
    int lower_bound( vector<int>& nums, int target ) {
        int left = 0, right = nums.size() - 1;
        while ( left < right ) {
            int mid = (left + right) / 2;
            if ( nums[mid] < target )
                left = ++mid;
            else
                right = mid;
        }
        return nums[left] == target ? left : -1;
    }
    
    int upper_bound( vector<int>& nums, int target ) {
        int left = 0, right = nums.size() - 1;
        while ( left < right ){
            int mid = (left + right + 1) / 2;
            if ( nums[mid] > target )
                right = --mid;
            else
                left = mid;
        }
        return nums[left] == target ? left : -1;
    }
};
