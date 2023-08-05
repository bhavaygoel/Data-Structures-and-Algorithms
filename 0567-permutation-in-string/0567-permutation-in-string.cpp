class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m;
        for (auto ch : s1) {
            m[ch]++;
        }
        int count = m.size(), i = 0, j = 0;
        while (j < s2.size()) {
            if (m.find(s2[j]) != m.end()) {
                m[s2[j]]--;
                if (m[s2[j]] == 0) {
                    count--;
                }
            }
            while (count == 0) {
                if (j - i + 1 == s1.size()) return true;
                if (m.find(s2[i]) != m.end()) {
                    m[s2[i]]++;
                    if (m[s2[i]] == 1) {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return false;
    }
};
