#include <vector>
#include <cassert>

using std::vector;

class Solution {
    std::vector<int> _memo;
public:
    bool canJump(vector<int>& nums) {
        _memo.clear();
        _memo.resize(nums.size());

        std::fill(_memo.begin(), _memo.end(), -1);
        _fill_memo(nums);
        return canJumpFrom(nums, 0);
    }
private:
    void _fill_memo(const vector<int>& nums)
    {
        for (int i = nums.size(); i >= 0; i--) {
            if (!canJumpFrom(nums, i)) break;
        }
    }
    bool canJumpFrom(const vector<int>& nums, int starting_index) {
        if (_memo[starting_index] != -1) return _memo[starting_index] == 1;
        if (nums[starting_index] >= nums.size() - starting_index -1) {
            _memo[starting_index] = 1;
            return true;
        }

        for (int i = 1; i <= nums[starting_index]; i++) {
            if (canJumpFrom(nums, starting_index + i)) {
               _memo[starting_index] = 1; 
               return true;
            }  
        }
        _memo[starting_index] = 0;
        return false;
    }
};


int main()
{
    Solution s1;
    std::vector<int> input1 {2,3,1,1,4};
    std::vector<int> input2 {3,2,1,0,4};
    std::vector<int> input3 {1,2,3};
    assert(s1.canJump(input1));
    assert(!s1.canJump(input2));
    assert(s1.canJump(input3));
}