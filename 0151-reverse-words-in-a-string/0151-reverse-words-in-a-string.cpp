class Solution {
public:
     string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }

        vector<string> words;
        string word;

        for (char c : s) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }

        // Add the last word if there is any
        if (!word.empty()) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Construct the result string
        stringstream ss;
        for (size_t i = 0; i < words.size(); ++i) {
            if (i != 0) {
                ss << " ";
            }
            ss << words[i];
        }
        return ss.str();
    }
};