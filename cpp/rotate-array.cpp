#include <iostream>
#include <vector>
class Solution {
public:
    void rotate(std::vector<int>& nums, int k)
    {
        int size = nums.size();
        auto new_index = [k, size](int i) { return (i + k) % size; };
        std::vector<int> tail(nums.end() - k, nums.end());
        for (int i = size - 1; i >= 0; i--) {
            // nums[new_index(i)] = nums[i];
            if (i < k) {
                nums[i] = tail[i];
                continue;
            }

            nums[i] = nums[i - k];
        }
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
