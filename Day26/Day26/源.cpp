










class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        bool isblance_ = true;
        TreeDepth(pRoot, isblance_);
        return isblance_;
    }
    private:
    int TreeDepth(TreeNode* root, bool& isblance)
    {
        if(root == nullptr || isblance == false)
            return 0;
        int left = TreeDepth(root->left, isblance);
        int right = TreeDepth(root->right, isblance);
        
        int tmp = left - right > 0 ? left - right : right - left;
        
        isblance = tmp < 2 ? true : false;
        
        return max(left,right)+1;
    }
};
