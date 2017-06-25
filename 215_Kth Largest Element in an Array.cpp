/**
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
*/
class Solution {
public:
    int findKthLargest( vector<int>& nums, int k ) {
        priority_queue<int, vector<int>, greater<int>> q; //use min heap 
        for ( auto num : nums ) {
            if ( q.size() < k )
                q.push( num );
            else if ( q.top() < num ) {
                q.pop();
                q.push( num );
            }
        }
        return q.top();
    }
};
// ==> anther solution
class Solution {
public:
    int findKthLargest( vector<int>& nums, int k ) {
        auto result = nums.end() - k;
        std::nth_element( nums.begin(), result, nums.end( ) );
        return *result;
    }
};

class Solution {
public:
    int findKthLargest( vector<int>& nums, int k ) {
        const int size_n = nums.size();
        int left = 0, right = size_n;
        while ( left < right ) {
            int i = left, j = right - 1, povit = nums[left];
            while ( i <= j ) {
                while ( i <= j && nums[i] >= povit ) i++;
                while ( i <= j && nums[j] < povit ) j--;
                if ( i < j )
                    swap( nums[i++], nums[j--] );
            }
            swap(nums[left], nums[j]);
            if ( j == k - 1 ) return nums[j];
            if ( j < k - 1 ) left = j + 1;
            else right = j;
        }
    }
};

class Solution { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};