#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{     
  //Your code here 
  stack<pair<char, int>> s;
  for(int i = 0; i < src.size(); i++){
      char ch = src[i];
      if(s.empty()){
          s.push({ch, 1});
      }else{
          if(s.top().first == ch){
            int cnt = s.top().second + 1;
            s.pop();
            s.push({ch, cnt});
          }else{
            s.push({ch, 1});
          }
      }
  }
  
  string res = "";
  while(!s.empty()){
      char ch = s.top().first;
      int cnt = s.top().second;
      s.pop();
      
      res = (ch + to_string(cnt)) + res;
  }
  return res;
}  