class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        //1.声明：数组ret存放返回结果
        vector<int> ret;
        //1.声明：栈nodes存放链表结点
        stack < ListNode * > nodes;
        //2.初始化：指针pNode指向链表头结点head
        ListNode *pNode = head;
        //3.当pNode不为空，循环执行a,b
        while (pNode != nullptr) {
            //a.将pNode压入栈中
            nodes.push(pNode);
            //b.pNode指向链表中的下一个结点
            pNode = pNode->next;
        }
        //4.当栈nodes不为空，循环执行a,b,c
        while (!nodes.empty()) {
            //a.取出栈顶元素赋值给pNode
            pNode = nodes.top();
            //b.将结点pNode的值pNode->val压入数组ret
            ret.push_back(pNode->val);
            //c.弹出栈顶元素
            nodes.pop();
        }
        //5.返回数组ret
        return ret;
    }
}