class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq; //max heap
        for(int i=0; i<3; i++){
            if(amount[i] != 0)
                pq.push(amount[i]);
        }
        int ans = 0;
        while(!pq.empty()){
            if(pq.size() > 1){
                ans++;
                int f = pq.top();
                pq.pop();
                int s = pq.top();
                pq.pop();
                if(f-1 > 0) pq.push(f-1);
                if(s-1 > 0) pq.push(s-1);
            }
            else{
                int tp = pq.top();
                ans += tp;
                break;
            }
        }
        return ans;
    }
};