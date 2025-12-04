// https://leetcode.com/problems/valid-anagram
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); ++i) {
      if (map.find(s[i]) != map.end()) {
        map.at(s[i]) += 1;
      } else {
        map.insert({s[i], 1});
      }

      if (map.find(t[i]) != map.end()) {
        map.at(t[i]) -= 1;
      } else {
        map.insert({t[i], -1});
      }
    }

    for (auto &pair : map) {
      if (pair.second != 0) {
        return false;
      }
    }

    return true;
  }
};
