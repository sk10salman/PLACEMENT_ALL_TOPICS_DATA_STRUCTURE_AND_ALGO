class Solution {
public:
    unsigned int countSetBits(unsigned int n) 
{ 
    unsigned int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 
    vector<int> countBits(int num) {
        vector<int>v;
        for(int i=0;i<=num;i++)
            v.push_back(countSetBits(i));
        return v;
    }
};
