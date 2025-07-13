class Solution {
public:
    vector<vector<string>>ans;
    unordered_map<string,int>mp;
    string startWord;
    
    void dfs(string word,vector<string>&seq,int size)
    {
        if(word==startWord)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mp[word];

        for(int i=0;i<size;i++)
        {
            char ch=word[i];
            for(int j=0;j<26;j++)
            {
                word[i]='a'+j;
                if(mp.find(word)!=mp.end() && mp[word]+1==steps)
                {
                    seq.push_back(word);
                    dfs(word,seq,size);
                    seq.pop_back();
                }
            }
            word[i]=ch;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        startWord=beginWord;

        mp[startWord]=1;
        s.erase(beginWord);

        queue<string>q;
        q.push(startWord);

        while(!q.empty())
        {
            string word=q.front();
            int steps=mp[word];
            q.pop();

            if(word==endWord)
            {
                break;
            }

            for(int i=0;i<word.size();i++)
            {
                char ch=word[i];
                for(int j=0;j<26;j++)
                {
                    word[i]='a'+j;
                    if(s.find(word)!=s.end())
                    {
                        q.push(word);
                        mp[word]=steps+1;
                        s.erase(word);
                    }
                }
                word[i]=ch;
            }
        }

        
        if(mp.find(endWord)!=mp.end())
        {
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq,startWord.size());
            
        }
        return ans;
    }
};