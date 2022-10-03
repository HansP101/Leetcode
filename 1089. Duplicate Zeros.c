class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
       vector<int> sol{arr};
        int index=0;
       for (auto value : sol){
           arr[index]=value;
           if(++index == arr.size()) break;
           if(!value){
               arr[index]=value;
               if(++index==arr.size()) break;
           }
       }
    }
};
