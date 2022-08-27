struct CoordVal{
    vector<int> coord;
    int dist;
};

struct Compare{
  bool operator()(CoordVal &a, CoordVal &b){return a.dist<b.dist;}; //maxHeap
  };

struct Solution{
    vector<vector<int>> kClosest(vector<vector<int>> & points, int k){
    vector<vector<int>> ans;
      priority_queue<CoordVal, vector<CoordVal>, Compare> pq;
      for(auto it: points){
            pq.push({{it[0],it[1]},it[0]*it[0]+it[1]*it[1]});
            if(pq.size()>k)
            pq.pop();
        }
      while(!pq.empty()){
        ans.push_back(pq.top().coord);
         pq.pop();
        }
    return ans;
    }
};
