class Solution {
public:
    string replaceSpace(string s) {
        //1.统计原始字符串中的空格数space和字符串长度len，定义替换之后的字符串长度=len+2*space
        int space = 0, len = s.length(), new_len;
        for (char ch : s) {
            if (ch == ' ')
                ++space;
        }
        new_len = len + 2 * space;
        string ret(s);
        ret.resize(new_len);
        //2.准备两个指针 p1 和 p2。p1 指向原始字符串的末尾，p2 指向替换之后的字符串的末尾
        int p1 = len - 1, p2 = new_len - 1;
        //3.重复4-5直到 p1 和 p2 指向同一位置
        while (p1 != p2) {
            //4.向前移动p1 ，逐个将它指向的字符复制到 p2 指向的位置，直到碰到空格为止
            if (ret[p1] != ' ') {
                ret[p2] = ret[p1];
                p1--, p2--;
            }
                //5.碰到空格后，把 p1 向前移动1格，并把 p2 向前移动 3 格插入'%20'
            else {
                ret[p2] = '0', ret[p2 - 1] = '2', ret[p2 - 2] = '%';
                p1--, p2 -= 3;
            }
        }
        //6.返回替换之后的字符串
        return ret;
    }
}