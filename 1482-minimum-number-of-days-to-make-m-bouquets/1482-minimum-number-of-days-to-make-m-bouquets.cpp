class Solution {
public:
    
    bool is_possible(vector<int>&arr,int m,int k,int mid)
    {
        int flower=0;
        int boque=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=mid)//checking the flowe which are ready in mid of day
            {
                flower++;//adding flower var
                if(flower==k)//if we get flower ==k we make a boque and add to it.
                {
                    boque++;
                    flower=0;//and making flower count=0;
                }
            }
            else//if we get any array greater than mid then we leave the flower and make flower value=0
            {
                flower=0;
            }
        }
        if(boque>=m)//checking is we are able to make m boque or not..
        {
            return 1;
            
        }
        return 0;
    }
    
 
    int minDays(vector<int>& arr, int m, int k) {
        
        int n=arr.size();
        if(m*k>n)
        {
            return -1;
        }
		//checking corner cases
        
        int mini=*min_element(arr.begin(),arr.end());//minimum time
        int maxi=*max_element(arr.begin(),arr.end());//maximum time
        //applying generic binary seach
        int start=mini;
        int end=maxi;
        int ans=-1;
        while(start<end)
        {
            int mid=(start+end)/2;
            if(is_possible(arr,m,k,mid))//checking weather we are able to create m boque or not
            {
                end=mid;
            }
            else
            {
                start=mid+1;
                
            }
        }
        return start;
        
    }
    
};
