class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        priority_queue<int> pq; //maxheap
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(pq.size() > 1){
            ans++;
            int f = pq.top(); pq.pop();
            int s = pq.top(); pq.pop();
            if(f-1 > 0) pq.push(f-1);
            if(s-1 > 0) pq.push(s-1);
        }
        return ans;
    }
};