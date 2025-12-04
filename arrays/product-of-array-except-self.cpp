// https://leetcode.com/problems/product-of-array-except-self

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> solve(vector<int> &nums) {
    vector<int> answer(nums.size(), 1);
    int prefix = 1;
    int suffix = 1;

    answer[0] = prefix;
    for (int i = 1; i < nums.size(); ++i) {
      prefix *= nums[i - 1];
      answer[i] = prefix;
    }

    answer[nums.size() - 1] *= suffix;
    for (int i = nums.size() - 2; i >= 0; --i) {
      suffix *= nums[i + 1];
      answer[i] *= suffix;
    }

    return answer;
  }
};
