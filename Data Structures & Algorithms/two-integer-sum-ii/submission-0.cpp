class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int l=0;
        int r = numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r] == target){
                result.push_back(l+1);
                result.push_back(r+1);
                break;
            }
            else if(numbers[l]+numbers[r] < target){
                l++;
            }
            else r--;
        }
        return result;
    }
};
