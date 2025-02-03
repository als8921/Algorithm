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
    for(int i = 0; i < (int)input.size(); i++)
    {
        char c = input[i];
        if(c == '(')
        {
            temp *= 2;
            stk.push(c);
        }
        else if(c == '[')
        {
            temp *= 3;
            stk.push(c);
        }
        else if(c == ')')
        {
            if(!stk.empty() && stk.top() == '(') 
            {
                if(input[i-1] == '(') result += temp;
                temp /= 2;
                stk.pop();
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
                if(input[i-1] == '[') result += temp;
                temp /= 3;
                stk.pop();
            }
            else
            {
                result = 0;
                break;
            }
            
        }
    }
    if(!stk.empty()) result = 0;
    cout << result << "\n";
}