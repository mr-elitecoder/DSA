#include <iostream>
#include <vector>
using namespace std;

int maxProfit(const vector<int> &prices)
{
    int minPrice = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for (int today = 1; today < n; today++)
    {
        maxProfit = max(prices[today] - minPrice, maxProfit);
        minPrice = min(prices[today], minPrice);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 96, 100};
    cout << maxProfit(prices);
    return 0;
}