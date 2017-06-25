class Solution {
public:
    int lengthLongestPath( string input ) {
        int level[100] = { 0 };
        int result = 0;
        for ( int i = 0; i < input.size(); i++ ) {
            int depth = 1;
            while ( i < input.size() && input[i] == '\t' ) {
                depth++;
                i++;
            }
            bool isFile = false;
            int count = 0;
            while ( i < input.size() && input[i] != '\n' ) {
                count++;
                i++;
                if ( input[i] == '.' )
                    isFile = true;
            }
            if ( !isFile )
                level[depth] = level[depth - 1] + count + 1;
            else
                result = max( result, level[depth - 1] + count );
        } 
        return result;
    }
};