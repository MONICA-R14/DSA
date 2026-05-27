class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //https://chatgpt.com/share/6a166d49-c58c-83a8-9578-64f32b097df1
        if(s1.length()>s2.length())
        return false;

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(char c:s1)
        {
            freq1[c - 'a']++;
        }
        //first window
        int k=s1.length();
        for(int i=0;i<k;i++)
        {
            freq2[s2[i] - 'a']++;
        }

        if(freq1==freq2) return true;

        //other windows so start from n index
        for(int i=k;i<s2.length();i++)
        {
            freq2[s2[i] - 'a']++; //add new letter to window at last and remove first letter from window
            freq2[s2[i-k] - 'a']--;
            if(freq1==freq2) return true;
        }
        return false;
        
        /*int sum=0;int cal=0;
        for(char c:s1)
        {
            sum+=c;
        }
        int i=0;
        for(int j=s1.length()-1; j<s2.length();j++)
        {
            int x=i;
            while(x<=j)
            {
                cal+=s2[x++];
            }
            if(sum==cal)return true;
            else cal=0;
            i++;
        }return false;*/
    }
};