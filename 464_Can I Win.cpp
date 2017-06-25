class Solution {
public:
    bool canIWin( int maxChoosableInteger, int desiredTotal ) {
        if ( maxChoosableInteger >= desiredTotal )
            return true;
            
        if ( maxChoosableInteger * ( maxChoosableInteger + 1) / 2 < desiredTotal )
            return false;
        
        unordered_map<int, bool> cache;
        return canIWin( desiredTotal, cache, 0, maxChoosableInteger );
    }
    
    bool canIWin( int target, unordered_map<int, bool>& cache, int state, int maxChoosableInteger ) {
        auto it = cache.find( state );
        if ( it != cache.end() )
            return it->second;
        
        bool& result = cache[state];
        for ( int i = 1; i <= maxChoosableInteger; i++ ) {
            int b = state & (1 << i);
            if ( b )
                continue;
            
            if ( i >= target || !canIWin( target - i, cache, state + (1 << i), maxChoosableInteger ) )
                return result = true;
        }
        return result = false;
    }
};