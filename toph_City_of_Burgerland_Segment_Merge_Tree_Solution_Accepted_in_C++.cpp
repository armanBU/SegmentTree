/*
    Sk arman Hossain
    University of Barisal

    Problem name : toph City of Burgerland
    Algorithm :Segment_Merge_tree
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
//ll big_mod(ll base,ll power,ll Mod){if(power==0){return 1;}else if(power%2==1){ll p1=base%Mod;ll p2=(big_mod(base,power-1,Mod))%Mod;return (p1*p2)%Mod;}else if(power%2==0){ll p1=(big_mod(base,power/2,Mod))%mod;return (p1*p1)%Mod;}}

vector<ll>Merge[500000],cum[500000];
ll ar[200000];
void merg(vector<ll> a,vector<ll> b,ll node)
{
    ll i=0,j=0;
    ll l1=a.size(),l2=b.size();
    while(i<l1&&j<l2)
    {
        if(a[i]<b[j])
        {
            Merge[node].PB(a[i]);
            i++;
        }
        else
        {
            Merge[node].PB(b[j]);
            j++;
        }
    }
    while(i<l1)
    {
        Merge[node].PB(a[i]);
        i++;
    }
    while(j<l2)
    {
        Merge[node].PB(b[j]);
        j++;
    }
    ll sum=0;
    sum=Merge[node][0];
    ll l3=Merge[node].size();
    cum[node].PB(0);
    for(ll k=1; k<l3; k++)
    {
        sum+=Merge[node][k];
        cum[node].PB(((k+1)*(Merge[node][k]))-sum);
    }
}
ll segmentTree(ll n,ll b,ll e)
{
    if(b==e)
    {
        Merge[n].PB(ar[b]);
        cum[n].PB(0);
        return 1;
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    segmentTree(l,b,mid);
    segmentTree(r,mid+1,e);
    merg(Merge[l],Merge[r],n);
    return 1;
}
ll query(ll n,ll b,ll e,ll i,ll j,ll x)
{
    if(b>j||e<i)
    {
        return 0;
    }
    if(b>=i&&e<=j)
    {
        ll ans=0;
        ll pos=upper_bound(Merge[n].begin(),Merge[n].end(),x)-Merge[n].begin();
        if(pos>=(ll)Merge[n].size())
        {
            pos-=1;
        }
        else
        {
            if(pos)
            {
                if(Merge[n][pos]>x)
                {
                    pos-=1;
                    //ll tm=Merge[n][pos-1];
                   // ll pos=lower_bound(Merge[n].begin(),Merge[n].end(),Merge[n][pos-1])-Merge[n].begin();
                }
            }
        }
        ans=cum[n][pos];
        if(x>(ll)Merge[n][pos])
        {
            ans+=((x-(ll)Merge[n][pos])*(pos+1));
        }
        return ans;
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    ll p=query(l,b,mid,i,j,x);
    ll q=query(r,mid+1,e,i,j,x);
    return (p+q);
}
int main()
{
    //freopen("1input.txt","r",stdin);

    ll n,q,a,b;
    scanf("%lld%lld",&n,&q);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&ar[i]);
    }
    ll y=segmentTree(1, 1, n);
    for(ll i=0; i<q; i++)
    {
        ll m,ans;
        scanf("%lld%lld%lld",&a,&b,&m);
        ans=query(1,1,n,a,b,m);
        printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

