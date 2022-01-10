class Solution {
    vector<int>arr;
    class SegTree
    {
        public:
        SegTree *left;
        SegTree *right;
        int start,end,val;
        SegTree(int a,int b)
        {
            start=a;
            end=b;
            left=NULL;
            right=NULL;
        }
    };
    int build(SegTree *cur,int l,int r)
    {
        if(l+1==r)
        {
            cur->val=arr[l];
            return cur->val;
        }
        int mid=(l+r)/2;
        cur->left=new SegTree(l,mid);
        cur->right=new SegTree(mid,r);
        int now=build(cur->left,l,mid)&build(cur->right,mid,r);
        cur->val=now;
        return now;
    }
    int query(SegTree *cur,int l,int r)
    {
        if(cur->start>=r||cur->end<=l)return INT_MAX;
        if(cur->start>=l&&cur->end<=r)return cur->val;
        int now=query(cur->left,l,r)&query(cur->right,l,r);
        return now;
    }
    SegTree *root;
public:
    int closestToTarget(vector<int>& arr, int target) {
        this->arr=arr;
        root=new SegTree(0,arr.size());
        build(root,0,arr.size());
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            int r=arr.size();
            int l=i;
            while(l<r)
            {
                int mid=(l+r)/2;
                int now=query(root,i,mid+1);
                if(now==target)return 0;
                else if(now-target>0)
                {
                    ans=min(ans,now-target);
                    l=mid+2;
                }else
                {
                    ans=min(ans,target-now);
                    r=mid;
                }
            }
            ans=min(ans,abs(target-query(root,i,l+1)));
        }
        return ans;
    }
};