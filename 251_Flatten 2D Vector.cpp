/**
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
 */
class Vector2D {
public:
    Vector2D( vector<vector<int>>& vec2d ) {
        itRow = vec2d.begin();
        itRowEnd = vec2d.end();
        while ( itRow != itRowEnd && itRow->empty() )
            itRow++; // ignore empty vector in the begining 
            
        if ( itRow != itRowEnd ) {
            itCol = itRow->begin();
            itColEnd = itRow->end();
        } 
    }

    int next() {
        int t = *itCol;
        if ( ++itCol == itColEnd ) {
            do {
                itRow++;
            } while ( itRow != itRowEnd && itRow->empty() );
            
            if ( itRow != itRowEnd ) {
                itCol = itRow->begin();
                itColEnd = itRow->end();
            }
        }
        return t;
    }

    bool hasNext() {
        return itRow != itRowEnd;
    }
    vector<vector<int>>::iterator itRow, itRowEnd;
    vector<int>::iterator itCol, itColEnd;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */