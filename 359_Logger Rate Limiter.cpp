class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = m_Message2Time.find(message);
        if ( it == m_Message2Time.end() ) {
            m_Message2Time[message] = timestamp;
            return true;
        }
        int t = it->second;
        if ( timestamp - 10 >= t ) {
             it->second = timestamp;
             return true;
        }
        return false;
    }
    unordered_map<string, int> m_Message2Time;
};