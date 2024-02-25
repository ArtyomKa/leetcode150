#include <cassert>
#include <vector>
using std::vector;
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        int uniques { 0 };
        for (auto iter = nums.cbegin() + 1; iter != nums.cend(); iter++) {
            if (nums[uniques] != *iter) {
                uniques += 1;
            }
            nums[uniques] = *iter;
        }
        return uniques + 1;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    std::vector<int> expected { 0, 1, 2, 3, 4 };
    Solution s;
    auto k = s.removeDuplicates(nums);
    assert(k == expected.size());

    for (int i = 0; i < k; i++) {
        assert(nums[i] == expected[i]);
    }
    return 0;
}
