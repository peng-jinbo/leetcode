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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ret = getTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        return ret;
    }
    TreeNode* getTree(vector<int>& preorder, vector<int>& inorder, int p_begin, int p_end, int i_begin, int i_end)
    {
        if(p_begin > p_end) return NULL;
        TreeNode* root = new TreeNode(preorder[p_begin]);
        int mid = i_begin;
        int count = 0;
        while(mid <= i_end)
        {
            if(inorder[mid] == preorder[p_begin]) break;
            mid++;
            count++;
        }
        root->left = getTree(preorder,inorder,p_begin+1,p_begin+count,i_begin,mid-1);
        root->right = getTree(preorder,inorder,p_begin+count+1,p_end,mid+1,i_end);
        return root;
    }
};