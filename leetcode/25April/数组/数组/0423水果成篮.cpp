#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
/*
思路是 哈希表+滑动窗口
使用哈希表存储滑动窗口内的元素值 右指针不断向右移动 但当哈希表的键值对大于2 
就要移动左指针 直到哈希表中键值对小于等于2
*/

int totalFruit(vector<int>& fruits) {
    int left = 0, sum = 0;
    int n = fruits.size();
    unordered_map<int, int> cnt;// 哈希表
  /*  for (unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;*/
    for (int right = 0; right < n; right++) {
        ++cnt[fruits[right]];// 哈希表中right对应的水果种类的数目加1
        while (cnt.size() > 2) {
            auto it = cnt.find(fruits[left]);// auto是C++11引入的关键字 用于自动推导变量类型
            --it->second;// left对应的水果种类数目减1
            if (it->second == 0) {
                cnt.erase(it);
            }
            left++;
        }
        sum = max(sum, right - left + 1);
    }
    return sum;
}

int main() {
	vector<int>fruits = {1,2,3,2,2};
	int ret = totalFruit(fruits);
	cout << "采摘水果最大数目为:" << ret << endl;

	system("pause");
	return 0;
}

