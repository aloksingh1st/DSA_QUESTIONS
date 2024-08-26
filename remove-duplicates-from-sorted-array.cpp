class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
     int n = arr.size();   
      set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
    }
};