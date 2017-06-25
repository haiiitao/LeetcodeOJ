class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert( int val ) {
        auto it = m_mapVal2Idx.find( val );
        if ( it != m_mapVal2Idx.end() )
            return false;
            
        m_Nums.push_back( val );
        m_mapVal2Idx[val] = m_Nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove( int val ) {
        auto it = m_mapVal2Idx.find( val );
        if ( it == m_mapVal2Idx.end() )
            return false;
        
        int idx = it->second;
        m_mapVal2Idx.erase( it );
        if ( idx != m_Nums.size() - 1 ) {
            m_Nums[idx] = m_Nums.back();
            m_mapVal2Idx[m_Nums.back()] = idx;
        }
        m_Nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return m_Nums[rand() % m_Nums.size()];
    }
    vector<int> m_Nums;
    unordered_map<int, int> m_mapVal2Idx;
};