/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* ret = getTree(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
        return ret;
    }
    TreeNode* getTree(vector<int>& inorder,vector<int>& postorder,int i_begin,int i_end,int p_begin, int p_end)
    {
        if(i_begin > i_end) return NULL;
        TreeNode* root = new TreeNode(postorder[p_end]);
        int val = 0;
        for(int i = i_begin; i <= i_end; i++)
        {
            if(inorder[i] == postorder[p_end]) break;
            val++;
        }
        val--;
        root->left = getTree(inorder,postorder,i_begin,i_begin+val,p_begin,p_begin+val);
        root->right = getTree(inorder,postorder,i_begin+val+2,i_end,p_begin+val+1,p_end-1);
        return root;
    }
};