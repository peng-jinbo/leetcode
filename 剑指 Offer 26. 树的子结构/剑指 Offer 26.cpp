class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL)   return false;
        if(A->val == B->val && scan(A,B))   return true;  //是否存在满足条件的子结构,按根左右遍历
        return isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
    bool scan(TreeNode* A, TreeNode* B) {
        if(B == NULL)  return true;
        if(A == NULL)  return false;
        if(A->val != B->val)    return false;  
        return scan(A->left,B->left) && scan(A->right, B->right);    
    }
};

