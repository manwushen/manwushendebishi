#include <iostream>
#include <string>
#include <vector>
#include <List>
#include<algorithm>
using namespace std;
class LeaderboardSystem
{
public:
    static list<int> GetTopScores(vector<int> scores, int m)
        {// 在这⾥实现你的代码
        sort(scores.begin(), scores.end(), greater<int>());
        list<int> Leaderboard;
        if (m == 0) return Leaderboard;
        else if (m > scores.size()) { cout <<"error!" ; return Leaderboard; }
        
        for (int i = 0; i < m; i++)
        {
            Leaderboard.push_back(scores[i]);
        }
        return Leaderboard;
        
    }



   void TestGetTopScores()
    {
       vector<int> scores1 = { 100, 50, 75, 80, 65 };
       int m1 = 3;
       list<int> result1 =GetTopScores(scores1, m1);
       for (int score : result1) cout << score << " ";
       cout << endl;

       vector<int> scores2 = { 50, 20, 70, 90 };
       int m2 = 4;
       list<int> result2 =GetTopScores(scores2, m2);
       for (int score : result2) cout << score << " ";
       cout << endl;

       vector<int> scores3 = { 30, 40 };
       int m3 = 5; 
           list<int> result3 = GetTopScores(scores3, m3);
           for (int score : result3) cout << score << " ";
           cout << endl;

       vector<int> scores4 = { 100, 100, 50, 50, 50 };
       int m4 = 3;
       list<int> result4 =GetTopScores(scores4, m4);
       for (int score : result4) cout << score << " ";
       cout << endl;

       vector<int> scores5 = {};
       int m5 = 2;
           list<int> result5 = GetTopScores(scores5, m5);
           for (int score : result5) cout << score << " ";
           cout << endl;

       vector<int> scores6 = { 60, 70, 80 };
       int m6 = 0;
       list<int> result6 = GetTopScores(scores6, m6);
       for (int score : result6) cout << score << " ";
       cout << endl;
    }

};
int main()
{
    LeaderboardSystem leader;
    leader.TestGetTopScores();
    return 0;
}

/*分析：
时间复杂度：排序操作复杂度为nlogn
循环操作复杂度为m
整体复杂度为nlogn
空间复杂度：需要返回一个大小为m的list，故空间复杂度为m
如果我们的游戏变得⾮常受欢迎，玩家数量达到了数百万，你会如何优化这个算法以处理⼤规模数据？
大根堆
*/