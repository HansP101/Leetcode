class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        long long minCutsSize=1;
        long long MaxCutsSize=0;
        long long MidCutsSize=0;
        long long totalSize=0;
        for(auto it: ribbons){
            MaxCutsSize+=it;
        }
        if(MaxCutsSize<k) return 0;

        while(minCutsSize<=MaxCutsSize){ // Binary Search 같을때에도 이 루프를 타겠다는 얘기, 끝날대는 min 이 더 큰것 , min을 더해줄것이니까. 우리가 원하는 것은 중간값이 니까. return Max
            MidCutsSize=(minCutsSize+MaxCutsSize)/2;
            long long numOfSameRibbons=0;
            
            for(auto it: ribbons){
                numOfSameRibbons+=it/MidCutsSize;
            }
         /*
            if(numOfSameRibbons>k) minCutsSize=MidCutsSize+1; 
            else if(numOfSameRibbons<k) MaxCutsSize=MidCutsSize-1;
            else if (numOfSameRibbons==k) return MidCutsSize;
          */  
                 
             if(numOfSameRibbons<k) MaxCutsSize=MidCutsSize-1;
            else minCutsSize=MidCutsSize+1; 
        
        }
        return MaxCutsSize;
    }
};
