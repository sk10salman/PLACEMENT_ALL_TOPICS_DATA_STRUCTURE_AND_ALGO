/*
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
*/

class MapSum {
    
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int result = 0;
        for(auto itr = m.begin();itr!=m.end();itr++){
            if(itr->first.length() < prefix.length())   continue;
            if(prefix == itr->first.substr(0, prefix.length())){
                result += itr->second;
            }
        }
        
        return result;}
}; 
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
