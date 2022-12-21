if(nums.size() == 2 && nums[0] == 0 && nums[1] == 0){
            return nums;
        }
        int total_product = 1;
        int zero_product = 1;
        if(count(nums.begin(), nums.end(),0) == 1){
            total_product = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != 0){
                    zero_product *= nums[i];
                }

            }
        }
        else if(count(nums.begin(), nums.end(),0) >= 2){
            zero_product = 0;
            total_product = 0;
        }else{
            for(int i = 0; i < nums.size(); i++){
                total_product *= nums[i];
            }
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ans.push_back(zero_product);
            }else{
                ans.push_back(total_product/nums[i]);
            }
        }
        return ans;
        
        
    }
