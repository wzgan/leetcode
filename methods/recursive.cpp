//
// Created by 甘唯哲 on 2020/6/24.
//

/*
 * Fibonacci
 */
int fibonacci(int n)
{
    //结束条件
    if (n <= 2)
    {
        return 1;
    }

    //递归关系
    return fibonacci(n-1) + fibonacci(n-2);
}

/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
int frog(int n)
{
//    if (n == 1)
//    {
//        return 1;
//    }  //结束条件不严谨，陷入死循环

    if(n <= 2)
    {
        return n;
    }

    return frog(n-1) + frog(n-2);
}

/*
 * 反转单链表
 */
struct Node
{
    int val;
    Node* next;
};

void reverse(Node* head)
{
    if (!head || !head->next)
    {
        return;
    }

    Node* headNext = head->next;
    reverse(headNext);
    headNext->next = head;
    head->next = nullptr;
}