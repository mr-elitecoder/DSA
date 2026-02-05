#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    static vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid);
};

vector<int> Solution::findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> ans;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            freq[grid[i][j]]++;
            if (freq[grid[i][j]] == 2)
                ans.push_back(grid[i][j]);
        }

    for (int i = 1; i <= n * n; i++)
    {
        if (!freq.count(i))
        {
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 5},
        {2, 4, 5},
        {7, 9, 8}};
    vector<int> res = Solution::findMissingAndRepeatedValues(grid);
    cout << "[ " << res[0] << " " << res[1] << " ]";
    return 0;
}