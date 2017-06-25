/**
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
 */
class Solution {
public:
    int calculate( string s ) {
        s.erase( remove_if( s.begin(), s.end(), ::isspace ), s.end() );
        int result = 0, prev = 0;
        char op = '+';
        for ( size_t i = 0, len = s.size(); i < len; ) {
            if ( isdigit( s[i] ) ) {
                int tmp = 0;
                do {
                    tmp = tmp * 10 + (s[i++] - '0');
                } while ( i < len && isdigit( s[i] ) );
                switch ( op ) {
                    case '+' : prev += tmp; break;
                    case '-' : prev -= tmp; break;
                    case '*' : prev *= tmp; break;
                    case '/' : prev /= tmp; break;
                }
            } else {
                op = s[i++];
                if ( op == '+' || op == '-' ) {
                    result += prev;
                    prev = 0;
                }
            }
        }
        return result + prev;
    }
};

// mine
class Solution {
public:
    int calculate( string s ) {
        int buffer = 0, commit = 0, atom;
        char op = '+';
        for ( int i = 0; i <= s.size(); ) {
            if ( s[i] == ' ' ) {
                i++;
            } else if ( isdigit( s[i] ) ) {
                atom = 0;
                do {
                    atom = atom * 10 + (s[i] - '0');
                } while( isdigit( s[++i] ) );
            } else { // op
                switch( op ) {
                    case '+': commit += buffer; buffer = atom; break;
                    case '-': commit += buffer; buffer = -atom; break;
                    case '*': buffer *= atom; break;
                    case '/': buffer /= atom; break;
                }
                op = s[i++];
            }
        }
        return commit + buffer;
    }
};