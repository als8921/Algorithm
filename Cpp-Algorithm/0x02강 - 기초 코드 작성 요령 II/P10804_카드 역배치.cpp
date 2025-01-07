#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapNumbers(int arr[], int start, int end)
{
    for (int i = 0; i < (int)((end - start + 1) / 2); i++)
    {
        swap(arr[start + i - 1], arr[end - i - 1]);
    }
    
}
int main(){
    int arr[20];
    for (int i = 0; i < 20; i++) arr[i] = i + 1;
    for (int i = 0; i < 10; i++)
    {   int a, b;
        cin >> a >> b;
        swapNumbers(arr, a, b);
    }
    for (int i = 0; i < 20; i++) cout << arr[i] << " ";
}