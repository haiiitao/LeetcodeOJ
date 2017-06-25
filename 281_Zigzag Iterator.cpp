/**
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
 */
class ZigzagIterator {
public:
    ZigzagIterator( vector<int>& s1, vector<int>& s2 ) {
        v1 = s1, v2 = s2;
        idx1 = idx2 = 0;
        len1 = v1.size(), len2 = v2.size();
    }

    int next() {
        if ( idx1 == idx2 && idx1 < len1 || idx2 == len2 ) {
            return v1[idx1++];
        } else {
            return v2[idx2++];
        }
        
    }

    bool hasNext() {
        if ( ( idx1 + idx2 ) == ( len1 + len2 ) )
            return false;
        else 
            return true;
    }
    
private:
    int idx1, idx2, len1, len2;
    vector<int> v1;
    vector<int> v2;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */