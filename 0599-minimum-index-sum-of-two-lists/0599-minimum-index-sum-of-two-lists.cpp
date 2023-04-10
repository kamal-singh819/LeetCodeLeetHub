class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp; //stores string with index of list1
        for(int i=0; i<list1.size(); i++) mp[list1[i]] = i;
        vector<string> ans;
        int sum = INT_MAX;
        for(int i=0; i<list2.size(); i++){
            if(mp.count(list2[i])){
                int indexsum = mp[list2[i]] + i;
                if(sum > indexsum){
                    ans.clear();
                    ans.push_back(list2[i]);
                    sum = indexsum;
                }else if(sum == indexsum) ans.push_back(list2[i]);
            }
        }
        return ans;  
    }
};