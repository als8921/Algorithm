#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        string s;
        cin >> s;

        list<char> result; 
        auto point = result.begin();
        for(char c : s)
        {
            if(c == '<')
            {
                if(point != result.begin())
                {
                    point--;
                }
            } 
            else if(c == '>')
            {
                if(point != result.end())
                {
                    point++;
                }
            }
            else if(c == '-')
            {
                if(point != result.begin())
                {
                    point = result.erase(--point);
                }
            }
            else
            {
                point = result.insert(point, c);
                point++;
            }
        }

        for(char i : result) cout << i; 
        cout << "\n"; 
    } 
}
