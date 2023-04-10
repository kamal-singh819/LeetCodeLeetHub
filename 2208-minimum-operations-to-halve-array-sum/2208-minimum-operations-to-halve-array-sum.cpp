class Solution {
public:
    int halveArray(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        priority_queue<double> maxHeap;
        for(int i=0; i<n; i++){
            sum += nums[i];
            maxHeap.push((double)(nums[i]*1.0));
        }
        int ans = 0; //minimum operation needed
        double target = sum/2.0;
        double temp = sum*1.0;
        while(temp > target){
            ans++;
            double tp = maxHeap.top();
            maxHeap.pop();
            tp = tp/2.0; //half of top
            temp = temp - tp; //decrease from sum
            maxHeap.push(tp);  
        }
        return ans;
        
    }
};