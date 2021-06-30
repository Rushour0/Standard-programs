#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define loop(i,s,n) for(int i = s;i<n;i++)
#define ll long long int
#define max_vec(v) *max_element(v.begin(),v.end())
#define min_vec(v) *min_element(v.begin(),v.end())
#define vec_in(v,n) do{int temp; for(ll i = 0;i<n;i++){cin>>temp;v.push_back(temp);}}while(0)

typedef vector<ll> vll;
typedef vector<int> vi;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm_vec(vi &vec)
{

    ll ans = vec[0];

    for (int i = 1; i < vec.size(); i++)
        ans = (((vec[i] * vec)) / (gcd(vec[i], ans)));
 
    return ans;
}

ll gcd_vec(vi & vec)
{
	ans = vec[0];

	for(int i = 1;i<vec.size();i++)
	{
		ans = gcd(vec[i],ans);
	}

	return ans;
}
int main()
{   
    fastio();
    int n,m;
    cin>>n>>m;
    vi a,b;
    vec_in(a,n);
    vec_in(b,m);
    ll stop_val = min_vec(b)    
    ll lcm_a = lcm_vec(a);
    ll gcd_b = gcd_vec(a);
    ll mult = lcm_a;
    static int count;
    while(mult<=stop_val)
    {
    	if (!gcd_b%mult)count++;
    	mult+=lcm_a;
    }
    cout<<count;
    return 0;
}
