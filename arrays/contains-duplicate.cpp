// https://leetcode.com/problems/contains-duplicate

#include <chrono>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicateBruteForce(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] == nums[j]) {
          return true;
        }
      }
    }

    return false;
  }

  bool containsDuplicateOptimal(vector<int> &nums) {
    unordered_set<int> set;

    for (int num : nums) {
      if (set.find(num) != set.end()) {
        return true;
      } else {
        set.insert(num);
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9};

  Solution sol;

  // brute force approach
  auto start = chrono::high_resolution_clock::now();
  bool ans = sol.containsDuplicateBruteForce(nums);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

  cout << "Brute Force -> Result: " << ans << " | Took " << duration.count()
       << " nanoseconds" << endl;

  // optimal solution
  start = chrono::high_resolution_clock::now();
  ans = sol.containsDuplicateBruteForce(nums);
  end = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

  cout << "Optimal Solution -> Result: " << ans << " | Took "
       << duration.count() << " nanoseconds" << endl;

  return 0;
}
