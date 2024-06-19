class Solution {
public:
    long long dfs(int curr,int p,long long k,vector <vector<pair<int,long long>>> &dp){
        if(p==-1) return 0;
        if(k&(1LL<<p)){
            return dp[p][curr].second+dfs(dp[p][curr].first,p-1,k,dp);
        }
        return dfs(curr,p-1,k,dp);
    }
    long long getMaxFunctionValue(vector<int>& arr, long long k) {
        int n = arr.size();
        vector <vector<pair<int,long long>>> dp(40,vector<pair<int,long long>>(n));
        
        for(int i=0;i<n;i++) dp[0][i] = {arr[i],arr[i]};

        for(int i=1;i<40;i++){
            for(int j=0;j<n;j++){
                int x = dp[i-1][j].first;
                dp[i][j] = {dp[i-1][x].first,dp[i-1][x].second+dp[i-1][j].second};
            }
        }
  
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,dfs(i,39,k,dp)+i);
        }
        return ans;
        
    }
};