class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        long long  ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            priority_queue<long long>pq1;
            priority_queue<long long,vector<long long>,greater<long long>>pq2;
            for(int j=i;j<n;j++)
            {
                pq1.push(nums[j]);
                pq2.push(nums[j]);
                ans+=(pq1.top()-pq2.top());
            }
        }
        return ans;
    }
};

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long int sum = 0;
        int n = nums.size();
    
        for (int i = 0; i < n; i++) {
            int mn = nums[i];
            int mx = nums[i];
        
            for (int j = i; j < n; j++) {

                if(nums[j]>mx)
                {
                    mx = nums[j];
                }
                if(nums[j]<mn)
                {
                    mn = nums[j];
                }
                sum = sum + (mx - mn);
			}
		}
		return sum; 
	   }
   };
