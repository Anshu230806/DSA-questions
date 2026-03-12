// memoization 
class Solution {
public:
    int fn(int i , int target , vector<int>& coins ,  vector<vector<int>>& dp){
        if(i == 0 ){
            if( target%coins[0] ==0 ) return dp[0][target]= target/coins[0];
            return INT_MAX;
        }
        if(dp[i][target] != -1) return dp[i][target];
        long long  notTake = 0 + fn(i-1 , target , coins , dp );
        long long take = INT_MAX;
        if(target >= coins[i]){ 
           
            long long var = fn(i , target-coins[i] , coins , dp);
            if(var >= INT_MAX){
                take = INT_MAX;
            }
            else{
                take =  1+ var;
            } 
        }
        return dp[i][target] = min( take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp( n , vector<int>(amount+1 , -1));
        int ans= fn(n-1, amount, coins , dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

// TABULATION


 
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp( n , vector<int>(amount+1 , -1));
        for(int target = 0 ; target <= amount ; target++){
            if( target%coins[0] ==0 ) dp[0][target] = target/coins[0];
            else{
                dp[0][target] = INT_MAX;
            }
        }
        
        for(int i = 1 ; i< n ;i++){
            for(int target = 0 ; target <= amount ; target++){
                long long notTake = 0 + dp[i-1][target];
                long long  take = INT_MAX;
                if(coins[i] <= target ){
                    long long var = 1 + (long long)dp[i][target-coins[i]];
                    if(var >= INT_MAX){
                        take = INT_MAX;
                    }
                    else{
                        take =  var;
                    } 
                }
                dp[i][target] = min(take , notTake);
            }
        }
        if( dp[n-1][amount] == INT_MAX) return -1;
        return dp[n-1][amount];
    }
};