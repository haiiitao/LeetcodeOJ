/**
 * Description: Given a string of numbers and operators, 
 * return all possible results from computing all the different possible ways to group numbers and operators. 
 * The valid operators are +, - and *.
 */
class Solution {
public:
    vector<int> diffWaysToCompute( string input ) {
        vector<int> result;
        divide( result, input, 0, input.size() );
        return result;
    }
    void divide( vector<int>& result, string& str, int start, int end ) {
        for ( int i = start; i < end; i++ ) {
            if ( str[i] == '+' || str[i] == '-' || str[i] == '*' ) {
                vector<int> tempLeft, tempRight;
                divide( tempLeft, str, start, i );
                divide( tempRight, str, i + 1, end );
                for ( auto l : tempLeft ) {
                    for ( auto r : tempRight ) {
                        if ( str[i] == '+' ) result.push_back( l + r );
                        if ( str[i] == '-' ) result.push_back( l - r );
                        if ( str[i] == '*' ) result.push_back( l * r );
                    }
                }
            }
        }
        if ( result.empty() )
            result.push_back( stoi( str.substr( start, end - start ) ) );
    }
};