class Solution {
public:
    void backtrack(vector<vector<int>>&result,int index, vector<int>&arr)
    {
        if(index==arr.size()-1)
        {
            result.push_back(arr);
            return;
        }
        unordered_set<int>s;
        for(int i=index;i<arr.size();i++)
        {
            if(s.find(arr[i])==s.end())
            {
                swap(arr[index],arr[i]);
                backtrack(result,index+1,arr);
                swap(arr[i],arr[index]); //backtrack;
                s.insert(arr[i]);
            }
        }
       
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        if(nums.size()==0)
             return result;
       vector<int>row;
        backtrack(result,0,nums);
        return result;
        
    }
};

/*
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
