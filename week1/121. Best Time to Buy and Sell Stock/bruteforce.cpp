int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i+1; j < prices.size(); j++){
                maxprofit = max(maxprofit, prices[j] - prices[i]);
            }
        }
        return maxprofit;
        
 }
