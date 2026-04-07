#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans; // Final results store karne ke liye
        queue<pair<string, int>> q; // BFS ke liye: {word, current_step}
        q.push({beginWord, 1});
        
        // mpp store karega: kaunsa word kis 'level' (distance) par hai
        unordered_map<string, int> mpp;
        mpp[beginWord] = 1;

        // Set for quick lookup (O(1)) and erasing words
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord); // Pehle word ko set se hata do

        // STEP 1: BFS - Nakshe (Map) par levels mark karna
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Agar endWord mil gaya, toh aage BFS karne ki zaroorat nahi
            // Lekin loop break karenge taaki usi level ke baaki words process ho jayein
            if (word == endWord) break;

            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        // Word mil gaya! Iska level mark karo aur queue mein daalo
                        st.erase(word);
                        q.push({word, steps + 1});
                        mpp[word] = steps + 1; 
                    }
                }
                word[i] = original; // Word ko wapas sahi karo agle transformation ke liye
            }
        }

        // STEP 2: DFS (Backtracking) - Peeche se rasta dhundhna
        // Agar endWord tak pahunch hi nahi paye (mpp mein nahi hai), toh khali ans return hoga
        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord); // Ulta shuru kar rahe hain: endWord se beginWord
            dfs(endWord, seq, ans, beginWord, mpp); 
        }

        return ans;
    }

private:
    void dfs(string word, vector<string>& seq, vector<vector<string>>& ans, string b, unordered_map<string, int>& mpp){
        // BASE CASE: Agar hum shuruat (beginWord) tak pahunch gaye
        if(word == b){
            reverse(seq.begin(), seq.end()); // Kyunki hum ulta chale the, rasta seedha karo
            ans.push_back(seq);              // Seedha rasta final answer mein daalo
            reverse(seq.begin(), seq.end()); // Backtrack: Wapas ulta kar do taaki baaki paths check ho sakein
            return;
        }

        int steps = mpp[word]; // Current word ka level kya hai?
        
        // Padosi dhundho jo exactly ek level pehle (steps - 1) ho
        for(int i = 0; i < word.size(); i++){
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                
                // Sabse zaroori condition: Kya ye word map mein hai AUR kya iska level steps-1 hai?
                if(mpp.find(word) != mpp.end() && mpp[word] == steps - 1){
                    seq.push_back(word);      // Raste mein is word ko likho
                    dfs(word, seq, ans, b, mpp); // Gehrai mein jao agle word ke liye
                    seq.pop_back();           // BACKTRACK: Wapas aate waqt word ko hatao (Naya rasta dhundhne ke liye)
                }
            }
            word[i] = original;
        }
    }
};