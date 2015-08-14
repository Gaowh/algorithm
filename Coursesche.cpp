/*
 * 需要注意的地方，尽量不要用邻接矩阵来存储课程对应的关系，这样内存耗费可能会很大
 *
 * */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> index(numCourses, 0);
        vector<vector<int> >map(numCourses);
        
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            index[prerequisites[i].first]++;
            map[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        int count = 0;
        for(int i=0; i<numCourses; i++){
            for(int j=0; j<numCourses; j++){
                if(index[j] == 0){
                    index[j] = -1;
                    count++;
                    for(auto p=map[j].begin(); p!=map[j].end(); p++){
                        index[*p]--;
                    }
                }
            }
        }
        return count == numCourses;
    }
};
