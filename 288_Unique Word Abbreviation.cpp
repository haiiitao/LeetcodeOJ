class ValidWordAbbr {
public:
    ValidWordAbbr( vector<string> dictionary ) {
        for ( auto& i : dictionary ) {
            if ( !dict.insert( i ).second )
                continue;
                
            counter[transform( i )]++;
        }
    }
    
    bool isUnique( string word ) {
        auto it = counter.find( transform( word ) );
        if ( it == counter.end() )
            return true;
        
        return it->second == 1 && dict.count( word );
    }
    
    string transform( string& word ) {
        if ( word.size() < 3 )
            return word;
        
        return word[0] + to_string( word.size() - 2 ) + word.back();
    }
    unordered_map<string, int> counter;
    unordered_set<string> dict; 
};