/* https://www.codechef.com/COOK118B/problems/CHEFSHIP 
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll p =31;
ll h[100001];
ll power[100001];

ll mod = 1e9+7;

// we will store hash value of strings till ith length in h[] array

void generate_hash(string s)
{
    h[0] = s[0]-'a'+1;
    power[0]=1;
    for(int i=1;i<s.length();i++)
    {
        power[i] = ((power[i-1]%mod)*(p%mod))%mod;
        h[i] = ( h[i-1]%mod + ((s[i]-'a'+1)%mod *(power[i]%mod))%mod)%mod;
    }
}

ll getHash(int l,int r)
{
    if(l==0)
        return h[r]%mod;
    else
        return (h[r]-h[l-1]+mod)%mod;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        int cnt =0;
        generate_hash(s);
        for(int i=1;i<n-1;i+=2)
        {
            int id1 = i/2;
            int id2 = (i+n)/2;

            bool t1 = (getHash(0,id1)*power[id1+1])%mod == getHash(id1 + 1, i);
            bool t2 = (getHash(i+1,id2)*power[id2-i])%mod == getHash(id2+1, n-1);

            if(t1 && t2)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
