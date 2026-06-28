class Solution {
public:
    string removeDuplicates(string s) {
      
      string ans;

      for(int i=0;i<s.size();i++)
      {
        if(!ans.empty() && s[i]==ans.back())
        {
            ans.pop_back();
        }
        else ans.push_back(s[i]);
      }

      return ans;
      
      /* stack<char>st;
       string ans="";
       for(int i=0;i<s.length();i++)
       {
        if(!st.empty()&& s[i]==st.top())
        {
            st.pop();
        }
        else st.push(s[i]);
       }

       while(!st.empty())
       {
        ans+=st.top();
        st.pop();
       }
        reverse(ans.begin(),ans.end());
       return ans; */
    }
};