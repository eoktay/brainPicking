class Solution {
public:
  
    vector<string> getAllPos(int start, int end, string S) {
      vector<string> ret;
      if (start == end) {
        string newWord = string(1, S[start]);
        ret.push_back(newWord);
      }
      else if (S[start] == '0' && S[end] == '0') {
        return ret;
      }
      else if (S[start] == '0' && S[end] != '0') {
        ret.push_back("0." + S.substr(start + 1, end));
        return ret;
      }
      else if (S[start] != '0' && S[end] == '0') {
        ret.push_back(S.substr(start, end - start + 1));
        return ret;
      }
      else {
        for (int i = start; i < end; i++) {
          ret.push_back(S.substr(start, i - start + 1) 
          + '.' + S.substr(i + 1, end - i));
        }
        ret.push_back(S.substr(start, end - start + 1));
      }
      
      
      return ret;
    }
    
  
    vector<string> ambiguousCoordinates(string S) {
      vector<string> ret;
      S = S.substr(1, S.size() - 2);
      for (int i = 0; i < S.size() - 1; i++) {
        vector<string> firstPos = getAllPos(0, i, S);
        vector<string> secondPos = getAllPos(i + 1, S.size() - 1, S);
        
        for (int k = 0; k < firstPos.size(); k++) {
          for (int l = 0; l < secondPos.size(); l++) {
            ret.push_back("(" + firstPos[k] + ", " + secondPos[l] + ")");
          }
        }
      
      }
      return ret;
    }
};
