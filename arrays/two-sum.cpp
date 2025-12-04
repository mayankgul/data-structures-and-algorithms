// https://leetcode.com/problems/two-sum
#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSumBruteForce(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > target) {
        continue;
      } else {
        for (int j = i + 1; j < nums.size(); ++j) {
          if (nums[i] + nums[j] == target) {
            return {i, j};
          }
        }
      }
    }

    return {};
  }

  vector<int> twoSumBetterApproach(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start != end) {
      int sum = nums[start] + nums[end];

      if (sum == target) {
        return {start, end};
      } else if (sum > target) {
        end = end - 1;
      } else {
        start = start + 1;
      }
    }

    return {};
  }

  vector<int> twoSumOptimal(vector<int> &nums, int target) {
    unordered_map<int, int> rems;

    for (int i = 0; i < nums.size(); ++i) {
      int rem = target - nums[i];
      if (rems.find(rem) == rems.end()) {
        rems.insert({nums[i], i});
      } else {
        return {i, rems.at(rem)};
      }
    }

    return {};
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {2, 15, 11, 7};
  int target = 9;

  Solution sol;

  // brute force approach
  auto start = chrono::high_resolution_clock::now();
  vector<int> ans = sol.twoSumBruteForce(nums, target);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

  cout << "Time taken by brute force approach: " << duration.count()
       << " nanoseconds" << endl;

  // better approach
  start = chrono::high_resolution_clock::now();
  sort(nums.begin(), nums.end());
  ans = sol.twoSumBetterApproach(nums, target);
  end = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

  cout << "Time taken by better approach: " << duration.count()
       << " nanoseconds" << endl;

  // optimal solution
  start = chrono::high_resolution_clock::now();
  ans = sol.twoSumOptimal(nums, target);
  end = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

  cout << "Time taken by optimal solution: " << duration.count()
       << " nanoseconds" << endl;

  return 0;
}
