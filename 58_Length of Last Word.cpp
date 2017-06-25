/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
 */
class Solution {
public:
    int lengthOfLastWord( string str ) {
        int left, right;
        const int len = str.size();
        for ( right = len - 1; right >= 0; right-- ) {
            if ( str[right] != ' ' )
                break;
        }

        left = right;
        for ( ; left >= 0; left-- ) {
            if ( str[left] == ' ' )
                break;
        }
                
        return right - left;
    }
};

// ==> another vestion
class Solution {
public:
    int lengthOfLastWord( string str ) {
        auto first = find_if( str.rbegin(), str.rend(), ::isalpha );
        auto last = find_if_not( first, str.rend(), ::isalpha );
        
        return distance( first, last );
    }
};