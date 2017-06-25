/**
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
 */
class Solution {
public:
    string simplifyPath( string path ) {
        stringstream ss( path );
        string temp;
        vector<string> tokens;
        while ( getline( ss, temp, '/' ) ) {
            if ( !temp.empty() && temp != "." ) {
                if ( temp != ".." )
                    tokens.push_back( temp );
                else if ( !tokens.empty() )
                    tokens.pop_back();
            }
        }
        string result;
        for ( auto& str : tokens )
            result += "/" + str;
        
        return result.empty() ? "/" : result;
    }
};