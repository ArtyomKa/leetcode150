#include <iostream>
#include <queue>
#include <utility>
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root)
    {
        int val;
        return deep(root, 0, val);
    }

private:
    TreeNode* deep(TreeNode* root, int parent_val, int& sum)
    {
        // TreeNode* new_left = nullptr;
        // TreeNode* new_right = nullptr;
        // static int greater = 0;
        if (root->right) {
            deep(root->right, root->val, sum);
        }
        sum += root->val;
        int new_val = sum;
        if (root->left) {
            deep(root->left, root->val, sum);
        }
        // if (parent_val < root->val)
        root->val = new_val;
        return root;
    }
};

TreeNode* construct(const std::vector<int>& values)
{
    TreeNode* root = new TreeNode(values[0]);
    for (auto iter = values.begin() + 1; iter != values.end(); iter++) {
        TreeNode* parent = nullptr;
        TreeNode* node = root;
        if (*iter == -1)
            continue;
        while (node != nullptr) {
            parent = node;
            if (*iter > node->val) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        TreeNode* newNode = new TreeNode(*iter);
        if (*iter > parent->val) {
            parent->right = newNode;
        } else {
            parent->left = newNode;
        }
    }
    return root;
}
void print(TreeNode* root, bool print_root = false)
{
    static std::queue<TreeNode*> q;
    if (root != nullptr) {
        q.push(root);
    }
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node != nullptr)
            std::cout << node->val << std::endl;
        else {
            std::cout << -1 << std::endl;

            continue;
        }

        q.push(node->left);
        q.push(node->right);
    }
}
int main(int argc, const char* argv[])
{
    std::vector<int> values = { 4,
        1,
        6,
        0,
        2,
        5,
        7,
        -1,
        -1,
        -1,
        3,
        -1,
        -1,
        -1,
        8 };
    auto tree = construct(values);
    print(tree);
    Solution s;
    auto greater = s.bstToGst(tree);
    print(greater);

    return 0;
}
