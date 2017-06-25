class Solution {
public:
    string originalDigits( string s ) {
        int counter[128] = { 0 };
        int num[10] = { 0 };
        string temp[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        for ( ch : s )
            counter[ch]++;
        
        num[0] = counter['z'];
        for ( ch : temp[0] )
            counter[ch] -= num[0];
            
        num[2] = counter['w'];
        for ( ch : temp[2] )
            counter[ch] -= num[2];

        num[6] = counter['x'];
        for ( ch : temp[6] )
            counter[ch] -= num[6];
                 
        num[8] = counter['g'];
        for ( ch : temp[8] )
            counter[ch] -= num[8];   
         
        num[7] = counter['s'];
        for ( ch : temp[7] )
            counter[ch] -= num[7];   

        num[5] = counter['v'];
        for ( ch : temp[5] )
            counter[ch] -= num[5];
 
        num[4] = counter['f'];
        for ( ch : temp[4] )
            counter[ch] -= num[4];  
            
        num[1] = counter['o'];
        for ( ch : temp[1] )
            counter[ch] -= num[1];
            
        num[3] = counter['t'];
        for ( ch : temp[3] )
            counter[ch] -= num[3];

        num[9] = counter['e'];
        for ( ch : temp[9] )
            counter[ch] -= num[9];
            
        string result;
        for ( char i = '0'; i <= '9'; i++ )
            for ( int j = 0; j < num[i - '0']; j++ )
                result.push_back( i );
        
        return result;
    }
};