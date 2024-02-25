#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int final_idx = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (final_idx >= i && j >= 0) {
            if (i < 0 || nums2[j] >= nums1[i]) {
                nums1[final_idx] = nums2[j];
                j--;
            } else {
                nums1[final_idx] = nums1[i];
                i--;
            }
            final_idx--;
        }
    }
};

int main(int argc, char* argv[])
{

    std::vector<int> nums1 { 1, 2, 3, 0, 0, 0 };
    std::vector<int> nums2 { 2, 5, 6 };
    int m { 3 }, n { 3 };
    vector<int> expected { 1, 2, 2, 3, 5, 6 };

    // std::vector<int> nums1 {0};
    // std::vector<int> nums2 {1};
    // int m {0}, n {1};
    Solution s;
    s.merge(nums1, m, nums2, n);
    // vector<int> expected {1};

    assert(std::equal(nums1.cbegin(), nums1.cend(), expected.cbegin()));

    return 0;
}
