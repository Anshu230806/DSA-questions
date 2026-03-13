  // same as finding  cnt_partition with given diff 
  // extra edge case ->   if(sum+diff <0 ) return 0;
  // arr[] = [1 1 1 1] , target = -1000
  int findTargetSumWays(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n ;i++) sum += arr[i];
        if(sum+diff <0 ) return 0;
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