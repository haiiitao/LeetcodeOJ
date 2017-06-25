class Solution {
public:
    bool isPalindrome( int x ) {
        if ( x < 0 ) 
            return false;
        
        int d = 1;
        while ( x / d >= 10 ) 
            d *= 10;
            
        for ( ; x; x = (x % d) / 10, d /= 100 ) {
            if ( x / d != x % 10 )
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome( int x ) {
        if ( x < 0 ) 
            return false;
            
        int temp = x, count = 1;
        while ( temp / 10 ) {
            count *= 10;
            temp /= 10;
        }
        while ( x ) {
            int left = x / count;
            int right = x % 10;
            if ( left != right )
                return false;
            
            x = (x % count) / 10;
            count /= 100;
        }
        return true;
    }
};