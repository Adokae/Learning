#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
/*
˼·�� ��ϣ��+��������
ʹ�ù�ϣ��洢���������ڵ�Ԫ��ֵ ��ָ�벻�������ƶ� ������ϣ��ļ�ֵ�Դ���2 
��Ҫ�ƶ���ָ�� ֱ����ϣ���м�ֵ��С�ڵ���2
*/

int totalFruit(vector<int>& fruits) {
    int left = 0, sum = 0;
    int n = fruits.size();
    unordered_map<int, int> cnt;// ��ϣ��
  /*  for (unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;*/
    for (int right = 0; right < n; right++) {
        ++cnt[fruits[right]];// ��ϣ����right��Ӧ��ˮ���������Ŀ��1
        while (cnt.size() > 2) {
            auto it = cnt.find(fruits[left]);// auto��C++11����Ĺؼ��� �����Զ��Ƶ���������
            --it->second;// left��Ӧ��ˮ��������Ŀ��1
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
	cout << "��ժˮ�������ĿΪ:" << ret << endl;

	system("pause");
	return 0;
}

