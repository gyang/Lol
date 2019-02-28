class Solution {
public:
    int maxProfit(int k, vector<int>& ps) {
        if(k==0 || ps.size()<2)
        {
            return 0;
        }
        
        int n = ps.size();
        if(k>=n/2)
        {
            return tryMost(ps);
        }
        
        vector<vector<int>> buy(k+1, vector<int>(n+1, INT_MIN));
        vector<vector<int>> sell(k+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=k; i++)
        {
            for(int j=0; j<n; j++)
            {
                buy[i][j+1] = max(buy[i][j], sell[i-1][j+1] - ps[j]);
                sell[i][j+1] = max(sell[i][j], buy[i][j+1] + ps[j]);
            }
        }
        
        return sell[k][n];
    }
    
    int tryMost(vector<int>& ps)
    {
        int n = ps.size();
        int result = 0;
        for(int i=1; i<n; i++)
        {
            if(ps[i]>ps[i-1])
            {
                result += ps[i]-ps[i-1];
            }
        }
        
        return result;
    }
};