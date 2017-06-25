class MovingAverage {
public:
    /** Initialize your data structure here. */
    int window;
    double sum;
    deque<int> q;
    MovingAverage(int size) {
        window = size;
        sum = 0;
    }
    
    double next(int val) {
        q.push_back(val);
        sum += val;
        if (q.size() <= window)
            return sum / q.size();
        
        sum-=q.front();
        q.pop_front();
        return sum / window;
    }
};