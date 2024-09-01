#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; //size of array
    cin>>n;
    int arr[n];//array
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //hash array
    int hash[13]={0};
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]+=1;
    }
    int q;//no of elemmnts to be checked
    cin>>q;
    while(q--)
    {
        int number;//num to be seached
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
}