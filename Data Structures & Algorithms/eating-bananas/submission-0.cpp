class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k = 0;
        while(l<=r){
            int time = 0;
            k = l + (r-l)/2;
            for(int i = 0;i<piles.size();i++){
                if(piles[i]%k == 0) time += piles[i]/k;
                else time += piles[i]/k + 1;
            }
            if(time<=h){
                r = k-1;
            }
            else{
                l = k+1;
            }
        }
        return l;
    }
};
