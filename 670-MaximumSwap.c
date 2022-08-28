class Solution {
public:
    int maximumSwap(int num) {
        string temp=to_string(num);
        int fr=0, to=0;
        bool found=false;
        for(int i=0; found==false and i<temp.size()-1; i++){
            for(int j=i+1; j<temp.size(); j++){
                if(temp[i]<temp[j]){
                    fr=i;
                    found=true; //wherever has bigger than current value then stop so that current index is from.
                    break;}
            }
        }
        int maxV=0;
        for(int i=fr; i<temp.size(); i++){
            if(temp[i]>=maxV) //keep moving to right if there is same number happened.
                to=i, maxV=temp[i];
        }
        swap(temp[fr], temp[to]);
        return stoi(temp);
    }
};

class Solution {
public:
    int maximumSwap(int num) {
        string temp=to_string(num);
        int fr=0, to=0;
        bool found=false;
        for(int i=0; found==false and i<temp.size()-1; i++){
            for(int j=i+1; j<temp.size(); j++){
                if(temp[i]<temp[j]){
                    fr=i;
                    found=true;
                    break;}
            }
        }
        int maxV=0;
        for(int i=fr; i<temp.size(); i++){
            if(temp[i]>=maxV)
                to=i, maxV=temp[i];
        }
        swap(temp[fr], temp[to]);
        return stoi(temp);
    }
};
