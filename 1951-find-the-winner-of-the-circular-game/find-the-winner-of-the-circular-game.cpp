class Solution {
public:

    int findTheWinner(int n, int k ) {
        return josephus(n,k)+1;
    }
    int josephus(int n,int k)
    {
        if(n==1)
        return 0;

        return (josephus(n-1,k) + k)%n;
    }
    /* vector<int>person;
     int index=0;
    int findTheWinner(int n, int k ) {
        for(int i=0;i<n;i++)
        {
            person.push_back(i);
        }
        return recurssion(person,n,k);
    }
    int recurssion(vector<int>person,int n,int k)
    {
        if(n==1)
        return person[0]+1;
        index=(index+k-1)%n;
        person.erase(person.begin() + index);
        return recurssion(person,n-1,k);
        
    }*/
};