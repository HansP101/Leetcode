struct Solution{

    struct Tag{
     int id;
     bool start;
     int timestamp;
     };
 
 vector<int> exclusiveTime(int n, vector<string>& logs) { 
     stack<Tag> TagStack;
     vector<int> array(n,0);

      for(auto it: logs){
        Tag curTag;
        identifyTag(it, curTag);
        if(curTag.start==true) TagStack.push(curTag);
        else {
         auto stackTop=TagStack.top();
         TagStack.pop();
         assert(stackTop.id==curTag.id);
         int timeCal=curTag.timestamp-stackTop.timestamp+1;
         array[curTag.id]+=timeCal;
            if(TagStack.size()){
                array[TagStack.top().id]-=timeCal;
            }
       }
      }
      return array;
 }
    
    
 void identifyTag(string s, Tag& tag){
    string temp;
     stringstream ss(s);
    getline(ss, temp, ':');
    tag.id=stoi(temp);   
    getline(ss, temp, ':');
    if(temp=="start") tag.start=true;
     else tag.start=false;
    getline(ss, temp,' ' );
    tag.timestamp=stoi(temp);
}
};
      
