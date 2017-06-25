class Solution {
public:
    int findMin( vector<int>& nums ) {
        int l = 0, r = nums.size() - 1;
        while ( l < r ) {
            int mid = (l + r) / 2;
            if ( nums[mid] > nums[r] )
                l = mid + 1;
            else if ( nums[mid] < nums[r] )
                r = mid;
            else 
                r--;              
        }
        return nums[l];
    }
};

class Solution {
public:
    int findMin( vector<int> &num ) {
        int left = 0, right = num.size() - 1;
        while ( left < right ) {
            int mid = (left + right) / 2;
            if ( num[right] < num[mid] )
                left = mid + 1;
            else if ( num[mid] < num[right] )
                right = mid;
            else    //num[mid]==num[j]
                if ( num[left] == num[mid] ) {//linear complexity
                    left++;
                    right--;
                }
                else
                    right = mid;
            
        }
        return num[left];
    }
};