/**
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
 */
class Solution {
public:
    string removeDuplicateLetters( string s ) {
        bool visited[128] = { false };
        int count[128] = { 0 };
        for ( auto ch : s ) 
            count[ch]++;
            
        string result;
        for ( auto ch : s ) {
            if ( visited[ch] && ch <= result.back() ) {
                count[ch]--;
                continue;
            } 
            while ( !result.empty() && count[result.back()] && ch < result.back() ) {
                visited[result.back()] = false;
                result.pop_back();
            }
            if ( !visited[ch] ) {
                count[ch]--;
                visited[ch] = true;
                result.push_back( ch );
            }
        }
        return result;
    }
};