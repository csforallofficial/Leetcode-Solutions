void generate(string temp , int last , int low , int high, int n ,int m , vector<int>& ans)
{
    if(n > m )
        return;
    
    if(stoi(temp)>=low && stoi(temp)<=high)
        ans.push_back(stoi(temp));
    
    string temp2 = temp + to_string(last);
    if(last == 10)
        return;
    for(int i = last ;i<=9;i++)
    {
        string s = "";
        for(int j = 1 ; j < last-1;j++)
            s = s + temp[j];
        temp = s + to_string(i);
        
        int num = stoi(temp);
        
        cout<<num<<endl;
        
        if(num >=low&& num<=high)
            ans.push_back(num);
    }
    cout<<temp2<<endl;
    generate(temp2 , last+1,low , high , n+1, m , ans);
}
class Solution {
public:
    vector<int> sequentialDigits(int low, int high){
        int n = 0,m=0;
     
        string s = to_string(low);
        n = s.size();
        s = to_string(high);
        m = s.size();
        
        string temp = "";
        for(int j = 1;j<=n;j++)
            temp = temp + to_string(j);
        vector<int> ans;
        cout<<temp<<endl;
        
        generate(temp , n+1,low , high , n , m , ans);
        return ans;
        
            
        
    }
};