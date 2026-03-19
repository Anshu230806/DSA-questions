class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n= nums.size();
        if(n <= 3) return n;
        vector<int>left(n);
        vector<int>right(n);
        left[0] =1;
        int cd = nums[1]-nums[0];
        for(int i=1 ; i< n ; i++){
            int diff = nums[i]-nums[i-1];
            if(diff == cd ){
                left[i] = left[i-1]+1;
            }
            else{
                cd = diff;
                left[i] = 2;
            }
        }
        right[n-1] = 1;
         cd = nums[n-1]-nums[n-2];
        for(int i = n-2 ; i>= 0; i--){
            int diff = nums[i+1]-nums[i];
            if(cd == diff){
                right[i]= right[i+1]+1;
            }
            else{
                right[i] =2;
                cd = diff;
            }
        }
        int largest = 2;
        largest = max( largest , 1+left[n-2]);
        largest = max( largest , 1+right[1]);
        for(int i = 1 ; i< n-1 ;i++){
            largest = max( largest , left[i-1]+1);
            largest = max( largest , right[i+1]+1);
            if( (nums[i-1]+nums[i+1])%2 == 0){
                int diff = nums[i-1]-(nums[i-1]+nums[i+1])/2;
                int leftLen = 1;
                int rightLen = 1;
                 if( i-2 >= 0 && nums[i-2]-nums[i-1] == diff){
                    leftLen = left[i-1];
                 }
                 if(i+2 < n && nums[i+1]-nums[i+2] == diff){
                    rightLen = right[i+1];
                 }
                  largest = max( largest , leftLen+rightLen+1);
            }
       
        }
      return largest;
    }
};