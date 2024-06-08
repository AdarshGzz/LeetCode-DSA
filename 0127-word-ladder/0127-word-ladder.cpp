class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(wordSet.find(endWord)==wordSet.end()) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int length = q.front().second;
            q.pop();

            if(word==endWord) return length;

            for(int i=0;i<word.size();i++){
                string newWord = word;
                for(char c='a';c<='z';c++){
                    newWord[i] = c;
                    if(wordSet.find(newWord)!= wordSet.end()){
                        q.push({newWord,length+1});
                        wordSet.erase(newWord);
                    }
                }
            }
        }
        return 0;
    }
};