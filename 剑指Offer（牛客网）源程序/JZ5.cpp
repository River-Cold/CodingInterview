class Solution
{
public:
    void push(int node) {
        // 直接将node压入stack1
        stack1.push(node);
    }

    int pop() {
        // 1.如果stack2为空，将stack1的元素逐个弹出并压入stack2
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // 2.如果stack2不为空，直接弹出stack2栈顶元素
        int top = stack2.top();
        stack2.pop();
        // 3.返回stack2的栈顶元素
        return top;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};