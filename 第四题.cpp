#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TalentAssessmentSystem
{
public:
    static double FindMedianTalentIndex(vector<int>& fireAbility, vector<int>& iceAbility)
    {
        int fireLength = 0;
        int iceLength = 0;
        fireLength = fireAbility.size();
        iceLength = iceAbility.size();
        int sumLength = fireLength + iceLength;
        if (sumLength == 0)return INT_MIN;
            
        
        if (fireLength == 0 && iceLength != 0) {
            if (iceLength % 2 == 0)
                return (iceAbility[iceLength / 2] + iceAbility[iceLength / 2 - 1]) / 2;
            else return iceAbility[iceLength / 2];
        }
        if (iceLength == 0 && fireLength != 0) {
            if (fireLength % 2 == 0)
                return (fireAbility[fireLength / 2] + fireAbility[fireLength / 2 - 1]) / 2;
            else return fireAbility[fireLength / 2];
        }
        vector<int> sum;
        
            int j = 0;
            int i = 0;
            while (i < fireLength && j < iceLength) {
                if (fireAbility[i] <= iceAbility[j]) {
                    sum.push_back(fireAbility[i++]);
                }
                else {
                    sum.push_back(iceAbility[j++]);
                }
            }

            while (i < fireLength) {
                sum.push_back(fireAbility[i++]);
            }
            while (j < iceLength) {
                sum.push_back(iceAbility[j++]);
            }
            if (sumLength % 2 == 0)
                return (sum[sumLength / 2] + sum[sumLength / 2 - 1]) / 2;
            else
                return sum[sumLength / 2];
            sum.clear();
        
        return 0;

    }

	
	
    void TestFindMedianTalentIndex()
	{
       
        vector<int> fireAbility1 = {};
        vector<int> iceAbility1 = { 2, 4, 8,10};
        cout << "Test 1 Result: " << FindMedianTalentIndex(fireAbility1, iceAbility1) << endl;
        
        vector<int> fireAbility2 ={ 1, 2, 3, 4, 5 };
        vector<int> iceAbility2 = {}; 
        cout << "Test 2 Result: " << FindMedianTalentIndex(fireAbility2, iceAbility2) << endl;
        
        vector<int> fireAbility3 = {};
        vector<int> iceAbility3 = {};
        cout << "Test 3 Result: " << FindMedianTalentIndex(fireAbility3, iceAbility3) << endl;
       
        vector<int> fireAbility4 = { 1, 3, 5, 7,9,13 };
        vector<int> iceAbility4 = { 2, 4, 6, 8, 8 };
        cout << "Test 4 Result: " << FindMedianTalentIndex(fireAbility4, iceAbility4) << endl;
       
        vector<int> fireAbility5 = { -5, -3, -1 };
        vector<int> iceAbility5 = { -4,  0, 2 , 3 };
        cout << "Test 5 Result: " << FindMedianTalentIndex(fireAbility5, iceAbility5) << endl;
	}
	
};
int main()
{
	TalentAssessmentSystem tale;
    tale.TestFindMedianTalentIndex();
	return 0;
}
/*分析：总共遍历了m+n个元素 故时间复杂度为O(M+N)
使用了一个合并数组 空间复杂度为O(M+N)
进阶挑战（可选）
1. 如果我们需要实时更新⼤量学徒的天赋指数，你会如何优化你的算法或数据结构？
答：使用双向链表，维护头结点、尾结点、中间节点，数据长度和中间节点位置，加入数据时由中间节点和头（尾）结点寻找插入点，若在中间节点前则中间节点位数+1，再根据奇偶和中间节点求出中位数。
2. 在游戏的⾼级模式中，可能会有更多的魔法属性（不仅仅是⽕和冰）。你的算法如何扩展到处理 k个有序数组的中位数？
使用一些更优的查找算法，寻找一个数使得大于和小于这个数的元素个数相等

创意思考（可选）
这个天赋评估系统如何影响游戏的⻆⾊发展和技能学习机制？你能想到如何将这个概念融⼊到游戏的其他⽅⾯，⽐如任务系统或 PVP 对战中吗？
中位数越高，说明学徒的整体天赋越高，可以让中位数高的学徒获得更高经验。当然中位数的判断并不完全准确，不妨加入平均数概念，若平均数大于中位数，说明数据整体偏高，可以称其为潜力值，让玩家对天赋有一个更全面的判断。
天赋越高的学徒，任务成功率越高，PVP作战中，天赋高的学徒可以获得对天赋低的学徒的些许减伤。
*/