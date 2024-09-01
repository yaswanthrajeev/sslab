#include <iostream>
#include <vector>

using namespace std;

void display(const vector<int> &v)  // v is a const reference
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] <<" ";
         // We can read v[i], but cannot modify v[i]
    }
     cout<<endl;
}

int main()
{
    vector<int> v = {10, 20, 35};
    display(v);  // Calling the function, v remains unchanged
    v.push_back(30);//adds 30 to the end
    display(v);
    v.pop_back();//removes elemen from end
    display(v);
    v.erase(v.begin()); 
    display(v);
    cout<<v.size()<<endl;
    return 0;
}
