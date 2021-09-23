class Solution {
public:

    int histogram(vector<int>&arr) {

        stack<pair<int, int>> st;

        int n = arr.size();

        vector<int> left(n, -1);
        vector<int> right(n, n);


        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first > arr[i]) {
                right[st.top().second] = i;
                st.pop();
            }
            st.push({arr[i], i});
        }

        while (!st.empty()) {
            right[st.top().second] = n;
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first > arr[i]) {
                left[st.top().second] = i;
                st.pop();
            }
            st.push({arr[i], i});
        }

        while (!st.empty()) {
            left[st.top().second] = -1;
            st.pop();
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int h = arr[i];
            int w = right[i] - left[i] - 1;
            ans = max(ans, h * w);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> arr(col);
        for (int i = 0; i < col; i++) {
            arr[i] = (matrix[0][i] - '0');
        }

        int ans = histogram(arr);
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i - 1][j] == '0' || matrix[i][j] == '0') {
                    arr[j] = (matrix[i][j] - '0');
                }
                else {
                    arr[j] += (matrix[i - 1][j] - '0');
                }
            }
            ans = max(ans, histogram(arr));
        }

        return ans;
    }
};