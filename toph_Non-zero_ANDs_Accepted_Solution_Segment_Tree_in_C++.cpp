
/*
    Sk arman Hossain
    University of Barisal

    Problem name : toph Non-zero ANDs
    Algorithm/Data Structure : Segment Tree
 */
#include<bits/stdc++.h>
#define T(n) printf("test %d\n",n)
typedef long long int ll;
using namespace std;
vector<ll>V,V2,V3;
ll ar[100010];
ll result[40];
ll seg_tree[400010][40];
ll build(ll n,ll b,ll e)
{
    if(b==e)
    {
        ll tm=ar[b],pos=0;
        while(tm)
        {
            if(tm%2!=0)
            {
                seg_tree[n][pos]++;


            }
            pos++;
            tm/=2;
        }
        return 0;
    }
    ll mid=(b+e)/2;
    ll left=n*2;
    ll right=(n*2)+1;
    ll p=build(left,b,mid);
    ll q=build(right,mid+1,e);
    for(ll i=0;i<35;i++){
        seg_tree[n][i]=seg_tree[left][i]+seg_tree[right][i];
    }
    return 1;
}
ll query(ll n,ll b,ll e,ll i,ll j){
    if(b>j||e<i){
        return 0;
    }
    if(b>=i&&e<=j){
        for(ll cn=0;cn<35;cn++){
            result[cn]+=seg_tree[n][cn];
        }
        return 0;
    }
    ll mid=(b+e)/2;
    ll left=n*2;
    ll right=(n*2)+1;
    ll p=query(left,b,mid,i,j);
    ll q=query(right,mid+1,e,i,j);
    return 1;
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        scanf("%lld",&n);
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&ar[i]);
        }
        ll xx=build(1,1,n);
        ll q;
        scanf("%lld",&q);
        for(ll i=0; i<q; i++)
        {
            memset(result,0,sizeof(result));
            ll l,r,k;
            scanf("%lld %lld %lld",&l,&r,&k);
            ll tt=query(1,1,n,l,r);
            ll ck=0;
            for(ll i=0; i<35; i++)
            {
                if(result[i]>=k)
                {
                    ck=1;
                    break;
                }
            }
            if(ck==1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

