#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    while(1)
    {
        string input;
        stack<char> s;
        getline(cin, input);
        bool result = true;
        if(input == ".") break;
        for(char c : input)
        {
            if(c == '.') break;
            else if (c == '[')
                s.push(c);
            else if (c == '(')
                s.push(c);
            else if (c == ']')
            {   
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else
                {
                    result = false;
                    break;
                }
            }
            else if (c == ')')
            {
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else
                {
                    result = false;
                    break;
                }
            }
        }
        if(s.empty() && result) cout << "yes\n";
        else cout << "no\n";
    }
}