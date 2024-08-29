#include <cassert>
#include <vector>

using std::vector;

class Solution {
    public:
    int jump(vector<int>& nums)
    {
        std::vector<int> _results(nums.size(), -1);
        auto nums_size = nums.size();
        _results[nums_size - 1 ] = 0;
        for (int i = nums_size-2; i >= 0; i--) {
            int curr_val = nums[i];
            int curr_min = nums_size;
            for (int j=1; j <= nums[i] && j < nums_size - i; j++) {
                if (curr_min > _results[i+j]){
                    curr_min = _results[i + j];
                }
            }
            _results[i] = curr_min + 1;
        }
        return _results[0];
    }
};

int main()
{
    Solution s1;
    std::vector<int> input1 { 2,3,0,1,4 };
    // std::vector<int> input2 { 3, 2, 1, 0, 4 };
    // std::vector<int> input3 { 1, 2, 3 };
    assert(s1.jump(input1) == 2);
    //assert(!s1.canJump(input2));
    //assert(s1.canJump(input3));
}
