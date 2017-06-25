/**
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */
class WordDistance {
public:
    WordDistance( vector<string>& words ) {
        for ( int i = 0, len = words.size(); i < len; i++ )
            map_Word2Idx[words[i]].push_back( i );
    }
    
    int shortest( string word1, string word2 ) {
        int i  =0, j = 0, result = INT_MAX;
        vector<int>& vec1 = map_Word2Idx[word1];
        vector<int>& vec2 = map_Word2Idx[word2];
        const int len1 = vec1.size(), len2 = vec2.size();
        while ( i < len1 && j < len2 ) { 
            result = min( result, abs( vec1[i] - vec2[j] ) );
            (vec1[i] < vec2[j]) ? i++ : j++;
        }
        return result;
    }
    
private:
    unordered_map<string, vector<int>> map_Word2Idx;
};

// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");