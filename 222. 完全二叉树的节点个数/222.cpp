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
    int countNodes(TreeNode* root) {
        int depth = get_depth(root);
        if(depth == 0) return 0;
        if(depth == 1) return 1;
        int begin = pow(2,depth-1);
        int end = pow(2,depth)-1;
        int record = end;
        while(begin<end)
        {
            int mid = (begin+end)/2;
            if(is_exist(root,mid,depth)) 
            {
                begin = mid+1;
            }
            else end = mid;
        }
        return is_exist(root,begin,depth)?begin:begin-1;
    }
    int get_depth(TreeNode* root)
    {
        int res = 0;
        while(root!=NULL)
        {
            res++;
            root=root->left;
        }
        return res;
    }
    bool is_exist(TreeNode* root, int num, int depth)
    {
        int bits = 1<<(depth-2);
        TreeNode* node = root;
        while(node!=NULL && bits>0)
        {
            if(!(bits & num))
            {
                node = node->left;
            }
            else node = node->right;
            bits = bits >> 1;
        }
        return node != NULL;
    }
};