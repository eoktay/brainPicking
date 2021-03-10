class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
      sort(tokens.begin(), tokens.end());
      int ret = 0;
      int score = 0;
      
      while(tokens.size() > 0) {
        while(tokens.size() > 0 && tokens[0] <= P) {
          P -= tokens[0];
          score++;
          ret = max(ret, score);
          tokens.erase(tokens.begin(), tokens.begin() + 1);
        }
        if (score == 0) {
          return ret;
        }
        if (tokens.size() > 0) {
          P += tokens[tokens.size() - 1];
          score--;
          tokens.erase(tokens.begin() + tokens.size() - 1);
        }
      }
      
      return ret;
      
    }
};
