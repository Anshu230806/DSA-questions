// similar with cnt partition with given target 
//  int target = (sum+diff)/2;
// memoization

//edge cases - 
// 1. diff > sum return 0
// 2. diff+sum) %2 != 0 return 0
//3 . every  0 doubles the result  ******
//  if(arr[0] == 0 && target ==0 ) return dp[i][target] = 2;





class Solution {
  public:
    int fn(int i ,int target ,vector<int>& arr ,vector<vector<int>>& dp)
    {
        //if(target == 0) return dp[i][target] =1;
        // important edge case
        if(i == 0){
            if(arr[0] == 0 && target ==0 ) return dp[i][target] = 2;
            if(target == arr[0]) return dp[i][target]= 1;
            if(target == 0) return dp[i][target] =1;
            return dp[i][target]= 0;
        }
        if(dp[i][target] != -1 ) return dp[i][target];
        int notTake = fn(i-1 , target , arr , dp);
        int take = 0;
        if(arr[i] <= target){
            take = fn(i-1 , target-arr[i] , arr , dp);
        }
        return dp[i][target] = take+notTake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n ;i++) sum += arr[i];
        if(diff > sum ||  (diff+sum)%2 !=0 ) return 0;
        int target = (sum+diff)/2;
        vector<vector<int>>dp(n ,vector<int>(target+1 ,-1));
        fn(n-1 , target , arr  , dp);
        return dp[n-1][target];
    }
};


  
// logical or is this ->  ||   which should be used in this que
// bitwise or is -> | 




// TABULATION 



   int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n ;i++) sum += arr[i];
        if(diff > sum ||  (diff+sum)%2 !=0 ) return 0;
        int target = (sum+diff)/2;
        vector<vector<int>>dp(n ,vector<int>(target+1 ,0)); 
        
        for(int j = 0 ;j <= target ; j++ ){
            if(arr[0] == 0 && j == 0) dp[0][j] = 2;
            else if(j == arr[0]) dp[0][j] =1;
            else if(j ==0) dp[0][j] =1;
        }
        for(int i =1 ; i< n ;i++){
            for(int j = 0; j<= target ; j++){
                int notTake =  dp[i-1][j];
                int take = 0;
                if(arr[i] <= j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][target];
    }
};



// SPACE OPTIMIZATION


 int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n ;i++) sum += arr[i];
        if(diff > sum ||  (diff+sum)%2 !=0 ) return 0;
        int target = (sum+diff)/2;
        
        vector<int>prev(target+1 , 0);
        vector<int>curr(target+1 , 0); 
        for(int j = 0 ;j <= target ; j++ ){
            if(arr[0] == 0 && j == 0) prev[j] = 2;
            else if(j == arr[0]) prev[j] =1;
            else if(j ==0) prev[j] =1;
        }
        for(int i =1 ; i< n ;i++){
            for(int j = 0; j<= target ; j++){
                int notTake =  prev[j];
                int take = 0;
                if(arr[i] <= j){
                    take = prev[j-arr[i]];
                }
                curr[j] = take + notTake;
            }
              prev = curr;
        }
        return prev[target];
    }

