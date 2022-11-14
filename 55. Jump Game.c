  //DP  
  bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> jump(n,false);
        jump[n-1]=true;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=nums[i] && i+j<n;j++)
            {
                if(jump[i+j]==true) 
                {
                    jump[i]=true; 
                    break;
                }
            }
        }
        
        return jump[0];
    }
//Greedy
    bool canJump(vector<int>& nums) {
      int n = nums.size(), farest = 0;
      for(int i = 0;i < n; i++)
      {
        if(farest < i) return false;
        farest = max(i + nums[i], farest);
      }
      
      return true;
    }
