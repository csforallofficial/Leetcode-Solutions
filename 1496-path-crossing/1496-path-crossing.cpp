class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0, y=0;
        map<pair<int, int>, int>mpp;
        mpp[{0,0}]++;
        
        for(int i=0; i<path.length(); i++){
            if(path[i]=='N') y++;
            else if(path[i]=='W') x--;
            else if(path[i]=='E') x++;
            else y--;
            
            if(mpp.find({x,y}) != mpp.end()) return true;
            else mpp[{x,y}]++;
        }
        
        return false;
    }
};