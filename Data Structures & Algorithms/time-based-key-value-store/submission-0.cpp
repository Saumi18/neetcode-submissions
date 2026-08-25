class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        if(!mp.count(key)) return "";
        vector<pair<string,int>>& v = mp[key];
        int l=0, r = v.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid].second<=timestamp){
                res = v[mid].first;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }
};
