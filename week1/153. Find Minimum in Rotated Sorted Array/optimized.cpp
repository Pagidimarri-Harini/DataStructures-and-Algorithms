int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int  ans;
        while(start < nums.size()){
            if(nums[start] <= nums[end]){
                ans = nums[start];
                break;
            }else{
                start += 1;
            }
        }
        return ans;
 }
