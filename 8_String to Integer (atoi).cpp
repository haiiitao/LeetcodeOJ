class Solution {
public:
    int myAtoi( string str ) {
        int result = 0, sign = 1, i = 0, len = str.size();
        for ( ; i < len && str[i] == ' '; i++ )
            ;

        if ( str[i] == '+' ) {
            i++;
        } else if ( str[i] == '-' ) {
            i++;
            sign = -1;
        }
        
        for ( ; i < len && ::isdigit( str[i] ); i++ ) {
            if ( result > INT_MAX / 10 || result == INT_MAX / 10 && INT_MAX % 10 < ( str[i] - '0' ) )
                return sign == -1 ? INT_MIN : INT_MAX;
                
            result = result * 10 + (str[i] - '0');
        }
        return result * sign;
    }
};