class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        //1.����������ret��ŷ��ؽ��
        vector<int> ret;
        //1.������ջnodes���������
        stack < ListNode * > nodes;
        //2.��ʼ����ָ��pNodeָ������ͷ���head
        ListNode *pNode = head;
        //3.��pNode��Ϊ�գ�ѭ��ִ��a,b
        while (pNode != nullptr) {
            //a.��pNodeѹ��ջ��
            nodes.push(pNode);
            //b.pNodeָ�������е���һ�����
            pNode = pNode->next;
        }
        //4.��ջnodes��Ϊ�գ�ѭ��ִ��a,b,c
        while (!nodes.empty()) {
            //a.ȡ��ջ��Ԫ�ظ�ֵ��pNode
            pNode = nodes.top();
            //b.�����pNode��ֵpNode->valѹ������ret
            ret.push_back(pNode->val);
            //c.����ջ��Ԫ��
            nodes.pop();
        }
        //5.��������ret
        return ret;
    }
}