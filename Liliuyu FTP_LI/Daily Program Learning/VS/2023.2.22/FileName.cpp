#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void) {

	int t, count = 0;
	int mark = 0;
	int max_size=0;
	int j;
	int n;
	int str[1000]{};
	cin >> t;//序列的长度
	max_size = t - 1;
	for (int i = 1; i < t+1; i++) {
		cin >> str[i-1];
	}//填充数据
	cin >> n;
	for (int i = 0; i < t; i++) {
		if (n == str[i]) {
			for (j = i; j < max_size; j++) {
				str[j] = str[j + 1];
			}
			max_size--;
			mark = i;
			count++;
			break;
		}
	}
	t--;
	while (t--) {
		cin >> n;
		if (n != str[mark - 1] && n != str[mark]) {
			cout << 0;
			return 0;
		}
		else {
			if (n == str[mark - 1]) {
				for (int j = mark - 1; j <= max_size-1; j++) {
					str[j] = str[j + 1];
				}
				max_size--;
				mark--;
				count++;
			}
			else {
				for (int j = mark; j < max_size; j++) {
					str[j] = str[j + 1];
				}
				max_size--;
				count++;
			}
		}

	}

	cout << count;


	return 0;
}