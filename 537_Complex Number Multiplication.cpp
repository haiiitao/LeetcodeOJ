class Solution {
public:
    string complexNumberMultiply( string a, string b ) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa( a ), bb( b );
        aa >> ra >> buff >> ia;
        bb >> rb >> buff >> ib;
        string ans = to_string( ra * rb - ia * ib ) + "+";
        ans += to_string( ra * ib + rb * ia ) + "i";
        return ans;
    }
};