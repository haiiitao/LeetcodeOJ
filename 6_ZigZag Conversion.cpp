/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
class Solution {
public:
    string convert( string s, int numRows ) {
    	const int len = s.size();
        std::string ans( len, '0' );
        char* p = &ans[0];
        int part_len = 2 * numRows - 2;
        if ( numRows == 1 || !len ) 
            return s;

        for ( int i = 0; i < numRows; ++i ) {
            if ( i == 0 || i == numRows - 1 )
                for ( int j = i; j < len; j += part_len ) 
                    *(p++) = s[j];
            else {
                int offset = 2 * i;
                for ( int j = i; j < len; offset = part_len - offset, j += offset ) 
                    *(p++) = s[j];
            }
        }
        return ans;
    }
};