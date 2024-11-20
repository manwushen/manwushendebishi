#include<iostream>
#include<vector>
using namespace std;
class EnergyFieldSystem
{public:
	float MaxEnergyField(vector<int>& heights){
	
		int i = 0;
		int j = heights.size() - 1;
		float max = 0;
		while (i <= j)
		{
			float area = 0;
			area = (heights[i] + heights[j]) * (j - i) / 2.0;
			if (area > max)max = area;
			if (heights[i] > heights[j])
			{
				j--;
				continue;
			}
			else
			{
				i++;
				continue;
			}

		}
			return max;
	}
	 void TestMaxEnergyField()
	{
		 vector<int> heights1 = { 1,8,6,2,5,4,8,3,7 };
		 cout << MaxEnergyField(heights1) << endl;

		 vector<int> heights2 = { 5, 5, 5, 5, 5 };
		 cout << MaxEnergyField(heights2) << endl;

		 vector<int> heights3 = { 1, 3, 5, 3, 1 };
		 cout << MaxEnergyField(heights3) << endl;

		 vector<int> heights4 = { 3, 7 };
		 cout << MaxEnergyField(heights4) << endl;

		 vector<int> heights5 = { 10 };
		 cout << MaxEnergyField(heights5) << endl;

		 vector<int> heights6 = {};
		 cout  << MaxEnergyField(heights6) << endl;
	}

};
int main()
{
	EnergyFieldSystem max;
	max.TestMaxEnergyField();

	return 0;
}
/*
* 分析：每个元素最多遍历一次 时间复杂度O(N)
* 只使用了额外的变量，没有使用额外的数组。空间复杂度O(1)
* 进阶挑战（可选）
1. 如果我们允许玩家使⽤魔法道具来临时增加某个位置的塔的⾼度，你会如何修改你的算法？
在每次判断的时候对两边分别增加一次高度，单独记录允许使用道具的情况下最大面积
2. 在游戏的⾼级模式中，某些位置可能有建筑限制（⾼度为0）。你的算法如何处理这种情况？
如果指针移动后指向0，直接再向同方向移动一次
创意思考
这个能量场机制如何影响玩家在游戏中的策略选择？你能想到如何将这个概念扩展到⼀个有趣的游戏玩法中吗？
玩家会更倾向于选择能形成更高能量场的位置
玩法：玩家进入一个陌生的敌对领域，搭建能量塔，能量塔越高的位置怪物就越多越危险，怪物会不断刷新，玩家需要在规定时间内在能量场内收集
尽可能多的某种奖励资源。能量场外的资源无法收集。风险与收益并存。
*/