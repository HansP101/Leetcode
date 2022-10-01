class Solution {
public:
    int maxArea(vector<int>& height) {
        int areaMax=0;
        int left=0;
        int right=height.size()-1;
        
        while(left<right){
            int area=(right-left)*min(height[left], height[right]);
            areaMax=max(areaMax, area);
            if(height[left]<height[right])
                left++;
            else right--;
        }
        return areaMax;
        
    }
};
