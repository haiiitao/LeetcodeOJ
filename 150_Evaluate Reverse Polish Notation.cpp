/**
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
class Solution {
public:
    int evalRPN( vector<string>& tokens ) {
        string str_Last = tokens.back(); 
        tokens.pop_back();
        if ( is_operator( str_Last ) ) {
            int y = evalRPN( tokens );
            int x = evalRPN( tokens );
            switch ( str_Last[0] ) {
                case '+' : return x + y;
                case '-' : return x - y;
                case '*' : return x * y;
                default :  return x / y;
            }
        } else {
            return stoi( str_Last );
        }
    }
private:
    bool is_operator( string& str ) {
        return string( "+-*/" ).find( str ) != string::npos;
    }
};

//==> another version: iterative
class Solution {
public:
    int evalRPN( vector<string>& tokens ) {
        stack<int> stk;
        for ( auto& str : tokens ) {
            if ( !is_operator( str ) ) 
                stk.push( stoi( str ) );
            else {
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                switch ( str[0] ) {
                    case '+' : x += y; break;
                    case '-' : x -= y; break;
                    case '*' : x *= y; break;
                    case '/' : x /= y; break;
                }
                stk.push( x );
            }
        } 
        return stk.top();
    }
private:
    bool is_operator( string& str ) {
        return string( "+-*/" ).find( str ) != string::npos;
    }
};