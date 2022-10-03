/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
class Solution{
    public:
int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        //get the dimensions
		
		int row = binaryMatrix.dimensions()[0]-1;
        int defCol = binaryMatrix.dimensions()[1]-1;
		int col=defCol;
		//Start from far left then go as much left as you can if meets 1, and then go downwards.
       
        while(row>=0){
            while(col>=0 and binaryMatrix.get(row,col)==1){
                col--;
            }
            row--;
        }
        return (col==defCol)?-1:col+1;
    }
};
