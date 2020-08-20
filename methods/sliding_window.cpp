//
// Created by 甘唯哲 on 2020/8/17.
//

//https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie

/*
 * 向右扩大窗口时，如何更新窗口的数据
 * 在什么情况下需要从左边缩小窗口
 * 缩小窗口时如何更新窗口数据
 * 结果在什么时候更新
 */

#include <string>
#include <unordered_map>
#include <vector>

//最小覆盖子串
//https://leetcode.com/problems/minimum-window-substring/
class Solution1 {
public:
    std::string minWindow(std::string s, std::string t)
    {
        std::unordered_map<char, int> need, window;
        for(char c : t)
        {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;

        int start = 0, len = s.size() + 1;
        while (right < s.size())
        {
            char c = s[right]; //即将移入窗口的字符
            right++; //窗口向右扩张

            //窗口数据更新
            if (need.count(c))
            {
                window[c]++;
                if (need[c] == window[c])
                    valid++;
            }

            //收缩窗口
            while (valid == need.size())
            {
                //更新最小覆盖子串
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }

                char d = s[left]; //要移除的字符
                left++; //窗口左边界收缩

                if (need.count(d)) //窗口内数据更新
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        return len == s.size()+1 ? "" : s.substr(start, len);
    }
};

//字符串排列
//https://leetcode.com/problems/permutation-in-string/

class Solution2 {
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        std::unordered_map<char, int> need, window;
        for (char c : s1)
        {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;

        while (right < s2.size())
        {
            char c = s2[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                {
                    valid++;
                    if (valid == need.size())
                        return true;
                } else if (window[c] > need[c])
                {
                    while (s2[left] != c)
                    {
                        char d = s2[left];
                        left++;
                        if ((window[d]--) == need[d])
                        {
                            valid--;
                        }
                    }
                    left++;
                    window[c]--;
                }
            } else
            {
                left = right;
                valid = 0;
                window.clear();
            }
        }
        return false;
    }

    bool checkInclusion2(std::string s1, std::string s2)
    {
        std::unordered_map<char, int> need, window;
        for (char c : s1)
        {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size())
        {
            char c = s2[right];
            right++;

            if (need.count(c))
            {
                window[c]++;
                if (need[c] == window[c])
                    valid++;
            }

            while (right - left == s1.size())
            {
                if (valid == need.size())
                    return true;

                char d = s2[left];
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};

//找所有字母异位词 implicit instantiation
//https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution3 {
public:
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        std::unordered_map<char, int> need, window;
        for (char c : p)
            need[c]++;

        std::vector<int> res;

        int left = 0, right = 0;
        int valid = 0;

        while (right < s.size())
        {
            char c = s[right++];

            if (need.count(c))
            {
                if (++window[c] == need[c])
                    valid++;
            }

            while (right - left == p.size())
            {
                if (valid == need.size())
                    res.push_back(left);

                char d = s[left++];
                if (need.count(d))
                {
                    if (window[d]-- == need[d])
                        valid--;
                }
            }
        }
        return res;
    }
};

//最长无重复子串
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution4 {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> window;

        int left = 0, right = 0;
        int len = 0, max_len = 0;
        while (right < s.size())
        {
            char c = s[right++];
            if (!window.count(c))
            {
                window[c]++;
                len++;
            } else
            {
                max_len = std::max(len, max_len);
                while (s[left] != c)
                {
                    window.erase(s[left++]);
                    len--;
                }
                left++;
            }
        }
        return std::max(len, max_len);
    }

    int lengthOfLongestSubstring2(std::string s)
    {
        std::unordered_map<char, int> window;

        int left = 0, right = 0;
        int res = 0;
        while (right < s.size())
        {
            char c = s[right++];
            window[c]++;

            while (window[c] > 1)
            {
                char d = s[left++];
                window[d]--;
            }

            res = std::max(res, right - left);
        }

        return res;
    }
};