/**
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
 */
class Solution {
public:
    bool isNumber( string s ) {
        if ( s.empty() ) 
            return false;
            
        int i = 0, len = s.size(), count_point = 0, count_num = 0;
        while ( i < len && s[i] == ' ' ) 
            i++;
            
        if ( i < len && (s[i] == '+' || s[i] == '-' ) ) 
            i++;
            
        while ( i < len && (::isdigit( s[i] ) || s[i] == '.' ) )
            s[i++] == '.' ? ++count_point : ++count_num;
            
        if ( count_point > 1 || count_num < 1 ) 
            return false;
        
        if ( i < len && (s[i] == 'e' || s[i] == 'E') ) {
            i++;
            if ( i < len && (s[i] == '+' || s[i] == '-' ) ) 
                i++;
                
            count_num = 0;
            while ( i < len && ::isdigit( s[i] ) ) {
                i++;
                count_num++;
            }
            if ( !count_num ) 
                return false;
        }
        
        while ( i < len && s[i] == ' ' ) 
            i++;
            
        return i == len;
    }
};