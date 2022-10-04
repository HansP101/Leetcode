 string minWindow(string s, string t) {
        // Initialize minl as INT_MAX
        int minl = INT_MAX;
        
        // Map to keep count of all characters of t 
        unordered_map <int, int> mp;
        for(auto ch: t) mp[ch]++;
        
        // Sliding Window Approach
        // Let c be the count of chars of t in a particular window. Initialize as 0
        // start be the start of the current window
        // end be the end of current window
        // minstart be the start for the minimum window found yet.
        
        int c = 0;
        
        int start = 0;
        int minstart = 0;
        
        for(int end = 0; end<s.length(); end++)
        {
            if(mp[s[end]]>0) c++;
            mp[s[end]]--; 
            
            // continue untill c equals length of t or when current window has all characters of t in it
            if(c==t.length())
            {
                // Note that negative values in map indicate the key char is not present in t, but present in s. And hence leading chars in s with negative values are insignificant.
                
                while(start<end && mp[s[start]]<0){
                    mp[s[start]]++;
                    start++;
                }
                
                if(end-start+1<minl)
                {
                    minl = end-start+1;
                    minstart = start;
                }
                
                // reduce the window size by incrementing start, reducing mp[s[start]] value, and reducing c
    
                mp[s[start]]++;
                start++;
                c--;
            }
        }
        
        if(minl==INT_MAX) return "";
        return s.substr(minstart, minl);
