/**
Median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
 */
class MedianFinder {
private:
    priority_queue<int> maxQ; // max_heap for the first half
    priority_queue<int, vector<int>, ::greater<int> > minQ; // min_heap for the second half

public:
    // Adds a number into the data structure.
    void addNum( int num ) {
        if ( maxQ.empty() || maxQ.top() > num ) 
            maxQ.push( num ); // if it belongs to the smaller half
        else 
            minQ.push( num ); 

        // rebalance the two halfs to make sure the length difference is no larger than 1
        if ( maxQ.size() > minQ.size() + 1 ) {
            minQ.push( maxQ.top() );
            maxQ.pop();
        } else if ( maxQ.size() + 1 < minQ.size() ) {
            maxQ.push( minQ.top() );
            minQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if ( maxQ.size() == minQ.size() ) 
            return maxQ.empty() ? 0 : (maxQ.top() + minQ.top()) / 2.0;
        else 
            return maxQ.size() > minQ.size() ? maxQ.top() : minQ.top(); 
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum( int num ) {
        if ( minQ.size() == maxQ.size() ) {
            minQ.push( num );
        } else if ( minQ.size() > maxQ.size() )
            maxQ.push( num );
        
        if ( !minQ.empty() && !maxQ.empty() && minQ.top() < maxQ.top() ) {
            minQ.push( maxQ.top() );
            maxQ.push( minQ.top() );
            minQ.pop(); 
            maxQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if ( minQ.size() > maxQ.size() )
            return minQ.top();
            
        return (minQ.top() + maxQ.top()) / 2.0;
    }
    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int, vector<int>, less<int>> maxQ;
};