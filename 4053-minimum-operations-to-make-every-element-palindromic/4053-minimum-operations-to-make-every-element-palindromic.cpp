class Solution {
public:
    using ll = long long;
    void build( vector<ll> &even,  vector<ll> &odd){
        for(ll x=1; x<=99999; x++){
            string s = to_string(x);
            string t = s;
            for(int i=s.size()-2; i>=0; i--){
                t += s[i];
            }
            ll p = stoll(t);
            if(p<=1000000001LL){
                if(p%2==0) even.push_back(p);
                else odd.push_back(p);
            }
            t = s;
            for(int i=s.size()-1; i>=0; i--){
                t += s[i];
            }
            p = stoll(t);
            if(p<=1000000001LL){
                if(p%2==0) even.push_back(p);
                else odd.push_back(p);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
    }
    ll calcost(ll x, vector<ll>& v){
        auto it = lower_bound(v.begin(), v.end(), x);
        ll best = 1e18;
        if(it!=v.end()){
            best = min(best, llabs(x-*it));
        }
        if(it!=v.begin()){
            --it;
            best = min(best, llabs(x-*it));
        }
        return best/2;
    }
    long long minOperations(vector<int>& nums) {
        static vector<ll> even, odd;
        static bool done = false;
        if(!done){
            build(even, odd);
            done = true;
        }
        ll cost = 0;
        for(auto x : nums){
            if(x%2==0){
                cost += calcost(x, even);
            }
            else cost += calcost(x, odd);
        }
        return cost;
    }
};