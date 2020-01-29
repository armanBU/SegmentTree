/*
    Sk arman Hossain
    University of Barisal

    Problem name :Codeforces D. Xenia and Bit Operations
    Algorithm : Segment Tree
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll s_tree[600010],ar[400010];
ll segmentTree(ll n,ll b,ll e,ll label)
{
    if(b==e)
    {
        s_tree[n]=ar[b];
        return ar[b];
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    segmentTree(l,b,mid,label+1);
    segmentTree(r,mid+1,e,label+1);
    if(label%2==0)
    {
        s_tree[n]=(s_tree[l]^s_tree[r]);
    }
    else
    {
        s_tree[n]=(s_tree[l]|s_tree[r]);
    }
    return s_tree[n];
}
ll update_query(ll n,ll b,ll e,ll i,ll j,ll x,ll label)
{
    if(b>j||e<i)
    {
        return s_tree[n];
    }
    if(b>=i&&e<=j)
    {
        s_tree[n]=x;
        return s_tree[n];
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    update_query(l,b,mid,i,j,x,label+1);
    update_query(r,mid+1,e,i,j,x,label+1);
    if(label%2==0)
    {
        s_tree[n]=(s_tree[l]^s_tree[r]);
    }
    else
    {
        s_tree[n]=(s_tree[l]|s_tree[r]);
    }
    return s_tree[n];
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);

    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        sf2(n,q);
        ll node=pow(2,n);
        for(ll i=1; i<=node; i++)
        {
            sf1(ar[i]);
        }
        ll label;
        if(n%2==0)label=2;
        else label=1;
        ll tm2=segmentTree(1,1,node,label);
        for(ll i=0; i<q; i++)
        {
            ll a,b;
            sf2(a,b);
            ar[a]=b;
            ll tm=update_query(1,1,node,a,a,b,label);
            printf("%lld\n",s_tree[1]);
        }
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

