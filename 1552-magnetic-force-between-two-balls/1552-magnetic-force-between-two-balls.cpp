class Solution {
public:
      bool isPossible(vector<int> & position,int m,int mid)
      {
          int cnt=1;
          int last=position[0];
          for(int i=0;i<position.size();i++)
          {
              if(abs(position[i]-last)>=mid)
              {
                  cnt++;
                  if(cnt==m)
                  {
                      return true;
                  }
                  last=position[i];
              }
          }
          return false;
          
      }
    int maxDistance(vector<int>& position, int m) {
        int mini=0,mx=-1;
        sort(position.begin(),position.end());
        for(int i=0;i<position.size();i++)
        {
            mx=max(mx,position[i]);
        }
       int l=0,r=mx,ans=0;
        int mid=l+(r-l)/2;
        while(l<=r)
        {
            if(isPossible(position,m,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
            mid=l+(r-l)/2;
        }
        return ans;
        
    }
};