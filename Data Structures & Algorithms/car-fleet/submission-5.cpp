class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars(speed.size(),{0,0});
        for(int i=0;i<speed.size();i++){
            cars[i] = {position[i],(double)(target-position[i])/speed[i]};
        }
        stack<double> st;
        sort(cars.rbegin(),cars.rend());
        for(int i=0;i<cars.size();i++){
            if(st.empty() || st.top() < cars[i].second){
                st.push(cars[i].second);
            }
        }
        return st.size();
    }
};
