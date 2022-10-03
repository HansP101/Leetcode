/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
/*
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int row=binaryMatrix.dimensions()[0];
        int col=binaryMatrix.dimensions()[1];
        int ans=INT_MAX;
        for (int i=0; i<row; i++){
            int leftbound=0, rightbound=col-1;
            while(leftbound<=rightbound){
                int pivot=(leftbound+rightbound)/2;
                if(binaryMatrix.get(i, pivot)==1){
                    rightbound=pivot-1;
                    ans=min(ans,pivot);
                }
                else{
                    leftbound=pivot+1;
                }
            }
     
         }
        if (ans==INT_MAX)
            return -1;
        return ans;
    }
};
*/
class Solution {
public:
int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        //get the dimensions
		
		int n = binaryMatrix.dimensions()[0];
        int m = binaryMatrix.dimensions()[1];
		
		//go as much left as you can, and then go downwards.
        int check = m-1;
        for(int i = 0;i<n;i++){
            while(check>=0 and binaryMatrix.get(i,check)==1){
                check--;
            }
        }
        return (check==m-1)?-1:check+1;
    }
};

