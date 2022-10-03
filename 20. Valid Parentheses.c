class Solution {
public:
    bool isValid(string s) {
        unordered_map <char, char> HashTable;
        HashTable['}'] = '{';
		HashTable[')'] = '(';
		HashTable[']'] = '[';
       
        stack<char> myStack;
        
        if ((s[0]=='(' )|| (s[0]=='{')|| (s[0]=='['))
         myStack.push(s[0]);
        else
            return false;
        for (int i =1; i<s.size();i++){
            if ((s[i]=='(' )|| (s[i]=='{')|| (s[i]=='['))
                myStack.push(s[i]);
               else{
                   auto it = HashTable.find(s[i]);
                   if (!myStack.empty() && (myStack.top()==it->second))
                   myStack.pop();
                   else 
                       return false;
               }     
        }
      if (myStack.empty())
          return true;
        else
            return false;       
        
    }
};
