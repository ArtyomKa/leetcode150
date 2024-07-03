#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        int repeat_counter = 0;
        auto reader = nums.begin()+1;
        auto writer = nums.begin()+1;
        while (reader != nums.end()) {
            if (*reader == *(reader - 1)) {
                repeat_counter += 1;
                if (repeat_counter >= 2) {
                    reader++;
                    continue;
                }
            } else {
                repeat_counter = 0;
            }
            *writer = *reader;
            writer++;
            reader++;
        }
        return writer - nums.begin();
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    std::vector input { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
    int res = sol.removeDuplicates(input);
    for (int i = 0; i < res; i++) {
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
