#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; //size of array
    cin>>s;
    
    //hash array
    int hash[256]={0};
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]-'a']+=1;
    }
    int q;//no of elemmnts to be checked
    cin>>q;
    while(q--)
    {
        char c;//num to be seached
        cin>>c;
        //fetch
        cout<<hash[c-'a']<<endl;
    }
}