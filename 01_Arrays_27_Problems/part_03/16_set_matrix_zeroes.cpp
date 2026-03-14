#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Check first column
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                firstColZero = true;

        // Check first row
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
                firstRowZero = true;

        // Mark rows and columns
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes based on marks
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Handle first column
        if (firstColZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;

        // Handle first row
        if (firstRowZero)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
    }
};