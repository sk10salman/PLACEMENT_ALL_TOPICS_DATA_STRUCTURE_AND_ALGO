class Solution {
public:
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
        
        vector<char> hexDigits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        
        unsigned int unsignedNum = 0;
        
        unsignedNum = (unsignedNum | num);  // if(num is neggetive than or 0 should do 2s complement otherwise its original num
        cout<<unsignedNum<<" ";
        string ans = "";
        
        int mask = 15;
        
        while(unsignedNum != 0){
            int temp = (unsignedNum & mask);
            
            ans = hexDigits[temp] + ans;
            
            unsignedNum = (unsignedNum >> 4);
        }
        
        return ans;
    }
};

/*
Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
