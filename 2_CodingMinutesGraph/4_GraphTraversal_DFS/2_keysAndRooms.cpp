// https://leetcode.com/problems/keys-and-rooms/submissions/

class Solution {
public:
    void visitHelper(vector<vector<int>>& rooms, int node, bool *visitedArray){
        visitedArray[node]=true;
          
            for(auto key:rooms[node]){
                if(!visitedArray[key]){
                visitHelper(rooms,key,visitedArray);
                }
            }
        }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        bool *visitedArray=new bool[n]{false};
        visitHelper(rooms,0,visitedArray);
        for(int i=0;i<n;i++){
            if(!visitedArray[i]){
                return false;
            }
        }
        return true;
    }
};