// https://leetcode.com/problems/verifying-an-alien-dictionary

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool solve(vector<string> &words, string order) {
    unordered_map<char, int> map;
    for (int i = 0; i < order.length(); ++i) {
      map.insert({order[i], i});
    }

    for (int i = 0; i < words.size(); ++i) {
      if (i == words.size() - 1) {
        break;
      }

      int min_length = min(words[i].length(), words[i + 1].length());
      bool prefix = false;
      for (int j = 0; j < min_length; ++j) {
        if (map.at(words[i][j]) < map.at(words[i + 1][j])) {
          break;
        } else if (map.at(words[i][j]) == map.at(words[i + 1][j])) {
          if (j == min_length - 1) {
            prefix = true;
          }
          continue;
        } else {
          return false;
        }
      }

      if (prefix && (words[i]).length() > min_length) {
        return false;
      }
    }

    return true;
  }
};
