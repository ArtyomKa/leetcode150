#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices)
    {
        int max_profit = 0;
        int buy_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {

            if (prices[i] < buy_price) {
                buy_price = prices[i];
            } else {
                max_profit = std::max(max_profit, prices[i] - buy_price);
            }
        }
        return max_profit;
    }
};

int main()
{
    Solution s;
    std::vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    std::cout << s.maxProfit(prices);
    return 0;
}
