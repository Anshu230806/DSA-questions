// memoization 


  int fn( int i , int target , vector<int>& coins , vector<vector<int>>& dp){
        if(i == 0 ){
            if(target == 0) return dp[i][target] =1;
            if(target%coins[0] == 0 ) return dp[i][target]=1;
            return dp[i][target]=0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int notTake = fn(i-1 , target , coins , dp);
        int take = 0;
        if(coins[i] <= target){
            take = fn( i ,target-coins[i]  , coins ,dp);
        }
        return  dp[i][target] =take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount+1 ,-1));
        return fn(n-1 , amount , coins , dp);
    }




    /// Tabulation

     int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long >>dp(n , vector<long long>(amount+1 ,0));
        for(int i = 0 ; i<= amount ;i++){
            if(i == 0) dp[0][0] =1;
            else if(i%coins[0] == 0) dp[0][i] =1;
        }

        for(int i= 1; i< n ;i++){
            for(int j = 0 ; j <= amount ; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(coins[i] <= j){
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = (long long)take + notTake;
            }
        }
        return dp[n-1][amount];
    }