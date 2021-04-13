class Solution
{
public:
    void push(int node) {
        // ֱ�ӽ�nodeѹ��stack1
        stack1.push(node);
    }

    int pop() {
        // 1.���stack2Ϊ�գ���stack1��Ԫ�����������ѹ��stack2
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // 2.���stack2��Ϊ�գ�ֱ�ӵ���stack2ջ��Ԫ��
        int top = stack2.top();
        stack2.pop();
        // 3.����stack2��ջ��Ԫ��
        return top;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};