#include<vector>
#include<iostream>
using namespace std;
class TreasureHuntSystem 
{
public:
	int MaxTreasureValue(vector<int>& treasures)
	{
		if (treasures.size() == 0) return 0;
		if (treasures.size() == 1) { return treasures[0]; }
		else if (treasures.size() == 2) { return max(treasures[0], treasures[1]); }
		vector<int> dp(treasures.size());
		dp[0] = treasures[0];
		dp[1] = max(treasures[0], treasures[1]);
		for (int i = 2; i < treasures.size() ; i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + treasures[i]);
		}
		return dp.back();
		
	}
	void TestMaxTreasureValue()
	{
		vector<int> treasures1 = { 3, 1, 5, 2, 4 };
		cout  << MaxTreasureValue(treasures1) << endl;

		vector<int> treasures2 = { 5 };
		cout << MaxTreasureValue(treasures2) << endl;

		vector<int> treasures3 = { 2, 8 };
		cout << MaxTreasureValue(treasures3) << endl;

		vector<int> treasures4 = { 4, 4, 4 };
		cout  << MaxTreasureValue(treasures4) << endl;

		vector<int> treasures5 = { 0, 0, 0 };
		cout << MaxTreasureValue(treasures5) << endl;

		vector<int> treasures6 = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
		cout  << MaxTreasureValue(treasures6) << endl;

		vector<int> treasures7 = {};
		cout <<  MaxTreasureValue(treasures7) << endl;
	}
};
int main()
{
	TreasureHuntSystem system;
	system.TestMaxTreasureValue();
}
/*分析 时间复杂度：遍历了一次 时间复杂度为O(N)
* 空间复杂度 使用了一个大小为N的dp数组 空间复杂度为（N）
* 进阶挑战（可选）
1. 如果我们允许玩家使⽤⼀次"魔法钥匙"，可以安全地打开任意两个相邻的宝箱⽽不触发陷阱，你会
如何修改你的算法？
额外加一个使用魔法钥匙情况下的dp数组
2. 在游戏的⾼级关卡中，有些宝箱可能包含负值（表⽰陷阱会扣除玩家的分数）。你的算法如何处理
这种情况？
直接将值改成负数
创意思考（可选）
这个机制可能会在游戏中带来哪些有趣的策略选择？你能想到如何将这个概念扩展到⼀个完整的游戏关卡设计中吗？
1如果开局所有宝箱都可见，玩家会更倾向于谨慎思考之后再选择宝箱，如果未来的宝箱不可见，玩家将不太可能会选价值过于小的宝箱而倾向于赌下一个宝箱是大宝箱
2将宝箱改成盲选，用颜色来区分出现高价值的概率，橙>紫>蓝>绿>白 同时引入陷阱魔法钥匙等机制，收集够足够的价值后可以进入下一关，
每通关一定关卡数可以获得上文提到的魔法钥匙。

*/