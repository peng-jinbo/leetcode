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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ret = getTree(nums,0,nums.size()-1);
        return ret;
    }
    TreeNode* getTree(vector<int>& nums, int begin, int end)
    {
        if(begin > end) return NULL;
        int mid = (begin+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = getTree(nums,begin,mid-1);
        root->right = getTree(nums, mid+1,end);
        return root;
    }
};