class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
  string a,b;
  for(string x:word1){
      a=a+x;
  }
  for(string y:word2){
      b=b+y;
  }
  if(a==b){
      return true;
  }
  else
  return false;
    }
};
