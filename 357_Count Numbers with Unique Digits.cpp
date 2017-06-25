class Solution {
public:
    int countNumbersWithUniqueDigits( int n ) {
        int sum = 1, prev;
        for ( int i = 1; i <= n; i++ ) {
            prev = i == 1 ? 9 : prev * (11 - i);
            sum += prev;
        }
        return sum;
    }
};