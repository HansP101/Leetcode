class Logger {
public:
    unordered_map<string, int> hashMap;
    Logger() {
                
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto it=hashMap.find(message);
        if(it!=hashMap.end()){
            if (it->second<=timestamp){
                it->second=timestamp+10;
                return true;
            }
            else 
                return false;
        }
        else{
            hashMap[message]=timestamp+10;
            return true;
             }
    }
            
};
