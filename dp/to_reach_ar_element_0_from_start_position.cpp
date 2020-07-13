class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        queue<int>q;
        q.push(start);
        set<int>s;
        
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            s.insert(i);
            if(arr[i]==0)
                return true;
            for(int j=-1;j<=1;j=j+2)
            {
                int n1=i+(j*arr[i]);
                if(n1>=arr.size())
                    continue;
                if(s.find(n1)!=s.end())
                     continue;
               s.insert(n1);
                q.push(n1);
            }
        }
        return false;
    }
};

/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.

