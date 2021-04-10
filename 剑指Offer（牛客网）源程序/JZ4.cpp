class Solution {
public:
    /**
     *
     * @param pre:前序遍历序列
     * @param in:中序遍历序列
     * @param preL:前序遍历左边界
     * @param preR:前序遍历右边界
     * @param inL:中序遍历左边界
     * @param inR:中序遍历右边界
     * @return root:树的根节点指针
     */
    TreeNode* reConstructBinaryTree(vector<int>pre, vector<int>in, int preL, int preR, int inL, int inR){
        // 递归结束条件
        if(preL > preR)
            return NULL;
        // 1.根据先序遍历序列的第一个数字创建根节点
        TreeNode* root = new TreeNode(pre[preL]);
        // 2.在中序遍历序列中找到根节点的位置，划分中序遍历的左右子树序列
        // 左子树区间：[inL , k - 1]
        // 右子树区间：[k + 1, inR]
        int k;
        for(k = inL; k <= inR; k++){
            if(in[k] == pre[preL])
                break;
        }
        // 3.根据中序遍历的左右子树的节点数量，划分前序遍历的左右子树序列
        // 左子树区间：[preL + 1 , preL + numLeft]
        // 右子树区间：[preL + numLeft + 1 , preR]
        int numLeft = k - inL;
        // 4.递归调用函数构建左右子树
        root->left = reConstructBinaryTree(pre, in, preL + 1, preL + numLeft, inL, k - 1);
        root->right = reConstructBinaryTree(pre, in, preL + numLeft + 1, preR, k + 1, inR);
        return root;
    }
    /**
     *
     * @param pre:前序遍历序列
     * @param in:中序遍历序列
     * @return root:树的根节点指针
     */
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        return reConstructBinaryTree(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    }
};