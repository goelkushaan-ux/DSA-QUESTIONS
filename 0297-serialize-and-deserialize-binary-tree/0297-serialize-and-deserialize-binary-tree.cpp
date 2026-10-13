/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                s += "NULL,";
                continue;
            }
            s += to_string(temp->val) + ',';
            q.push(temp->left);
            q.push(temp->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        if (str == "NULL")
            return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (getline(ss, str, ',')) {
                if (str != "NULL") {
                    curr->left = new TreeNode(stoi(str));
                    q.push(curr->left);
                }
            }
            if (getline(ss, str, ',')) {
                if (str != "NULL") {
                    curr->right = new TreeNode(stoi(str));
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));