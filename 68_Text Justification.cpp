/**
Given an array of words and a length L, 
format the text such that each line has exactly L characters and is fully 
(left and right) justified.

You should pack your words in a greedy approach; that is, 
pack as many words as you can in each line. Pad extra spaces ' ' 
when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and 
no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
 */
class Solution {
public:
    vector<string> fullJustify( vector<string>& words, int maxWidth ) {
        int row_size = 0, start_idx = 0;
        vector<string> result;
        for ( int i = 0, len = words.size(); i < len; i++ ) {
            row_size += words[i].size() + (i == start_idx ? 0 : 1);
            if ( row_size > maxWidth ) {
                result.push_back( transform( start_idx, i - 1, maxWidth, words ) );
                row_size = 0;
                start_idx = i;
                i = i - 1;
            }
        }
        string last_row;
        for ( int i = start_idx; i < words.size(); i++ )
            last_row += words[i] + " ";
        
        last_row.pop_back();
        last_row.append( maxWidth - last_row.size(), ' ' );
        result.push_back( last_row );
        return result;
    }
    string transform( int start, int end, int maxWidth, vector<string>& words ) {
        string result;
        if ( start == end ) {
            result = words[start];
            result.append( maxWidth - words[start].size() , ' ' );
            return result;
        }
        int word_length = 0;
        for ( int i = start; i <= end; i++ )
            word_length += words[i].size();
        
        int gap = (maxWidth - word_length) / (end - start);
        int temp = (maxWidth - word_length) % (end - start);
        for ( int i = start; i < start + temp; i++ )
            result += words[i] + string( gap + 1, ' ');
            
        for ( int i = start + temp; i <= end; i++ ) 
            result += words[i] + string( gap, ' ' );
        
        result.erase( result.size() - gap, result.size() );
        return result;
    }
};

class Solution {
public:
    vector<string> fullJustify( vector<string>& words, int maxWidth ) {
        int row_size = 0, start_idx = 0;
        vector<string> result;
        for ( int i = 0, len = words.size(); i < len; i++ ) {
            row_size += words[i].size() + (i == start_idx ? 0 : 1);
            if ( row_size > maxWidth ) {
                result.push_back( transform( start_idx, i - 1, maxWidth, words ) );
                row_size = 0;
                start_idx = i;
                i = i - 1;
            }
        }
        string last_row;
        for ( int i = start_idx; i < words.size(); i++ )
            last_row += words[i] + " ";
        
        last_row.pop_back();
        last_row.append( maxWidth - last_row.size(), ' ' );
        result.push_back( last_row );
        return result;
    }
    string transform( int start, int end, int maxWidth, vector<string>& words ) {
        string result;
        if ( start == end ) {
            result = words[start];
            result.append( maxWidth - words[start].size() , ' ' );
            return result;
        }
        int word_length = 0;
        for ( int i = start; i <= end; i++ )
            word_length += words[i].size();
        
        int gap = (maxWidth - word_length) / (end - start);
        int temp = (maxWidth - word_length) % (end - start);
        for ( int i = start; i < start + temp; i++ )
            result += words[i] + string( gap + 1, ' ');
            
        for ( int i = start + temp; i <= end; i++ ) 
            result += words[i] + string( gap, ' ' );
        
        result.erase( result.size() - gap, result.size() );
        return result;
    }
};