class NumMatrix {
public:

    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        prefix = matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 1; i < n; i++) {
            prefix[i][0] = prefix[i - 1][0] + matrix[i][0];
        }

        for (int i = 1; i < m; i++) {
            prefix[0][i] = prefix[0][i - 1] + matrix[0][i];
        }


        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = prefix[row2][col2];
        if (row1 != 0) {
            sum -= prefix[row1 - 1][col2];
        }
        if (col1 != 0) {
            sum -= prefix[row2][col1 - 1];
        }
        if (row1 != 0 && col1 != 0) {
            sum += prefix[row1 - 1][col1 - 1];
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */