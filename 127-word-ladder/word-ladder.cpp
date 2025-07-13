class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;

        q.push({beginWord,1});
        dict.erase(beginWord);
        
        while(!q.empty())
        {
            string word=q.front().first;
            int len=q.front().second;
            q.pop();

            if(word==endWord)
            {
                return len;
            }
            for(int i=0;i<word.size();i++)
            {
                char ch=word[i];
                for(int j=0;j<26;j++)
                {
                    word[i]='a'+j;
                    if(dict.find(word)!=dict.end())
                    {
                        q.push({word,len+1});
                        dict.erase(word);
                    }
                }
                word[i]=ch;
            }
        }
        return 0;
    }
};