class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        int maxLeft = height[l];
        int maxRight = height[r];
        while(l<r){
            int areaL = min(maxLeft,maxRight) - height[l];
            int areaR = min(maxLeft,maxRight) - height[r];
            if(height[l]<height[r]){
                maxLeft = max(maxLeft,height[l]);
                res += maxLeft - height[l];;
                l++;
            }
            else{
                maxRight = max(maxRight,height[r]);
                res += maxRight- height[r];
                r--;
            }
        }
        return res;
    }
};
