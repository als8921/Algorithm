#include<bits/stdc++.h>
using namespace std;

long long maxArea(vector<int> height);
void printStack(std::stack<std::pair<int, int>> s) {
    std::vector<std::pair<int, int>> temp;

    // 스택의 원소를 벡터에 저장
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }

    // 벡터의 원소를 역순으로 출력
    for (int i = temp.size() - 1; i >= 0; --i) {
        std::cout << "(" << temp[i].first << ", " << temp[i].second << ") ";
    }
    std::cout << std::endl;
}
int main()
{
    while(1)
    {
        vector<int> h;
        int n;
        cin >> n;
        if(!n) break;

        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            h.push_back(a);
        }
        // cout <<"\nanswer : "<< maxArea(h) << "\n";
        cout << maxArea(h) << "\n";
    }
}

long long maxArea(vector<int> height){
    long long area = 0;
    stack<pair<int, int>> s;
    for(int i = 0; i < (int)height.size(); i++)
    {
        area = max(area, (long long) height[i]);
        if(s.empty())
        { 
            s.push({i, height[i]});
        }
        else if(!s.empty() && s.top().second < height[i])
        {
            // area = max(area, (long long) (i - s.top().first + 1) * s.top().second);
            s.push({i, height[i]});
        }
        else if(!s.empty() && s.top().second == height[i])
        {
            area = max(area, (long long) (i - s.top().first + 1) * s.top().second);
        }
        else if(!s.empty() && s.top().second > height[i])
        {
            area = max(area, (long long) (i - s.top().first + 1) * height[i]);
            pair<int, int> temp;
            while(!s.empty() && s.top().second >= height[i])
            {   
                temp = s.top();
                area = max(area, (long long) (i - temp.first) * temp.second);
                s.pop();
            }
            s.push({temp.first, height[i]});
        }
        // printStack(s);
        // cout << "++++++++++++++++++++++++++++++++++++++   " <<area<<"\n";
    }
    while(!s.empty())
    {
        area = max(area, (long long) (height.size() - s.top().first) * s.top().second);
        s.pop();
    }

    return area;
}