//* https://leetcode.com/problems/frequency-tracker/description/

class FrequencyTracker {
public:
    map<int,int> mp;
    map<int,int> mpp;
    FrequencyTracker() {
    }
    
    void add(int number) {
        if(mpp.find(number) != mpp.end()){
            mp[mpp[number]]--;
            if(mp[mpp[number]] == 0){
                mp.erase(mpp[number]);
            }
        }
        mpp[number]++;
        mp[mpp[number]]++;
    }
    
    void deleteOne(int number) {
        if(mpp.find(number) != mpp.end()){
            mp[mpp[number]]--;
            if(mp[mpp[number]] == 0){
                mp.erase(mpp[number]);
            }
            mpp[number]--;
            if(mpp[number] == 0){
                mpp.erase(number);
            }
            else{
                mp[mpp[number]]++;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return mp.find(frequency) != mp.end();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */