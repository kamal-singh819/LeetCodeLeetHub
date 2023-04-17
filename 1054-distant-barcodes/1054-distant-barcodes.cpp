class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> count(10001, 0);
        int n = barcodes.size();
        for(int i=0; i<n; i++) count[barcodes[i]]++;
        
        priority_queue<pair<int, int>> pq; //max heap
        for(int i=0; i<10001; i++){
            if(count[i] != 0) pq.push({count[i], i}); //push count and no. into heap
        }
        int k = 0;
        while(pq.size() > 1){
            auto tp1 = pq.top(); pq.pop();
            barcodes[k++] = tp1.second;
            tp1.first--;
            
            auto tp2 = pq.top(); pq.pop();
            barcodes[k++] = tp2.second;
            tp2.first--;
            //again push into heap after decrement count
            if(tp1.first > 0) pq.push({tp1.first, tp1.second});
            if(tp2.first > 0) pq.push({tp2.first, tp2.second});
        }
        if(!pq.empty()){
            barcodes[k] = pq.top().second;
            pq.pop();
        }
        return barcodes;
    }
};