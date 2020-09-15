//
// Created by 甘唯哲 on 2020/8/21.
//

//Implement Queue using Stacks
//https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>
#include <vector>

class MyQueue {
private:
    std::stack<int> in;
    std::stack<int> out;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {

    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int res = out.top();
        out.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
};


//priority queue
//binary heap
class MaxPQ
{
private:
    std::vector<int> pq;
    int N = 0;

public:
    MaxPQ(int cap)
    {
        pq.insert(pq.begin(), cap, 0);
        N = cap;
    }

    int max()
    {
        return pq[1];
    }

    void insert(int e)
    {
        N++;
        pq.push_back(e);
        swim(N);
    }

    void delMax()
    {
        exch(1, N);
        pq.pop_back();
        sink(1);
        N--;
    }

private:
    void swim(int k) //swim element with index k
    {
        while (k > 1 && pq[k] > pq[k/2])
        {
            exch(k, k/2);
            k = k/2;
        }
    }

    void sink(int k)
    {
        while (k*2 <= N)
        {
            int older = k*2;
            if (k*2 < N && pq[k*2] < pq[k*2+1])
                older = k*2+1;
            if (pq[k] >= pq[older])
                break;
            exch(k, older);
            k = older;
        }
    }

    void exch(int i, int j)
    {
        int temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }

};