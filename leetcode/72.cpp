#include "../common.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dist[word1.size()+1][word2.size()+1];
        memset(dist, 0, sizeof(dist));

        for(int i=1;i<=word2.size();i++){
            dist[0][i]=i;
        }
        for(int j=1;j<=word1.size();j++){
            dist[j][0] = j;
        }
        
        for(int i =1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1] == word2[j-1]){
                    dist[i][j]=dist[i-1][j-1];
                }
                else
                    dist[i][j] = min(dist[i-1][j-1], min(dist[i][j-1], dist[i-1][j])) +1;

            }
        }
        return dist[word1.size()][word2.size()];
    }
};


int main(){
    string word1 = "intention";
    string word2 = "execution";

    Solution s;
    cout << s.minDistance(word1, word2) << endl;




}
