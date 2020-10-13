#include <string>
#include <vector>

//brute-force 
std::vector<int> getNext_brute(const std::string& p)
{
    int sz = p.size();
    std::vector<int> next(sz, 0);
    for (int i = 0; i < sz; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if(p.substr(0, j) == p.substr(i-j+1, i+1))
            {
                next[i] = j;
                break;
            }
        }
    }
    return next;
}

//dp
std::vector<int> getNext_dp(const std::string &p)
{
    int sz = p.size();
    std::vector<int> next(sz, 0);
    next[0] = 0;
    for (int i = 1; i < sz; i++)
    {
        if(p[i] == p[next[i-1]])
        {
            next[i] = next[i-1]+1;
        }
        else
        {
            int now = next[i-1];
            while (next[now-1] != 0)
            {
                now = next[now-1];
                if(p[now] == p[i])
                {
                    next[i] = next[now-1]+1;
                }
            }
            next[i] = 0;
        }
    }
    return next;
}

int KmpMatch(const std::string &s, const std::string &p)
{
    int s_sz = s.length(), p_sz = p.length();
    
    std::vector<int> next = getNext_dp(p); 

    int i = 0, j = 0;
    while (i < s_sz)
    {
        if(s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = next[j-1];
            }
        }
        
        if (j == p_sz)
        {       
            return i-j;
        }
    }
    return -1;
}

//////
//dfa
std::vector<std::vector<int>> getDfa(const std::string &p)
{
    int m = p.size();
    std::vector<std::vector<int>> dfa(m, std::vector<int>(26, 0));
    dfa[0][p[0]] = 1;
    int x = 0;
    for(int j = 1; j < m; ++j)
    {
        for(int c = 'a'; c <= 'z'; ++c)
        {
            if(c == p[j])
            {
                dfa[j][c] = j+1;
            }
            else
            {
                dfa[j][c] = dfa[x][c];
            }
        }
        x = dfa[x][p[j]];
    }
}

int kmpMatch_dfa(const std::string &s, const std::string &p)
{
    int n = s.size(), m = p.size();
    int j = 0;

    std::vector<std::vector<int>> dfa = getDfa(p);
    for (int i = 0; i < n; i++)
    {
        j = dfa[j][s[i]];
        if(j == m)
        {
            return i-m+1;
        }
    }
    return -1;
}