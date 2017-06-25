class Solution {
public:
    vector<vector<int> > zigzagLevelOrder( TreeNode* root ) {
        vector<vector<int> > result;
        if ( !root ) 
            return result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push( root );
        bool leftToRight = true;

        while ( !nodesQueue.empty()) {
            int len = nodesQueue.size();
            vector<int> row( len );
            for (int i = 0; i < len; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
    
                int index = leftToRight ? i : (len - 1 - i);
                row[index] = node->val;
                if ( node->left ) nodesQueue.push( node->left );
                if ( node->right ) nodesQueue.push( node->right );
            }
            // after this level
            leftToRight = !leftToRight;
            result.push_back( row );
        }
        return result;
    }
};