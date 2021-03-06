class Compare {
  public:
  bool operator()(vector<int> & a, vector<int> & b){
    if (a[0] >= b[0]) {
      return true;
    }
    return false;
  }
  
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
      
        for (int i = 0; i < nums1.size(); i++) {
          for (int j = 0; j < nums2.size(); j++) {
            pq.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
          }
        }
        
        while(!pq.empty() && k > 0) {
          vector<int> top = pq.top();
          pq.pop();
          
          ret.push_back({top[1], top[2]});
          k--;
        }
      
        return ret;
    }
};
