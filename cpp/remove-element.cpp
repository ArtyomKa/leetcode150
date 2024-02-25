#include <algorithm>
#include <cassert>
#include <charconv>
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int counter { 0 };
        auto front_iter = nums.begin();
        auto tail_iter = nums.end() - 1;
        while (front_iter <= tail_iter) {

            if (*front_iter != val) {
                std::cout << "fiter " << *front_iter;
                counter++;
            } else {
                if (*tail_iter != val) {
                    // swap
                    *front_iter = *tail_iter;
                    *tail_iter = 0;
                }
                tail_iter--;
                continue;
            }
            front_iter++;
        }

        return counter;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    // case2
    std::vector<int> nums { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val { 2 };
    int expeccted_res { 5 };
    std::vector<int> expected { 0, 1, 4, 0, 3, 0, 0, 0 };

    auto res = s.removeElement(nums, val);
    std::cout << "res: " << res << std::endl;
    for (auto& val : nums) {
        std::cout << val << ", ";
    }
    assert(res == expeccted_res);
    return 0;
}
