class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int n = barcodes.length;
        int m = 10001;
        int[] count = new int[m];
        Arrays.fill(count, 0);
        
        int mxCount = 0, mxNum = 0;
        for(int i=0; i<n; i++){
            count[barcodes[i]]++;
            if(count[barcodes[i]] > mxCount){
                mxCount = count[barcodes[i]];
                mxNum = barcodes[i];
            }
        }
        
        int pos = 0;
        for(int i=0; i<m; i++){
            int num;
            if(i == 0) num = mxNum;
            else num = i;
            while(count[num]-- > 0){
                barcodes[pos] = num;
                pos = pos+2 < n ? pos+2 : 1;
            }
        }
        return barcodes;
    }
}