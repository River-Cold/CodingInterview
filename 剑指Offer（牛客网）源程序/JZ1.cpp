class Solution {
    bool Find(int target, vector <vector<int>> array) {
        int r = array.size(), c = array[0].size();
        int i = 0, j = c - 1;

        while (i < r && j >= 0) {
            int x = array[i][j];
            if (x == target) {
                return true;
            } else if (x > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
}