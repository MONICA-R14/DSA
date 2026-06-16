class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int maxarea=0;
       stack<int>st;
        int n=heights.size();
       for(int i=0;i<=n;i++)
       {
        int h = (i==n)?0:heights[i];
        while(!st.empty() && h<heights[st.top()])
        {
            int h=heights[st.top()]; st.pop();
            int w=(st.empty())? i : i-st.top()-1;

            int area=h*w;
            maxarea=max(maxarea,area);
        }
        st.push(i);
       }
       return maxarea;

    }
};