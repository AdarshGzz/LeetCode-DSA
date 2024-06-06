class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freqMap;
        for(char i:s ){
            freqMap[i]++;
        }
        priority_queue<pair<int,char>> maxHeap;
        for(auto i:freqMap){
            maxHeap.push({i.second,i.first});
        }

        string result;
        while(!maxHeap.empty()){
            auto entry = maxHeap.top();
            maxHeap.pop();
            result.append(entry.first,entry.second);
        }
        return result;
    }
};