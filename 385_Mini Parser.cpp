class Solution {
public:
    NestedInteger deserialize( string s ) {
        int pos = 0;
        return deserialize( s, pos ).getList()[0];
    }
    
private:
    NestedInteger deserialize( string& s, int& i ) {
        int sign = 1;
        NestedInteger list;
        for ( int len = s.size(); i < len; ) {
            if ( s[i] == ',') {
                i++;
                continue;
            } else if ( s[i] == '-' ) {
                i++;
                sign = -1;
                continue;
            } else if ( isdigit( s[i] ) ) {
                int num = 0;
                do {
                    num = num * 10 + (s[i] - '0');
                    i++;
                } while( isdigit( s[i] ) );
                list.add( NestedInteger( sign * num ) );
                sign = 1;
            } else if ( s[i] == '[' ) {
                i++;
                list.add( deserialize( s, i ) );
            } else 
                break;
        }
        i++;
        return list;
    }
};