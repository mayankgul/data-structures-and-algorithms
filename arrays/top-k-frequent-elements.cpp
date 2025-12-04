// https://leetcode.com/problems/top-k-frequent-elements

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> solve(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(nums[i]) != map.end()) {
        map.at(nums[i]) += 1;
      } else {
        map.insert({nums[i], 1});
      }
    }

    auto compare = [&](int a, int b) { return map.at(a) > map.at(b); };
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);

    for (auto &pair : map) {
      pq.push(pair.first);

      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<int> answer;
    while (!pq.empty()) {
      answer.push_back(pq.top());
      pq.pop();
    }

    return answer;
  }
};
