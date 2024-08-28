#include <iostream>
#include <vector>
class Solution {
public:
    void rotate(std::vector<int>& nums, int k)
    {
        int actual_k = k % nums.size();
        if (actual_k == nums.size()) return;
        std::vector<int> overflow(actual_k);
        std::copy(nums.end() - actual_k, nums.end(), overflow.begin());
        std::copy_backward(nums.begin(), nums.end() - actual_k, nums.end());
        std::copy(overflow.begin(), overflow.end(), nums.begin());
    }
};
//[5,6,7,1,2,3,4]
int main(int argc, const char* argv[])
{
    Solution solution;
    std::vector<int> input { 1, 2, 3, 4, 5, 6, 7 };
    solution.rotate(input, 3);
    for (auto& val : input) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
