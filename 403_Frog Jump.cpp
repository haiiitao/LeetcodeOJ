class Solution {
public:
    bool canCross( vector<int>& stones ) {
        unordered_set<int> pos;
        for ( auto i : stones )
            pos.insert( i );
            
        unordered_map<int, unordered_set<int>> jumps;
        jumps[0].insert( 0 );
        
        for ( auto i : stones ) {
            auto it = jumps.find( i );
            if ( it == jumps.end() ) 
                continue;
            else {
                for ( auto& x : it->second ) {
                    if ( x > 0 && pos.count( i + x ) ) jumps[i + x].insert( x );
                    if ( pos.count( i + x + 1) ) jumps[i + x + 1].insert( x + 1 );
                    if ( x - 1 > 0 && pos.count( i + x - 1 ) ) jumps[i + x - 1].insert( x - 1 );
                }
            }
        }
        return jumps.count( stones.back() );   
    }
};

class Solution {
public:
    unordered_map<int, bool> dp;
    bool canCross( vector<int>& stones, int pos = 0, int k = 0 ) {
        for ( int i = pos + 1; i < stones.size(); i++ ) {
            int gap = stones[i] - stones[pos];
            if ( gap < k - 1 ) continue;
            if ( gap > k + 1 ) break;
            if ( canCross( stones, i, gap ) ) return true;
        }
        return pos == stones.size() - 1;
    }
};

class Solution {
public:
    unordered_map<int, bool> dp;
    bool canCross( vector<int>& stones, int pos = 0, int k = 0 ) {
        int key = pos | k << 11;
        if ( dp.count(key) )
            return dp[key];
    
        for ( int i = pos + 1; i < stones.size(); i++ ) {
            int gap = stones[i] - stones[pos];
            if ( gap < k - 1 ) continue;
            if ( gap > k + 1 ) break;
            if ( canCross( stones, i, gap ) )
                return dp[key] = true;
        }
        return dp[key] = (pos == stones.size() - 1);
    }
};

class Solution {
public:
    unordered_map<int, unordered_map<int,bool>> f;
    bool canCross( vector<int>& stones, int pos = 0, int k = 0 ) {
        auto it_pos = f.find( pos );
        if ( it_pos != f.end() ) {
            auto it_k = it_pos->second.find( k );
            if ( it_k != it_pos->second.end() )
                return it_k->second;
        }
    
        for ( int i = pos + 1, len = stones.size(); i < len; i++ ) {
            int gap = stones[i] - stones[pos];
            if ( gap < k - 1 ) continue;
            if ( gap > k + 1 ) break;
            if ( canCross( stones, i, gap ) )
                return f[pos][k] = true;
        }
        return f[pos][k] = (pos == stones.size() - 1);
    }
};