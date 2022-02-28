class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> max_heap;
        max_heap.push(a);
        max_heap.push(b);
        max_heap.push(c);
        int ans = 0;
        while(true){
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();
            if(x==0 || y==0)
                break;
            x--;
            y--;
            ans++;
            max_heap.push(x);
            max_heap.push(y);
        }
        return ans;
    }
};