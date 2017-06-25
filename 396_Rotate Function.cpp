class Solution {
public:
    int maxRotateFunction( vector<int>& A ) {
        int sum = 0, f = 0, len = A.size();
        for ( int i = 0; i < len; i++ ) {
            sum += A[i];
            f += i * A[i];
        }
        int result = f;
        for ( int i = len - 1; i >= 1; i-- ) {
            f += sum - len * A[i];
            result = max( result, f );
        }
        return result;
    }
};