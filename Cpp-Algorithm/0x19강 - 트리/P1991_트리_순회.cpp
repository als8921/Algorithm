#include <bits/stdc++.h>
using namespace std;


struct Node
{
    char preNode;
    char nextNode;
};

map<char, Node> nodeList;


void preorderTraversal(char currentNode)
{
    char preNode = nodeList[currentNode].preNode;
    char nextNode = nodeList[currentNode].nextNode;

    cout << currentNode;
    if(preNode != '.') preorderTraversal(preNode);
    if(nextNode != '.') preorderTraversal(nextNode);
}


void postorderTraversal(char currentNode)
{
    char preNode = nodeList[currentNode].preNode;
    char nextNode = nodeList[currentNode].nextNode;

    if(preNode != '.') postorderTraversal(preNode);
    if(nextNode != '.') postorderTraversal(nextNode);
    cout << currentNode;
}

void inorderTraversal(char currentNode)
{
    char preNode = nodeList[currentNode].preNode;
    char nextNode = nodeList[currentNode].nextNode;

    if(preNode != '.') inorderTraversal(preNode);
    cout << currentNode;
    if(nextNode != '.') inorderTraversal(nextNode);
}


int main(){
    int n; cin >> n;
    while(n--)
    {
        char cur, pre, next;
        cin >> cur >> pre >> next;
        nodeList.insert({cur, Node({pre, next})});
    }

    preorderTraversal('A');
    cout<<"\n";

    inorderTraversal('A');
    cout<<"\n";

    postorderTraversal('A');
    cout<<"\n";
}