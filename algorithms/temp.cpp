#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<math.h>
#include<set>
#include <algorithm>

using namespace std;
#define int long long
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

void temp(vector<int> v)
{
    int n=v.size();
    vector<int> len;
    if(v.size()<3)
    {
        return ;
    }
    int prev=v[0];
    int temp_count=1;
    int ans=0;
    vector<int> s;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==prev)
        {
            temp_count++;
        }
        else
        {
            s.push_back(prev);
            prev=v[i];
            len.push_back(temp_count);
            temp_count=1;
        }
    }
    print(v);
    s.push_back(v[v.size()-1]);

    len.push_back(temp_count);

    for(int i=0;i<len.size();i++)
    {
        if(len[i]>2)
        {
            ans=ans+(len[i]-2);
            len[i]=2;
        }
    }
    n-=ans;
    cout<<ans<<endl;
    vector<int> actual;
    for(int i=0;i<s.size();i++)
    {
        int t=s[i];
        for(int j=0;j<len[i];j++)
        {
            actual.push_back(t);
        }
    }
    vector<int> index;
    int cur=0;
    print(actual);
    print(len);
    for(int i=0;i<len.size();i++)
    {
        index.push_back(cur);
        cur+=len[i];
    }
    print(index);
    int start=1;
    for(int i=0;i<len.size();i++)
    {
        if(len[i]==2 && index[i]%2==0)
        {
            ans++;
            n--;
            start=i;
            break;
        }
    }
    cout<<ans<<endl;
    vector<int> final_index;
    for(int i=0;i<len.size();i++)
    {
        if(len[i]==2)
        {
            final_index.push_back(index[i]);
        }
    }
    print(final_index);
    if(final_index.size()>0)
    {
        int c=start;
        int t2=1;
        int j=0;
        while(final_index[j]!=start)
        {
            t2++;
            j++;
        }
        t2=max(t2,j+1);
        for(int i=t2;i<final_index.size();i++)
        {
            if(c%2==final_index[i]%2)
            {
                continue;
            }
            else
            {
                ans++;
                n--;
                c=final_index[i];
            }
        }
    }
    if(n%2!=0)
    {
        ans++;
    }
    cout<<ans;


}
bool ans=false;
bool helper(vector<int>& nums, int target,int low,int high)
{
    int mid=low+high;
    mid/=2;
    if(nums[mid]==target)
        return true;
    bool x=false;
    bool y=false;
    bool z=false;
    bool a=false;
    if(nums[low]<=nums[mid])
    {
        if(nums[low]<=target && nums[mid]>=target)
        {
            x=helper(nums,target,low,mid-1);
        }
        else
        {
            y=helper(nums,target,mid+1,high);
        }
    }
    if(nums[mid]<=nums[high])
    {
        if(nums[mid]<=target && nums[high]>=target)
        {
            z=helper(nums,target,mid+1,high);
        }
        else
        {
            a=helper(nums,target,low,mid-1);
        }
    }
    return a||z||y||x;
}
bool search(vector<int>& nums, int target) {
    return helper(nums,target,0,nums.size()-1);
}
int32_t main() {
   vector<int> v{2,5,6,0,0,1,2};
   return search(v,3);

}

