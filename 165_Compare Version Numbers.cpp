/**
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        for ( auto& w : version1 ) if ( w == '.' ) w=' ';
        for ( auto& w : version2 ) if ( w == '.' ) w=' ';
        istringstream s1( version1 ), s2( version2 );
        while ( 1 ) {
            int n1, n2;
            if ( !(s1 >> n1) ) n1 = 0;
            if ( !(s2 >> n2) ) n2 = 0;
            if ( !s1 && !s2 ) return 0;
            if ( n1 < n2 ) return -1;
            if ( n1 > n2 ) return 1;
        }
        return 0;
    }
};

class Solution {
public:
    int compareVersion( string strVersion1, string strVersion2 ) {
        vector<int> vecVersion1, vecVersion2;
        extract( vecVersion1, strVersion1 );
        extract( vecVersion2, strVersion2 );
        
        const int len1 = vecVersion1.size(), len2 = vecVersion2.size();
        int len = len1 > len2 ? len1 : len2;
        for ( size_t i = 0; i < len - len1; i++ ) vecVersion1.push_back( 0 );
        for ( size_t i = 0; i < len - len2; i++ ) vecVersion2.push_back( 0 );

        for ( size_t i = 0; i < len; i++ ) {
            if ( vecVersion1[i] == vecVersion2[i] ) 
                continue;
                
            return ( vecVersion1[i] > vecVersion2[i] ) ? 1 : -1;
        }
        return 0;
    }
    
private:
    void extract( vector<int>& vecVersion, string& strVersion ) {
        stringstream ss( strVersion );
        string temp;
        while ( getline( ss, temp, '.' ) ) 
            vecVersion.push_back( atoi( temp.c_str() ) );
    }
};;