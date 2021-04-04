class Solution {
public:
    string replaceSpace(string s) {
        //1.ͳ��ԭʼ�ַ����еĿո���space���ַ�������len�������滻֮����ַ�������=len+2*space
        int space = 0, len = s.length(), new_len;
        for (char ch : s) {
            if (ch == ' ')
                ++space;
        }
        new_len = len + 2 * space;
        string ret(s);
        ret.resize(new_len);
        //2.׼������ָ�� p1 �� p2��p1 ָ��ԭʼ�ַ�����ĩβ��p2 ָ���滻֮����ַ�����ĩβ
        int p1 = len - 1, p2 = new_len - 1;
        //3.�ظ�4-5ֱ�� p1 �� p2 ָ��ͬһλ��
        while (p1 != p2) {
            //4.��ǰ�ƶ�p1 ���������ָ����ַ����Ƶ� p2 ָ���λ�ã�ֱ�������ո�Ϊֹ
            if (ret[p1] != ' ') {
                ret[p2] = ret[p1];
                p1--, p2--;
            }
                //5.�����ո�󣬰� p1 ��ǰ�ƶ�1�񣬲��� p2 ��ǰ�ƶ� 3 �����'%20'
            else {
                ret[p2] = '0', ret[p2 - 1] = '2', ret[p2 - 2] = '%';
                p1--, p2 -= 3;
            }
        }
        //6.�����滻֮����ַ���
        return ret;
    }
}