#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<math.h>
#include<set>

using namespace std;

void print(int a[], int n) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    vector<int> v{3,2,1,0,4};
    int n=v.size();
    int max_reachable=0;
    vector<bool> visited(n,false);
    if(v[0]==0 && v.size()>1)
    {
        return false;
    }
    visited[0]=true;
    for(int i=0;i<n-1;i++)
    {
        max_reachable=max(max_reachable,v[i]+i);
        if(max_reachable<=i)
        {
            return false;
        }
        if(i+v[i]<n)
        {
            visited[v[i]+i]=true;
        }
        else if(i+v[i]>=n)
        {
            visited[n-1]=true;//
        }
    }
    return visited[n-1];

}
