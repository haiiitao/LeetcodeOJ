class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert( int val ) {
        auto it = m_mapVal2Idx.find( val );
        m_Nums.push_back( val );
        m_mapVal2Idx[val].insert( m_Nums.size() - 1 );
        return it == m_mapVal2Idx.end();
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove( int val ) {
        auto it = m_mapVal2Idx.find( val );
        if ( it == m_mapVal2Idx.end() )
            return false;
        
        int idx = *it->second.begin();
        it->second.erase( it->second.begin() );
        if ( idx != m_Nums.size() - 1 ) {
            m_Nums[idx] = m_Nums.back();
            m_mapVal2Idx[m_Nums.back()].erase( m_Nums.size() - 1 );
            m_mapVal2Idx[m_Nums.back()].insert( idx );
        }
        if ( it->second.empty() )
            m_mapVal2Idx.erase( it );
                
        m_Nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return m_Nums[rand() % m_Nums.size()];
    }
    vector<int> m_Nums;
    unordered_map<int, unordered_set<int>> m_mapVal2Idx;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */