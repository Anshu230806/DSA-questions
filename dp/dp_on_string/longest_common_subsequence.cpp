// memoization

  int fn(int ind1 , int ind2 , string s1 , string s2 ,vector<vector<int>>& dp ){
        if(ind1 < 0 || ind2 < 0 ) return 0 ;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2] ){
            return dp[ind1][ind2] = 1+fn(ind1-1 , ind2-1 , s1 ,s2 , dp);
        }
        return dp[ind1][ind2] = max(fn(ind1-1 , ind2 , s1 , s2 , dp) , fn(ind1 , ind2-1 , s1 , s2 , dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size();
        int ind2 = text2.size();
        vector<vector<int>>dp(ind1, vector<int>(ind2 , -1));
        
      return  fn( ind1-1 , ind2-1, text1 , text2 , dp);
    }



    // TABULATION


      int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size();
        int ind2 = text2.size();
        vector<vector<int>>dp(ind1, vector<int>(ind2 , 0));
            for(int i = 0 ;i <ind1  ; i++){
                for(int j = 0 ; j < ind2 ; j++){
                    if(text1[i] == text2[j]){
                        if(i-1 < 0 || j-1 < 0){
                           dp[i][j] =1 ;
                        }
                        else{
                            dp[i][j] = 1 + dp[i-1][j-1];
                        }
                    }
                    else{
                        if(i-1 >=0 ){
                            dp[i][j] = dp[i-1][j];
                        }
                        if(j-1 >= 0 ){
                            dp[i][j] = max(dp[i][j] , dp[i][j-1]);
                        }
                    }
                }
            }
      return dp[ind1-1][ind2-1];
    }



    // space optimaization also can be done 


     int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size();
        int ind2 = text2.size();
        //vector<vector<int>>dp(ind1, vector<int>(ind2 , 0));
        vector<int>prev(ind2+1 , 0);
        vector<int>curr(ind2+1 , 0);
            for(int i = 0 ;i <ind1  ; i++){
                for(int j = 0 ; j < ind2 ; j++){
                    if(text1[i] == text2[j]){
                        if(i-1 < 0 || j-1 < 0){
                           curr[j] =1 ;
                        }
                        else{
                            curr[j] = 1 + prev[j-1];
                        }
                    }
                    else{
                        if(i-1 >=0 ){
                            curr[j] = prev[j];
                        }
                        if(j-1 >= 0 ){
                            curr[j] = max(curr[j] , curr[j-1]);
                        }
                    }
                }
                prev = curr ;
            }
      return prev[ind2-1];
    }