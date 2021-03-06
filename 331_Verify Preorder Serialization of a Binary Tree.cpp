/**
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
 */
class Solution {
public:
    bool isValidSerialization( string preorder ) {
        int nodeCnt = 0, nullCnt = 0, pos;
        for ( int i = 0, len = preorder.size(); i < len; i = pos + 1 ) {
            pos = preorder.find( ",", i );
            if ( pos == -1 ) 
                pos = len;
                
            ( preorder.substr( i ,pos - i ) == "#" ) ? nullCnt++ : nodeCnt++;
            if ( nullCnt == nodeCnt + 1 && pos != len ) 
                return false;
        }
        return nullCnt == nodeCnt + 1;
    }
};

class Solution {
public:
 bool isValidSerialization( string s ) {
        stringstream ss;    
        ss << s;
        string token;
        stack<string> stk;
        while ( getline( ss, token, ',' ) ) {
            if ( token == "#") {
                while ( !stk.empty() && stk.top() == "#" ) {
                    stk.pop();
                    if ( stk.empty() )
                        return false;
                    
                    stk.pop();
                }
            } 
            stk.push( token );
        }
        return stk.size() == 1 && stk.top() == "#";
    }
};