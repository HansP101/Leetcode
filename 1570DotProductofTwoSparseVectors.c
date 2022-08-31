public:
    vector<int> array;
    SparseVector(vector<int> &nums) {
        for(auto it: nums){
            array.push_back(it);
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans=0;
        for(int i=0; i<vec.array.size(); i++){
            ans+=array[i]*vec.array[i];
        }
        return ans;
    }
};
