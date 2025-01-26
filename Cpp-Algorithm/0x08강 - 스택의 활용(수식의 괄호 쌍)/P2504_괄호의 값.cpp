#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string input;
    getline(cin, input);

    stack<char> stk;
    int result = 0;
    int temp = 1;
    for(char c : input)
    {
        if(c == '(')
        {
            stk.push(c);
        }
        else if(c == '[')
        {
            stk.push(c);
        }
        else if(c == ')')
        {
            if(!stk.empty() && stk.top() == '(') 
            {
                stk.pop();
                temp *= 2;
            }
            else
            {
                result = 0;
                break;
            }
        }
        else if(c == ']')
        {
            if(!stk.empty() && stk.top() == '[')
            {
                stk.pop();
                temp *= 3;
            }
            else
            {
                result = 0;
                break;
            }
            
        }
        if(stk.empty())
        {
            result += temp;
            temp = 1;
        }
    }
    cout << result << "\n";
}

/*
(()[[]])([])

(2 + 3 * 3) * 2 + 3 * 2


2 + 3
*/