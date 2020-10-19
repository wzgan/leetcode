//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include <queue>

class Solution {
public:
	//bfs level-traverse
    Node* connect(Node* root) 
    {
        std::queue<Node*> q1;
        std::queue<Node*> q2;

       
        while(!q1.empty() && !q2.empty())
        {

        }

    }
};