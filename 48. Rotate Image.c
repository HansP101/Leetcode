class Solution {
public:
   void rotate(vector<vector<int>> &M) {
	int n = M.size();
	// first find reverse matrix (inplace)
	reverse(M.begin(), M.end());
	// then find transpose (inplace)
	for (int r = 0; r < n; r++)
		for (int c = r; c < n; c++)
			swap(M[r][c], M[c][r]);
  }
};
