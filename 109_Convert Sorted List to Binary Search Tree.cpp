class Solution {
public:
    TreeNode* generate( ListNode*& head, int n ){
        if ( n == 0 )
            return NULL;
            
        TreeNode *t = new TreeNode( 0 );
        t->left = generate( head, n / 2 );
        t->val = head->val;
        head = head->next;
        t->right = generate( head, n - n / 2 - 1 );
        return t;
    }
    
    TreeNode *sortedListToBST( ListNode* head ) {
        ListNode* t = head;
        int count = 0;
        while ( t ) {
            ++count;
            t = t->next;
        }
        return generate( head, count );
    }
};