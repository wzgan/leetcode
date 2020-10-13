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
    
}

int KmpMatch(const std::string &s, const std::string &p)
{
    int s_sz = s.length(), p_sz = p.length();
    
    std::vector<int> next = getNext_brute(p); 

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
    return false;
}