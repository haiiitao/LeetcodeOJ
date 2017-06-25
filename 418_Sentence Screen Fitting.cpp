class Solution {
public:
    int wordsTyping( vector<string>& sentence, int rows, int cols ) {
        stringstream ss;
        for ( auto& s : sentence )
            ss << s << " ";
        
        string temp = ss.str();
        int start = 0, sentenceLen = temp.size();
        int jump[sentenceLen]  = { 0 };
        for ( int i = 1; i < sentenceLen; i++ )
            jump[i] = temp[i] == ' ' ? 1 : jump[i - 1] - 1;
        
        for ( int i = 0; i < rows; i++ ) {
            start += cols;
            start += jump[start % sentenceLen];
        }
        return start / sentenceLen;
    }
};