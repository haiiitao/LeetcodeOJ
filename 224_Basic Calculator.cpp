/**
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
 */
class Solution {
public:
    int calculate( string s ) {
        int i = 0, len = s.size();
        function<int()> evaluate = [&]() {
            int result = 0, sign = 1;
            while ( i < len && s[i] != ')' ) {
                if ( s[i] == '-' ) {
                    sign = -1;
                    i++;
                } else if ( s[i] == '+' ) {
                    sign = 1;
                    i++;
                } else if ( s[i] == ' ' ) {
                    i++;
                } else if ( s[i] == '(' ) {
                    i++;
                    result += sign * evaluate();
                } else {
                    int num = 0;
                    while ( i < len && isdigit( s[i] ) )
                        num = num * 10 + s[i++] - '0';
                        
                    result += sign * num;
                }
            }
            i++; // ignore ')'
            return result;            
        };
        return evaluate();
    }
};