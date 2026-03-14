  // memoization
  // this not work bcz time limit exceeds
  int fn(int i ,int capacity , vector<int>& val , vector<int>& wt,
    vector<vector<int>>& dp){
        if(i == 0){
            if(wt[0] <= capacity){
                return dp[i][capacity]=val[0]*(capacity/wt[0]);
            }
            return dp[i][capacity]=0;
        }
        int notTake = 0 + fn(i-1 , capacity , val , wt , dp);
        int take = INT_MIN;
        if(wt[i] <= capacity){
            take = val[i] + fn(i , capacity-wt[i] , val , wt ,dp);
        }
        return dp[i][capacity] =max(take , notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n , vector<int>(capacity+1 , -1));
        fn(n-1 , capacity , val , wt ,dp);
        return dp[n-1][capacity];
    }



    // Tabulation


       int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n , vector<int>(capacity+1 , 0));
        
        for(int i=0; i <= capacity ;i++){
            if(wt[0] <= i){
                dp[0][i] = val[0]*(i/wt[0]);
            }
        }
        
        for(int i=1 ; i< n ;i++){
            for(int j = 0; j<= capacity ;j++){
                int notTake = 0 + dp[i-1][j];
                int take = INT_MIN;
                if(wt[i] <= j ){
                    take = val[i]+ dp[i][j-wt[i]];
                }
                dp[i][j] = max(take , notTake);
            }
        }
        return dp[n-1][capacity];
    }

    // SPACE OPTIMIZATION


       int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        //vector<vector<int>>dp(n , vector<int>(capacity+1 , 0));
        
        vector<int>prev(capacity+1 , 0);
        vector<int>curr(capacity+1, 0);
        for(int i=0; i <= capacity ;i++){
            if(wt[0] <= i){
                prev[i] = val[0]*(i/wt[0]);
            }
        }
        
        for(int i=1 ; i< n ;i++){
            for(int j = 0; j<= capacity ;j++){
                int notTake = 0 + prev[j];
                int take = INT_MIN;
                if(wt[i] <= j ){
                    take = val[i]+ curr[j-wt[i]];
                }
                curr[j] = max(take , notTake);
            }
            prev = curr;
        }
        return prev[capacity];
    }