/**
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
 */
class Solution {
public:
    bool isStrobogrammatic( string num ) {
        int left = 0, right = num.size() - 1;
        while ( left < right ) {
            bool b = (num[left] == '6' && num[right] == '9') ||
                 (num[left] == '9' && num[right] == '6') ||
                 (num[left] == '8' && num[right] == '8') ||
                 (num[left] == '0' && num[right] == '0') ||
                 (num[left] == '1' && num[right] == '1');
            if ( !b )
                return false;
                
            left++, right--;
        }
        return left != right || ( num[left] == '1' || num[left] == '8' || num[left] == '0' );
    }
};