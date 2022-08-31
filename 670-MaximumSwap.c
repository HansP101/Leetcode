class Solution {
public:
    int maximumSwap(int num) {
        string temp=to_string(num);
        if (temp.size()<=1) return num;
        string sortedTemp=temp;
        sort(sortedTemp.begin(), sortedTemp.end(), [](auto &a, auto&b){return a>b;});
       
        int first=0, second=0;
        char target;
        for(first, second; first<temp.size() and second<temp.size(); ){
            if(temp[first]==sortedTemp[second])
            {first++;
             second++;}
            else {
                target=sortedTemp[second];  
                break;
              }
        }
        
        if (first==temp.size()) return stoi(temp);
        
        for(int i=first; i<temp.size(); i++){
            if(temp[i]==target) second=i;
        }

        swap(temp[first], temp[second]);
        return stoi(temp);
    }
};\

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
