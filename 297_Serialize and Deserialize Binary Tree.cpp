class Codec {
public:

    // Encodes a tree to a single string.
    string serialize( TreeNode* root ) {
        stringstream ss;
        serialize( ss, root );
        return ss.str();
    }
    void serialize( stringstream& ss, TreeNode* root ) {
        if ( !root ) {
            ss << "#";
            return;
        }
        ss << root->val << ",";
        serialize( ss, root->left );
        ss << ",";
        serialize( ss, root->right );
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize( string data ) {
        int i = 0;
        return deserialize( data, i );
    }
    TreeNode* deserialize( string& data, int& i ) {
        if ( data[i] == '#') {
            i += 2;
            return NULL;
        }
        int num = 0, sign = 1;
        if ( data[i] == '-' ) {
            i++; sign = -1;
        }
        do {
               num = num * 10 + data[i] - '0';
        } while ( isdigit( data[++i] ) );
                
        TreeNode* ret = new TreeNode( sign * num );
        i++;
        ret->left = deserialize( data, i );
        ret->right = deserialize( data, i );
        return ret;
    }
};