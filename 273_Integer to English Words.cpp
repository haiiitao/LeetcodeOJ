class Solution {
public:
    const vector<string> digitToStr = { "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine" };
    const vector<string> teensToStr = { " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
    const vector<string> tysToStr = { "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety" };
    
    string readThousand( int num ) {
        stringstream ss;
        if ( num >= 100 ) 
            ss << digitToStr[num / 100] << " Hundred";
        
        int tens = (num % 100) / 10;
        num %= 10;
        if ( tens == 1 ) {
            ss << teensToStr[num]; 
            return ss.str(); 
        }
        ss << tysToStr[tens] << digitToStr[num];
        return ss.str();
    }

    string numberToWords( int num ) {
        string result;
        const static vector<string> thous = { "", " Thousand", " Million", " Billion" };
        for ( int i = 0; i < 4 && num; i++, num /= 1000 ) {
            int mod = num % 1000;
            if ( mod ) 
                result = readThousand( mod ) + thous[i] + result;
        }
        if ( result.empty() ) 
            return "Zero";
    
        return result.substr( 1 );
    }
};