class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;

        for(int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.rbegin(), cars.rend()); // closest to target first

        stack<double> st;

        for(int i = 0; i < cars.size(); i++) {
            double time = cars[i].second;

            if(st.empty() || time > st.top()) {
                st.push(time); // new fleet
            }
            // time <= st.top() → joins existing fleet
        }
        return st.size();
    }
};