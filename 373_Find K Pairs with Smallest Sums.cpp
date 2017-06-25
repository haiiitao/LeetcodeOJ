class Solution {
private:
    struct cmp {
      bool operator()( vector<int>& a, vector<int>& b ) {
          return a[0] + a[1] > b[0] + b[1]; // can't use >=
      }  
    };
public:
    vector<pair<int, int>> kSmallestPairs( vector<int>& nums1, vector<int>& nums2, int k ) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        const int len1 = nums1.size(), len2 = nums2.size();
        k = min( k, len1 * len2 );
        for ( int i = 0; i < len1 && len2; i++ )
            pq.push( { nums1[i], nums2[0], 0 } );
            
        vector<pair<int, int>> result;
        while( k-- > 0 ) {
            int a = pq.top()[0], b = pq.top()[1], c = pq.top()[2];
            pq.pop();
            result.push_back( { a, b } );
            if ( c == len2 - 1 )
                continue;
            
            pq.push( { a, nums2[c + 1], c + 1 } );    
        }
        return result;
    }
};