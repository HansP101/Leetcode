class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string subres;
        queue<string> mainQueue;
        queue<string> lineQueue;
        int numofwordsinLine=0, wordslengthinline=0;
        for(auto it: words){
            mainQueue.push(it);
        }
        while(!mainQueue.empty()){
            int gap, extra;
            auto takeOne=mainQueue.front();
            if(wordslengthinline+numofwordsinLine+takeOne.size()>maxWidth){
                int spaces=maxWidth-wordslengthinline;
                if(numofwordsinLine>1) gap=spaces/(numofwordsinLine-1), extra=spaces%(numofwordsinLine-1);
                else gap=spaces,extra=0;      
                while(lineQueue.size()>1){
                    subres+=lineQueue.front();
                    subres += string(gap, ' '), spaces -= gap;
                    if (extra) subres += ' ', extra--, spaces--;
                    lineQueue.pop();  
                }
                   subres+=lineQueue.front();
                    subres+=string(spaces, ' ');
                    lineQueue.pop(); 
                   res.push_back(subres);
                numofwordsinLine=0;
                wordslengthinline=0;
                subres={};
            } 
            numofwordsinLine++;
             wordslengthinline+=takeOne.size();
            lineQueue.push(takeOne);
            mainQueue.pop();
        }
        if(!lineQueue.empty()){
            int spaces=maxWidth-wordslengthinline;
            while(lineQueue.size()>1){
                subres+=lineQueue.front();
                subres+=string(1, ' ');
                lineQueue.pop();
                spaces--;
            }
            subres+=lineQueue.front();
            lineQueue.pop();
            subres+=string(spaces,' ');
            res.push_back(subres);
        }
        return res;
    }
};
