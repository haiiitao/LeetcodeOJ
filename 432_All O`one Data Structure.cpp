class AllOne {
public:
    struct Row {
        unordered_set<string> strs;
        int val;
        Row( const string& s, int x ) : val( x ) {
            strs.insert( s );
        }
    };

    unordered_map<string, list<Row>::iterator> strmap;
    list<Row> matrix;

    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc( string key ) {
        auto found = strmap.find( key );
        if ( found == strmap.end() ) {
            if ( matrix.empty() || matrix.back().val != 1 ) {
                matrix.push_back( Row( key, 1 ) );
                strmap[key] = prev( matrix.end() );
            } else {
                auto newrow = prev( matrix.end() );
                newrow->strs.insert( key );
                strmap[key] = newrow;
            }
        } else {
            auto row = found->second;
            auto lastrow = row;
            --lastrow;
            if ( lastrow == matrix.end() || lastrow->val != row->val + 1 ) {
                found->second =  matrix.emplace( row, key, row->val + 1 );
            } else {
                lastrow->strs.insert( key );
                found->second = lastrow;
            }
            row->strs.erase( key );
            if ( row->strs.empty() ) 
                matrix.erase( row );
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec( string key ) {
        auto found = strmap.find( key );
        if ( found == strmap.end() ) {
            return;
        } else {
            auto row = found->second;
            if ( row->val == 1 ) {
                row->strs.erase( key );
                if ( row->strs.empty() ) 
                    matrix.erase( row );
                    
                strmap.erase( key );
                return;
            }
            auto nextrow = row;
            ++nextrow;
            if ( nextrow == matrix.end() || nextrow->val != row->val - 1 ) {
                found->second = matrix.emplace( nextrow, key, row->val - 1 );
            } else {
                nextrow->strs.insert( key );
                found->second = nextrow;
            }
            row->strs.erase( key );
            if ( row->strs.empty() ) 
                matrix.erase( row );
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return matrix.empty() ?  "" : *(matrix.front().strs.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return matrix.empty() ?  "" : *(matrix.back().strs.begin());
    }
};