class Solution {
    const int mod = 1e9+7;
    using ll = long long;
    ll power(ll x,ll y){
        if(y == 0)
            return 1;
        if(y == 1)
            return x;
        ll r = power(x,y>>1);
        return ((r*r)%mod * power(x,y&1))%mod;
    }
public:
    int numSubseq(vector<int> nums, int target) {
        sort(nums.begin(),nums.end());
        int l = 0,r = 0;
        int n = nums.size();
        int ans = 0;
        while(l<n && nums[l] <= target){
            int r = upper_bound(nums.begin(),nums.end(),target - nums[l]) - nums.begin();
            if(r <= l)
                break;
            ans =  (power(2,r - l - 1) + ans)%mod;
            l++;
        }
        return ans;
    }
};