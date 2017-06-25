class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        const int len = nums.size();
        vector<int> result( len, 0 ); 
        int i = a >= 0 ? len - 1 : 0;
        int left = 0, right = len - 1;
        while ( left <= right ) {
            int leftNum = transform( nums[left], a, b, c );
            int rightNum = transform( nums[right], a, b, c );
            if ( a >= 0 ) {
                leftNum <= rightNum ? right-- : left++;
                result[i--] = leftNum <= rightNum ? rightNum : leftNum;
            } else {
                leftNum <= rightNum ? left++ : right--;
                result[i++] = leftNum <= rightNum ? leftNum : rightNum;
            }
        }
        return result;
    }
    int transform( int num, int a, int b, int c ) {
        return a * num * num + b * num + c;
    }
};