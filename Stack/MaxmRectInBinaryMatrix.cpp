#include "bits/stdc++.h"
using namespace std ;
int mah(vector<int> a ,int n)
{
    vector<int> l;
    vector<int> r;
    stack<pair<int,int>> st ;
    stack<pair<int,int>> s2 ;
    for(int i =0 ;i<n ;i++)
    {
        if(st.empty())
        {
            l.push_back(-1) ;
        }else if(st.size()>0 && st.top().first<a[i])
        {
            l.push_back(st.top().second) ;
        }else if(st.size()>0 && st.top().first>=a[i])
        {
            while(st.size()>0 && st.top().first>=a[i])
            {
                st.pop() ;
            }
            if(st.size()==0)
            {
                l.push_back(-1) ;
            }else {
                l.push_back(st.top().second) ;
            }
        }
        st.push({a[i],i}) ;
    }
    
    for(int i =n-1 ;i>=0 ;i--)
    {
        if(s2.empty())
        {
            r.push_back(n) ;
        }else if(s2.size()>0 && s2.top().first<a[i])
        {
            r.push_back(s2.top().second) ;
        }else if(s2.size()>0 && s2.top().first>=a[i])
        {
            while(s2.size()>0 && s2.top().first>=a[i])
            {
                s2.pop() ;
            }
            if(s2.size()==0)
            {
                r.push_back(n) ;
            }else {
                r.push_back(s2.top().second) ;
            }
        }
        s2.push({a[i],i}) ;
    }
    reverse(r.begin(),r.end()) ;
    vector<int> w ;
    for (int i = 0; i < n; i++)
    {
        w.push_back(r[i]-l[i]-1) ;
    }
    vector<int> area ;
    for (int i = 0; i < n; i++)
    {
        area.push_back(w[i]*a[i]) ;
    }
    int mx = area[0] ;
    for (int i = 1; i < n; i++)
    {
        mx=max(mx,area[i]) ;
    }
    return mx ;
}

int main()
{
    int n,m ;
    cin>>n>>m ;
    int a[n][m] ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j] ;
        }
    }

    vector<int> v ;
    for(int j =0 ;j<m ;j++)
    {
        v.push_back(a[0][j]) ;
    }
    int mx =mah(v,m) ;
    for(int i =1 ;i<n ;i++)
    {
        for(int j =0 ;j<m ;j++)
        {
            if(a[i][j]==0)
            {
                v[j] =0 ;
            }else{
                v[j]=v[j]+a[i][j] ;
            }
        }
        mx=max(mx,mah(v,m)) ;
    }
    cout<<mx<<endl ;
    
}