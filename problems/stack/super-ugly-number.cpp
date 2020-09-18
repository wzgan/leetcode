//
// Created by 甘唯哲 on 2020/9/17.
//

#include <vector>
#include <queue>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        q.push(1);
        for (int i = 0; i < n-1; ++i)
        {
            int cur = q.top();
            while (!q.empty() && q.top() == cur)
            {
                q.pop();
            }
            for (int fact : primes)
            {
                q.push(cur*fact);
            }
        }
        return q.top();
    }

    struct Number
    {
        int num;
        int index;
        int prime;
        Number(int num, int index, int prime): num(num), index(index), prime(prime){}
        bool operator > (const Number& n) const
        {
            return num > n.num;
        }
    };

    int nthSuperUglyNumber2(int n, std::vector<int>& primes)
    {
        std::priority_queue<Number,std::vector<Number>, std::greater<Number>> q;
        std::vector<int> ugly_nums(n, 1);

        for (int prime : primes)
        {
            Number n(prime, 0, prime);
            q.push(n);
        }

        for (int i = 1; i < n; ++i)
        {
            int cur = q.top().num;
            ugly_nums[i] = cur;
            while (cur == q.top().num)
            {
                Number n = q.top();
                q.pop();
                q.push(Number(n.prime*ugly_nums[n.index+1], n.index+1, n.prime));
            }
        }

        return ugly_nums[n-1];
    }
};