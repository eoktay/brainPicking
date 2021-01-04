class Solution {
public:
    int reverse(int x) {
        string rev = to_string(x);
        // cout << rev << endl;
        if (x < 0)
        {
          std::reverse(rev.begin() + 1, rev.end());
          rev = rev.substr(1);
        }
        else
          std::reverse(rev.begin(), rev.end());
      
        if (x > 0 && 
            to_string(INT_MAX).size() == rev.size())
        {
          if (rev > to_string(INT_MAX))
            return 0;
        }
      
        if (x < 0 && 
            to_string(INT_MIN).substr(1).size() == rev.size())
        {
          if (rev > to_string(INT_MIN).substr(1))
            return 0;
        }
      
        if (x < 0)
          return -1 * stoi(rev);
      
        return stoi(rev);
    }
};
