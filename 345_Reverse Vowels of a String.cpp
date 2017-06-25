/**
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
 */
class Solution {
public:
    string reverseVowels( string s ) {
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        stack<char> stk;
        for ( auto c : s  ) {
            if ( vowels.count( c ) )
                stk.push( c );
        }

        for ( auto& c : s ) {
            if ( vowels.count( c ) ) {
                c = stk.top();
                stk.pop();
            }
        }
        return s;
    }
};