// https://leetcode.com/problems/longest-consecutive-sequence

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int solve(vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }

    unordered_set<int> set;
    for (int n : nums) {
      set.insert(n);
    }

    int lcs = 1;
    int common_seq = 1;

    for (int n : set) {
      if (set.find(n - 1) == set.end()) {
        bool found = true;
        int current = n + 1;

        while (found) {
          if (set.find(current) != set.end()) {
            common_seq++;
            current++;
          } else {
            if (common_seq > lcs) {
              lcs = common_seq;
            }

            common_seq = 1;
            found = false;
          }
        }
      }
    }

    return lcs;
  }
};
