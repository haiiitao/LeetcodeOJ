/**
 * Description: Design and implement a data structure for Least Recently Used (LRU) cache. 
 * It should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
 * it should invalidate the least recently used item before inserting a new item.
 */
class LRUCache {
public:
    class item {
    public:
        int key, val;
        item( int k, int v ) : key( k ), val( v ){}
    };
    
    typedef list<item> list_t;
    typedef unordered_map<int, list_t::iterator> map_t;
    
    LRUCache( int capacity ) : m_capacity( capacity ) 
    {}
    
    int get( int key ) {
        auto iter = m_mapCache.find( key );
        if ( iter == m_mapCache.end() ) 
            return -1;
            
        m_list.splice( m_list.end(), m_list, iter->second );
        iter->second = prev( m_list.end() );
        
        return iter->second->val;
    }
    
    void set( int key, int value ) {
        auto iter = m_mapCache.find( key );
        if ( iter != m_mapCache.end() ) {
            m_list.splice( m_list.end(), m_list, iter->second );
            iter->second = prev( m_list.end() );
            iter->second->val = value;
        } else {
            if ( m_mapCache.size() >= m_capacity ) {
                m_mapCache.erase( m_list.front().key );
                m_list.pop_front();
            }
            m_mapCache[key] = m_list.insert( m_list.end(), item( key, value ) );
        }
    }

private:
    map_t   m_mapCache;
    list_t  m_list;
    int     m_capacity;
};

class LRUCache {
public:
    LRUCache( int capacity ) {
        cap = capacity;
    }
    
    int get( int key ) {
        auto it = cache.find( key );
        if ( it == cache.end() )
            return -1;
        
        int ret = it->second->second;
        lru.splice( lru.begin(), lru, it->second );
        it->second = lru.begin();
        return ret;
    }
    
    void put( int key, int value ) {
        auto it = cache.find( key );
        if ( it != cache.end() ) {
            lru.splice( lru.begin(), lru, it->second );
            it->second = lru.begin();
            it->second->second = value;
        } else {
            if ( lru.size() == cap ) {
                cache.erase( lru.back().first );
                lru.pop_back();
            }
            lru.push_front( { key, value } );
            cache[key] = lru.begin();
        }
    }
    int cap;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
};