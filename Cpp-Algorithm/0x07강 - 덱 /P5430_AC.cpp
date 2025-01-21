#include<bits/stdc++.h>
using namespace std;


void R(deque<int> &dq)
{
    deque<int> reverse;
    while(!dq.empty())
    {
        reverse.push_back(dq.back());
        dq.pop_back();
    }
    dq = reverse;
}
void D(deque<int> &dq, bool reverse)
{
    if(reverse) dq.pop_back();
    else dq.pop_front();
}

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        string Cmd;
        string tempString;
        int n;
        cin >> Cmd >> n >> tempString;

        string arrayString;
        for(int i = 1; i < (int)tempString.length() - 1; i++)
            arrayString += tempString[i];

        istringstream ss(arrayString);

        string buffer;
        deque<int> dq;
        while(getline(ss,buffer,','))
            dq.push_back(stoi(buffer));

        bool reverse = false;
        bool isError = false;
        for(char c : Cmd)
        {
            if(c == 'R') reverse = !reverse;
            else if(c == 'D') 
            {
                if(dq.empty())
                {
                    isError = true;
                    break;
                }
                D(dq, reverse);
            }
            
            
        }
        if(reverse) R(dq);

        
        if(isError)
            cout << "error\n";
        else
        {
            if(dq.empty()) cout << "[]\n";
            else
            {
                cout << "[";
                for(int i = 0; i < (int)dq.size() - 1; i++)
                    cout << dq[i] <<",";
                cout << dq[(int)dq.size() - 1];
                cout << "]\n";
            }
        }
    }
}