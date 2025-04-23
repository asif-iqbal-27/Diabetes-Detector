#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;


// Custom implementation of upper_bound
ll custom_upper_bound(vector<ll>& v,ll l, ll value) {
    ll low = l, high = v.size();
    if(value<v[low] or value>v[high-1])return 0;
    while (low < high) {
        ll mid = (low + high) / 2;
        if (v[mid] > value)
            high = mid;
        else
            low = mid + 1;
    }
    //if(value<v[low])return 0;
    return low-l;
}

// Custom implementation of lower_bound
ll custom_lower_bound(vector<ll>& v,ll l, ll value) {
    ll low = l, high = v.size();
        if(value<v[low] or value>v[high-1])return 0;

    while (low < high) {
        ll mid = (low + high) / 2;
        if (v[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low-l;
}

int main() {
   
    int t;
    cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> v(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(),v.end());
        
        ll ans = 0;
      for(int i=0;i<n;i++) {
            ll num1 = sum - v[i] - x;
            ll num2 = sum - v[i] - y;
            ll up = custom_upper_bound(v,i, num1);
            ll lb = custom_lower_bound(v,i, num2);
          //  v.erase(v.begin());
        //  cout<<num1<<" "<<num2<<" "<<up<<" "<<lb<<endl;
            ans += (up - lb);
            if (lb == 0 && up - lb > 0)
                ans--;
        }
        cout << ans << endl;
    }
    return 0;
}