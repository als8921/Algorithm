#include<bits/stdc++.h>
using namespace std;

struct IndexValue{
    int idx;
    int value;
};
struct Compare{
    bool operator()(IndexValue a, IndexValue b)
    {
        return a.value > b.value;
    }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    int N, L;
    cin >> N >> L;
    priority_queue<IndexValue, vector<IndexValue>, Compare> pq;

    for(int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        pq.push({i, value});

        while(pq.top().idx <= i - L)
        {
            pq.pop();
        }
        cout << pq.top().value << " ";
    }
}