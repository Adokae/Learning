#include <iostream>
using namespace std;
#include <unordered_map>
// ����s�к���t�����ַ�����С�Ӵ�
class Solution {
public:
	unordered_map <char, int> ori, cnt;
	// �ù�ϣ��洢�ַ����и��ַ����ֵĴ˴� ��ĿҪ�󺭸�t���� ��Ҫ���ַ������ִ���
	// ori��¼�ַ���t cnt��¼�ַ���s

	bool check() {
		// �ñ������Զ��ƶ�p������ p��pair��������
		// �жϻ�������cnt���ַ��Ƿ����t�������ַ���Ҫ��
		for (const auto& p : ori) {
			if (cnt[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		for (const auto& c:t) {
			++ori[c];
		}// ����t���ַ��� ͳ��t�и��ַ����ִ���
		int l = 0, r = -1;// ��������ָ��
		int len = INT_MAX, ansL = -1, ansR = -1;// ��¼��С�����Ӵ�����ʼ�ͽ���λ��
		while (r<int(s.size())) {
			// �ȶ�r��1 ���ж�s[r]�Ƿ����ori.end() ������ָ�� ʹ�串��t������Ԫ��
			if (ori.find(s[++r]) != ori.end()){
				++cnt[s[r]];// �����д洢��Ҳֻ��ori�е��ַ�
			}
			// ��ǰ���������а����Ӵ��е��ַ� ����ָ�������ָ��
			while (check() && l <= r) {
				if (r - l + 1 < len) {
					len = r - l + 1;
					ansL = l;
				}// ��ǰ����ָ��С��֮ǰͳ�ƵĴ���ָ�� �����Ӵ����Ⱥ���С�Ӵ���ʼλ��
				if (ori.find(s[l]) != ori.end()) {
					--cnt[s[l]];
				}//��ָ��ָ���ַ�������ori�� ���ַ��ڴ�����������1 ��ΪҪ����cnt����洢������
				++l;// �ƶ���ָ��
			}
		}
		return ansL == -1 ? string() : s.substr(ansL, len);
	}
};


int main() {
	string s = "ABOBECODEBANC";
	string t = "ABC";
	Solution so;
	string ret = so.minWindow(s, t);
	cout << "�������ǣ�" << ret << endl;

	system("pause");
	return 0;
}