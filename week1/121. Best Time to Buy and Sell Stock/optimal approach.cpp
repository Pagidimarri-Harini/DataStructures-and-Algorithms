int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxprofit = 0;
        for(int i = 0; i < prices.size()-1; i++){
            profit = max(profit+(prices[i+1]-prices[i]),0);
            maxprofit = max(maxprofit, profit);
            
        }
        return maxprofit;
        
}
