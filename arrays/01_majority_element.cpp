#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*  # APPROACH 1 : SORTING -> NAIVE APPROACH

    > To start with, my initial approach would be to sort the array.

    > ​The logic is that since the majority element appears more than
    half the time, it will inevitably land in the middle index after sorting.​

    > However, while this is simple to implement, the time complexity is
    O(n \log n) due to the sorting operation, which isn't optimal.
*/
int majorityElementSorting(vector<int> nums)
{ // Pass by value
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}
/*  # APPROACH 2 : HASHMAP -> BETTER APPRAOCH
    > Moving on to a more time-efficient solution, we could use a
    Frequency Map (or Hash Map).
    > In this approach, we traverse the array once and tally the
    count of each number. As soon as an element's count exceeds n/2, we return
    > On the positive side, this gives us linear time complexity, O(n).
    But the downside is that it requires O(n) auxiliary space to store the map.
*/
int majorityElementHashmap(const vector<int> &nums)
{
    unordered_map<int, int> freq;
    int n = nums.size();
    for (int num : nums)
    {
        freq[num]++;
        if (freq[num] > n / 2)
            return num;
    }
    return -1;
}
/*  # APPROACH 3 Boyer-Moore Voting Algorithm -> OPTIMAL
    > This brings us to the most efficient solution: the Boyer-Moore Voting Algorithm.
    > ​The key insight here is that the majority element is dominant enough to survive
    cancellation against all other elements.

​-> Here is how it works:

​    > First, we maintain a count and a candidate.
​    > Then, as we iterate, we increment the count for identical numbers and decrement
      it for different ones.
    >​ Consequently, the non-majority elements cancel out, leaving us with the majority
    element.

​    Ultimately, this allows us to solve the problem in linear time,
     O(n), and—most importantly—constant space, O(1).
*/
int majorityElement(vector<int> &nums)
{

    int candidate = -1;
    int count = 0;
    for (int curr : nums)
    {
        if (count == 0)
            candidate = curr;
        count += candidate == curr ? 1 : -1;
    }
    return candidate;
    /* verification step incase of absence of Majority Element
        count = 0;
        for(int num : nums)
            if(num == candidate) count++;
        return (count > nums.size()/2) ? candidate : -1;
    */
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 2, 1, 2};

    cout << "| Majority Element : " << majorityElementSorting(nums);
    cout << "\n| Majority Element : " << majorityElementHashmap(nums);
    cout << "\n| Majority Element : " << majorityElement(nums);
    return 0;
}