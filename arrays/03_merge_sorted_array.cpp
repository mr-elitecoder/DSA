#include <iostream>
#include <vector>
using namespace std;
void mergeSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int ptr1 = m - 1;
    int ptr2 = n - 1;
    int vLastIdx = m + n - 1;

    while (ptr2 >= 0)
    {
        if (ptr1 >= 0 && nums1[ptr1] > nums2[ptr2])
        {
            nums1[vLastIdx--] = nums1[ptr1--];
        }
        else
        {
            nums1[vLastIdx--] = nums2[ptr2--];
        }
    }
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    mergeSortedArray(nums1, 3, nums2, 3);
    for (int n : nums1)
        cout << n << " ";
    return 0;
}