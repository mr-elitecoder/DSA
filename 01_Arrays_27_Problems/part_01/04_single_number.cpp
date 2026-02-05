#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> nums)
{
    int result = 0;
    for (int n : nums)
    {
        result ^= n;
    }
    return result;
}

int main()
{
    vector<int> nums = {5, 2, 5, 2, 1};
    cout << singleNumber(nums) << endl;
    return 0;
}
