class TwoSum {
public:
    // Add the number to an internal data structure.
    void add( int number ) {
        counter[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find( int value ) {
        for ( auto it = counter.begin(), itEnd = counter.end(); it != itEnd; it++ ) {
            const int key = it->first, gap = value - key;
            if ( key == gap && it->second > 1 )
                return true;
                
            if ( key != gap && counter.count( gap ) )
                return true;
        }
        return false;
    }
    unordered_map<int, int> counter;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
