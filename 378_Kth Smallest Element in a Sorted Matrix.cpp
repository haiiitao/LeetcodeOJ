class Solution
{
public:
	int kthSmallest( vector<vector<int>>& matrix, int k ) {
		int len = matrix.size();
		int l = matrix[0][0], r = matrix[len - 1][len - 1];
		while ( l < r ) {
			int mid = (l + r) / 2;
			int counter = 0;
			for ( int i = 0; i < len; i++ )
				counter += (upper_bound( matrix[i].begin(), matrix[i].end(), mid ) - matrix[i].begin());
			
			if ( counter < k )
				l = mid + 1;
			else
				r = mid;
		}
		return r;
	}
};