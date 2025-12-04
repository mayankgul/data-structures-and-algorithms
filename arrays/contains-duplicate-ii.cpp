// https://leetcode.com/problems/contains-duplicate-ii
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  bool solve(vector<int> &nums, int k) {
    unordered_set<int> nums_set;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums_set.find(nums[i]) != nums_set.end()) {
        return true;
      }

      nums_set.insert(nums[i]);

      if (nums_set.size() > k) {
        nums_set.erase(nums[i - k]);
      }
    }

    return false;
  }
};
