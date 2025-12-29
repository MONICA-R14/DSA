class Solution {
public:
    bool isValid(string st) {
       stack<char>s;
       for(char c:st)
       {
        if(c== '('|| c== '[' || c== '{')
         s.push(c);

         if(c == ')'||c == ']'|| c == '}')
         {
            if(s.empty())
              return false;
            
            if(!compare(s.top() ,c))
            return false; 

            s.pop();    
         }
       } 
       return s.empty();
    }
    bool compare(char a,char b)
    {
        if(a=='(' && b==')') return true;
        if(a=='[' && b==']') return true;
        if(a=='{' && b=='}') return true;
        return false;
    }
};