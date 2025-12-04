// https://leetcode.com/problems/group-anagrams/
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> solve(vector<string> &strs) {
    unordered_map<string, vector<string>> map;
    vector<int> char_counts(26, 0);

    for (string s : strs) {
      for (int i = 0; i < char_counts.size(); ++i) {
        char_counts[i] = 0;
      }

      for (char c : s) {
        char_counts[c - 'a'] += 1;
      }

      string key;
      key.reserve(26 * 2);
      for (int i = 0; i < 26; ++i) {
        key += "#";
        key += to_string(char_counts[i]);
      }

      if (map.find(key) != map.end()) {
        map.at(key).push_back(s);
      } else {
        map.insert({key, {s}});
      }
    }

    vector<vector<string>> ans;
    for (auto &pair : map) {
      ans.push_back(pair.second);
    }

    return ans;
  }
};
