#include <iostream>
using namespace std;
#include <vector>

int main() {
	int len, a,b;
	int elem,sum = 0,pre= 0;
	cin >> len;
	vector<int> array;
	vector<int> pre_array;
	for (int i = 0; i < len; i++) {
		scanf("%d", &elem);
		pre += elem;
		array.push_back(elem);
		pre_array.push_back(pre);
	}
	while (~scanf("%d%d",&a,&b)) {
		if (a == 0) {
			sum = pre_array[b];
		}
		else {
			sum = pre_array[b] - pre_array[a - 1];
		}
		printf("%d",sum);
	}

	system("pause");

	return 0;
}
