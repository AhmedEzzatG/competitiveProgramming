class Solution {
    struct monoqueue {
        deque<pair<int,int>> q;
        void push(int val,int idx){
            while(q.size() && q.back().first <= val)
                q.pop_back();
            q.push_back({val,idx});
        }
        void pop(int idx){
            while(q.size() && q.front().second <= idx)
                q.pop_front();
        }
        int getMax(){
            return q.front().first;
        }
    };
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        monoqueue q;
        int mx = -1e9;
        for(auto & it : points){
            int x = it[0],y = it[1];
            q.pop(x - k - 1);
            mx = max(mx,q.getMax() + y + x);
            q.push(y - x,x);
        }
        return mx;
    }
};