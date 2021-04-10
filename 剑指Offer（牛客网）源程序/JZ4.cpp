class Solution {
public:
    /**
     *
     * @param pre:ǰ���������
     * @param in:�����������
     * @param preL:ǰ�������߽�
     * @param preR:ǰ������ұ߽�
     * @param inL:���������߽�
     * @param inR:��������ұ߽�
     * @return root:���ĸ��ڵ�ָ��
     */
    TreeNode* reConstructBinaryTree(vector<int>pre, vector<int>in, int preL, int preR, int inL, int inR){
        // �ݹ��������
        if(preL > preR)
            return NULL;
        // 1.��������������еĵ�һ�����ִ������ڵ�
        TreeNode* root = new TreeNode(pre[preL]);
        // 2.����������������ҵ����ڵ��λ�ã��������������������������
        // ���������䣺[inL , k - 1]
        // ���������䣺[k + 1, inR]
        int k;
        for(k = inL; k <= inR; k++){
            if(in[k] == pre[preL])
                break;
        }
        // 3.����������������������Ľڵ�����������ǰ�������������������
        // ���������䣺[preL + 1 , preL + numLeft]
        // ���������䣺[preL + numLeft + 1 , preR]
        int numLeft = k - inL;
        // 4.�ݹ���ú���������������
        root->left = reConstructBinaryTree(pre, in, preL + 1, preL + numLeft, inL, k - 1);
        root->right = reConstructBinaryTree(pre, in, preL + numLeft + 1, preR, k + 1, inR);
        return root;
    }
    /**
     *
     * @param pre:ǰ���������
     * @param in:�����������
     * @return root:���ĸ��ڵ�ָ��
     */
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        return reConstructBinaryTree(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    }
};