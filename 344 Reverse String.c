class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
        
        return s;
    }
};

// not to use reverse(s.begin(), s.end());

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverseString(string &inStr){
  for(int i=0,j=inStr.size()-1;i<j; i++, j--){
      swap(inStr[i], inStr[j]);
  }
}

int main(){ 
    string inStr="HELLO";
    reverseString(inStr);
    printf("%s",inStr.c_str());
    return 0;
}
