#pragma    warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;
//judge prime function
bool isprime[1000000];
int prime[1000000];
void judge(int x) {
	memset(isprime, 1, x);
	isprime[1] = 0;
	for (int i = 2; i < x; i++) {
		if (isprime[i]) {
			for (int j = i * i; j < x; j += i) {
				isprime[j] = 0;
			}
		}
	}
}

//quicksort
void qksort(int a[], int left, int right) {
	if (left >= right)return;
	int L = left, R = right;
	while (L < R) {
		while (L < R && a[R] >= a[left])R--;
		while (L < R && a[L] <= a[left])L++;
		swap(a[L], (L == R) ? a[left] : a[R]);
	}
	qksort(a, left, R - 1);
	qksort(a, L + 1, right);
}

//swap
void swap(int& a, int& b) {
	a ^= b ^= a ^= b;
}

//inverse
void inverse(int num) {
	for (int i = 1; i <= num; i++) {
		if (isprime[i]) {
			int sum = 0,tmp=i;
			while (tmp) {
				sum = sum * 10 + tmp % 10;
				tmp /= 10;
			}
			if (sum != i)isprime[i] = 0;
		}
	}
}


//bubblesort
void bubblesort(int a[]) {
	for (int i = 0; i < 10; i++) {
		int flag = 1;
		for (int j = 0; j < 10 - i-1; j++) {
			if (a[j] > a[j + 1])swap(a[j], a[j + 1]),flag=0;
		}
		if (flag)break;
	}
}

//1.

//void inverse(char a[]) {
//	int len = strlen(a);
//	for (int i = 0; i < len / 2; i++) {
//		char tmp = a[i];
//		a[i] = a[len - 1 - i];
//		a[len - 1 - i] = tmp;
//	}
//}
//#define arr_size 10000
////StudybarCommentBegin
//int main()
//{
//	char a[arr_size];
//	gets(a);
//	inverse(a);
//	puts(a);
//	return 0;
//}
////StudybarCommentEnd

//2.

//string s;
//int main() {
//	cin >> s;
//	int len = s.size();
//	sort(s.begin(), s.begin() + len);
//	cout << s;
//
//	return 0;
//}

//3.

//int main() {
//	judge(1000);
//	inverse(1000);
//	for (int i = 10; i <= 1000; i++) {
//		if (isprime[i])cout << i << " ";
//	}
//	return 0;
//}

///*4.sin(x)

//int main() {
//	double a, b = 1;
//	double x, sinx = 0;
//	cin >> x;
//	a = x;
//	int count = 1;
//	for (double i = 1; fabs(a / b) >= 1e-5; i++) {
//		sinx += a / b;
//		a = -a * x * x;
//		b = b * 2 * i * (2 * i + 1);
//		count++;
//	}
//	printf("%.3lf\n%d", sinx, count);
//
//	return 0;
//}

///5.删除元素，用时长，原因：数组大小不慎放入移动的循环

////StudybarCommentBegin
//#include <stdio.h>
//int removeElement(int nums[], int numsSize, int val);
//int main(void) {
//	int n, m, val, a[1000];
//	int i;
//	scanf("%d%d", &n, &val);
//	for (i = 0; i < n; i++) scanf("%d", &a[i]);
//	m = removeElement(a, n, val);
//	for (i = 0; i < m; i++) printf("%d ", a[i]);
//	return 0;
//}
////StudybarCommentEnd
//
//int removeElement(int nums[], int numsSize, int val) {
//	int i = 0;
//	while (i < numsSize) {
//		int flag = 0;
//		if (nums[i] == val) {
//			flag = 1;
//			for (int j = i; j < numsSize - 1; j++) {
//				nums[j] = nums[j + 1];
//			}
//			if(flag)numsSize--;
//		}
//		if (!flag)i++;
//	}
//	return numsSize;
//}
//
//int removeElement(int nums[], int numsSize, int val) {
//	int flag = 0;
//	for (int i = 0; i < numsSize; i++) {
//		if (flag)i--;
//		flag = 0;
//		if (nums[i] == val) {
//			for (int j = i; j < numsSize - 1; j++) {
//				nums[j] = nums[j + 1];
//				flag = 1;
//			}
//			numsSize--;
//		}
//	}
//	return numsSize;
//}

///6.做烦了

//string s;
//string s1[20];
//int main() {
//	getline(cin, s);
//	int cnt = 1;
//	int len = s.size();
//	int flag = 0;
//	for (int i = 0; i < len; i++) {
//		if (s[i] != ' ') {
//			s1[cnt] += s[i];
//			flag = 1;
//		}
//		if (s[i] == ' '&&flag) {
//			cnt++,flag=0;
//		}
//	}
//	int max = 0;
//	for (int j = 1; j <= cnt; j++) {
//		int tmp = s1[j].size();
//		if (tmp > max) {
//			max = tmp;
//		}
//	}
//	bool isprint[100];
//	memset(isprint, 0, 100);
//	for (int k = 1; k <= cnt; k++) {
//		if (s1[k].size() == max)isprint[k] = 1;
//	}
//	for (int n = 1; n <= cnt; n++) {
//		if (isprint[n])cout << s1[n] << endl;
//	}
//	
//	return 0;
//}

//7.网费

//int main() {
//	double n;
//	cin >> n;
//
//}

//8.

//int a[10];
//int main() {
//	for (int i = 0; i < 10; i++) {
//		cin >> a[i];
//	}
//	sort(a, a + 10);
//	int sum = 0;
//	for (int j = 0; j < 5; j++) {
//		sum += a[j];
//	}
//	cout << sum;
//
//	return 0;
//}

//9.

//int main() {
//	for (int i = 1; i <= 99; i++) {
//		if ((i % 10 != 5) && (i % 10 != 6)&&(i%10!=1))continue;
//		else {
//			if (i >= 1 && i <= 10)cout << i<<endl;
//			else{
//				if (i * i % 100 == i)cout << i << endl;
//			}
//		}
//	}
//	return 0;
//}

//10.

//int main() {
//	int a, b;
//	int sum = 0;
//	cin >> a >> b;
//	judge(b);
//	for (int i = a; i <= b; i++) {
//		if (isprime[i])sum += i;
//	}
//	cout << sum;
//
//	return 0;
//}

//11.再算电费

//int main() {
//	return 0;
//}

//12.

//int main() {
//	int num;
//	cin >> num;
//	int sum = 0;
//	while (num) {
//		sum += num % 10;
//		num /= 10;
//	}
//	cout << sum;
//	return 0;
//}

//13.

////StudybarCommentBegin
//#include <stdio.h>
//
//#include <string.h>
//
//void shift(char s[]);
//
//int main()
//
//{
//
//	char s[10];
//
//	gets(s);
//	shift(s);
//	printf("%s\n", s);
//
//	return 0;
//
//}
////StudybarCommentEnd
//char tmp;
//void shift(char s[]) {
//	int n = 3;
//	while (n) {
//		tmp = s[0];
//		for (int i = 0; i < strlen(s)-1; i++) {
//			s[i] = s[i + 1];
//		}
//		s[strlen(s)-1] = tmp;
//		n--;
//	}
//}

//14.

//int a[3];
//int main() {
//	for (int i = 0; i < 3; i++) {
//		cin >> a[i];
//	}
//	sort(a, a + 3);
//	cout << a[1];
//	return 0;
//}

//15.

//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		int tmp = pow(i, 2);
//		if ( tmp% 391 == 50)cout << i<<" ";
//	}
//	return 0;
//}

//16.

////StudybarCommentBegin
//int main()
//{
//	int n;
//	void jdgprime(int n);
//	scanf("%d", &n);
//	jdgprime(n);
//	return 0;
//}
//
////StudybarCommentEnd
//void jdgprime(int n) {
//	judge(10000);
//	if (isprime[n])cout << "y";
//	else {
//		for (int i = 2; i <= n; i++) {
//			if (isprime[i]&&n%i==0) {
//				int tmp = n / i;
//				printf("%d*%d", i, tmp);
//				break;
//			}
//		}
//	}
//}

//17.

//int a[10],b[10];
//int main() {
//	judge(10000);
//	int flag = 1;
//	int cnt = 0;
//	for (int i = 0; i < 10; i++) {
//		cin >> a[i];
//		if (isprime[a[i]]) {
//			flag = 0; 
//			b[cnt++] = a[i];
//		}
//	}
//	if (flag)cout << "No prime";
//	else {
//		sort(b, b + cnt);
//		for (int j = 0; j < cnt; j++)cout << b[j]<<" ";
//	}
//	return 0;
//}

//18.

//int a[10], b[10];
//int main() {
//	for (int i = 0; i < 10; i++) {
//		cin >> a[i];
//		b[i] = a[i];
//	}
//	int m=0, n=0;
//	sort(a, a + 10);
//	int min=abs(a[0]-a[1]), minn=0;
//	for (int j = 0; j < 9; j++) {
//		if (abs(a[j] - a[j + 1]) < min) {
//			min = abs(a[j] - a[j + 1]), minn = j;
//		}
//	}
//	for (int k = 0; k < 10; k++) {
//		if (b[k] == a[minn] || b[k] == a[minn + 1]) {
//			m = b[k],b[k]=10000000; break;
//		}
//	}
//	for (int l = 0; l < 10; l++) {
//		if (b[l] == a[minn] || b[l] == a[minn + 1]) {
//			n = b[l]; break;
//		}
//	}
//	printf("%d %d %d", m,n, min);
//
//	return 0;
//}

//19.

//int main() {
//	judge(10000);
//	for (int i = 400; i <= 500; i++) {
//		if (!isprime[i]) {
//			int sum = 0;
//			for (int j = 1; j < i; j++) {
//				if (i % j == 0) {
//					sum += j;
//				}
//			}
//			if (sum == i)cout << i << endl;
//		}
//	}
//
//	return 0;
//}

//20.

//string s;
//int main() {
//	cin >> s;
//	int len = s.size();
//	cout << s[len - 3] << s[len - 4] << s[len - 5];
//
//	return 0;
//}

//21.

//int a[2][6];
//int main() {
//	for (int i = 0; i < 6; i++) {
//		cin >> a[0][i];
//	}
//	for (int k = 0; k < 6; k++)cout << a[0][k]<<" ";
//	cout << endl;
//	for (int j = 0; j < 5; j++) {
//		int k = j % 2;
//		for (int n = 0; n < 6; n++) {
//			a[!k][n] = a[k][(n + 1) % 6];
//			cout << a[!k][n] << " ";
//		}
//		cout << endl;
//	}
//}

//22.

//int a[5],w[4];
//bool b[5];
//int main() {
//	memset(b, 1, 5);
//	for (int i = 0; i < 5; i++)cin >> a[i];
//	for (int j = 0; j < 5; j++) {
//		int tmp = a[j];
//		int cnt = 0;
//		while (tmp) {
//			w[cnt++] = tmp % 10;
//			tmp /= 10;
//		}
//		if (w[0] + w[2] != w[1] + w[3]) {
//			b[j] = 0;
//		}
//	}
//	for (int k = 0; k < 5; k++) {
//		if (b[k])cout << a[k] << " ";
//	}
//	return 0;
//}

//23.

//int a[6];
//int main() {
//	for (int i = 0; i < 6; i++)cin >> a[i];
//	sort(a, a + 6);
//	for (int k = 0; k < 6; k++)cout << a[k] << " ";
//
//	return 0;
//}

//24.

//int main() {
//	stack<int> s;
//	int n;
//	while (cin >> n) {
//		s.push(n);
//	}
//	while (!s.empty()) {
//		cout << s.top()<<" ";
//		s.pop();
//	}
//
//	return 0;
//}

//25.

//int main() {
//	char ch;
//	int let = 0, shu = 0, oth = 0;
//	while ((ch = getchar()) != '\n') {
//		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))let++;
//		else if (ch == ' ')oth++;
//		else if (ch >= '0'&&ch <= '9')shu++;
//	}
//	printf("letter:%d\ndigit:%d\nother:%d", let, shu, oth);
//	return 0;
//}

//26.

//void insert(int a[], int num) {
//	if (num >= a[9])a[10] = num;
//	else {
//		for (int i = 0; i < 9; i++) {
//			if (num <= a[i]) {
//				for (int j =10; j > i; j--) {
//					a[j] = a[j - 1];
//				}
//				a[i] = num;
//				break;
//			}
//		}
//	}
//}
////StudybarCommentBegin
//int main()
//{
//	int a[11] = { 10,20,30,40,50,60,70,80,90,100 };
//	int number, i;
//	scanf("%d", &number);
//	insert(a, number);
//	for (i = 0; i < 11; i++)
//		printf("%d ", a[i]);
//}
////StudybarCommentEnd

//27.

//string s,s1;
//int main() {
//	cin >> s;
//	s1 = s;
//	reverse(s.begin(), s.end());
//	if (s1 == s)cout << "Y";
//	else cout << "N";
//	return 0;
//}

//28.

//int main() {
//	double a, b, c;
//	cin >> a >> b >> c;
//	if (a + b <= c || a + c <= b || b + c <= a)cout << "They can't form a triangle.";
//	else {
//		double C = a + b + c;
//		double p = (a + b + c) / 2;
//		double s = sqrt(p * (p - a) * (p - b) * (p - c));
//		printf("%.2lf %.2lf", C, s);
//	}
//	return 0;
//}

//29.

//int main() {
//	judge(10000);
//	int n, cnt=0;
//	cin >> n;
//	for (int i = 2; i <= n; i++) {
//		if (isprime[i])cnt++;
//	}
//	cout << cnt;
//
//	return 0;
//}

//30.

//int a[3][3];
//int main() {
//	int max = 0, maxx = 0,maxy=0;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			cin >> a[i][j];
//			if (a[i][j] > max) {
//				max = a[i][j];
//				maxx = i, maxy = j;
//			}
//		}
//	}
//	printf("最大值%d的坐标为%d,%d", max, maxx, maxy);
//
//	return 0;
//}

//31.

//string s;
//int main() {
//	cin >> s;
//	int cnt = 0;
//	for (int i = 0; i < s.size(); i++) {
//		for (int j = 0; j < i; j++) {
//			if (s[j] > s[i])cnt++;
//		}
//	}
//	cout << cnt;
//	return 0;
//}

//32.

//int main() {
//	double a = 2, b = 1, tmp;
//	int n;
//	double sum=0;
//	cin >> n;
//	while (n--) {
//		sum += a / b;
//		tmp = a;
//		a = a + b;
//		b = tmp;
//	}
//	printf("%.2lf", sum);
//
//	return 0;
//}

//33.

////StudybarCommentBegin
//#include <stdio.h>
//#define SIZE 80
//int MyStrcmp(char s[], char t[]);
//main()
//{
//	char s[SIZE], t[SIZE], i;
//	gets(s);
//	gets(t);
//	i = MyStrcmp(s, t);
//	if (i > 0)
//		printf("string s>string t.\n");
//	else if (i < 0)
//		printf("string s<string t.\n");
//	else
//		printf("string s=string t.\n");
//}
//
////StudybarCommentEnd
//int MyStrcmp(char s[], char t[]) {
//	int flag = 1;
//	for (int i = 0; i < strlen(s); i++) {
//		if (s[i] != t[i]) {
//			flag = 0;
//			return s[i] - t[i];
//			break;
//		}
//	}
//	if (flag)return 0;
//}

//34.

//int main() {
//	for (int i = 1; i < 100000; i++) {
//		if (i % 2 == 1 && i % 3 == 2 && i % 5 == 4 && i % 6 == 5 && i % 7 == 0) {
//			cout << i;
//			break;
//		}
//	}
//
//	return 0;
//}

//2017.3

//int judgef(int c[])
//{
//	int i;
//	for (i = 1; i <= 10; i++) {
//		if (c[1] != c[i]) {
//			return 1;   
//		}
//	}
//	return 0;
//}
//int a[11],b[11];
//int main() {
//	int cnt = 0;
//	for (int i = 1; i <= 10; i++)cin >> a[i];
//	while (judgef(a)) {
//		for (int i = 1; i <= 10; i++) {
//			if (a[i] % 2 == 0) {
//				b[i] = a[i] = a[i] / 2;
//			}
//			else {
//				b[i] = a[i] = (a[i] + 1) / 2;
//			}
//		}
//		for (int j = 1; j <= 9; j++) {
//			a[j] += b[j+1];
//		}
//		a[10] += b[1];
//		cnt++;
//	}
//	cout << cnt << endl;
//	cout << a[1];
//	return 0;
//}


//王子睡公主

//int gonzhu[100010];
//void func() {
//	int num = 1, cnt = 0;
//	while (num <= 100000) {
//		int tmp = num;
//		for (;num<=tmp+cnt && num <= 100000; num++) {
//			if (cnt % 2==0)gonzhu[num] = 1;
//			else gonzhu[num] = 0;
//		}
//		cnt++;
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	judge(10000);
//	func();
//	int count = 0;
//	for (int j = 1; j <= n; j++) {
//		if (!isprime[j] && gonzhu[j])count++;
//	}
//	cout << count;
//	return 0;
//}

//约瑟夫

//vector<int> table;
//int main() {
//	int a, b;
//	int pos = 0;
//	while (cin >> a >> b) {
//		for (int i = 0; i < a; i++)table.push_back(i);
//		for (int i = 0; i < a; i++) {
//			pos = (pos + b - 1) % table.size();
//			if(table.size()==1)cout << table[pos] + 1 << " ";
//			table.erase(table.begin() + pos);
//		}
//	}
//	return 0;
//}

//2017.1

//string s;
//int a[5];
//int main() {
//	cin >> s;
//	if (s.size() < 6)cout << "Not Safe";
//	else {
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] >= 'a' && s[i] <= 'z')a[1] = 1;
//			else if (s[i] >= 'A' && s[i] <= 'Z')a[2] = 1;
//			else if (s[i] >= '0' && s[i] <= '9')a[3] = 1;
//			else a[4] = 1;
//		}
//		int sum = 0;
//		for (int j = 1; j <= 4; j++)sum += a[j];
//		if (sum == 1)cout << "Not Safe";
//		else if (sum == 2)cout << "Medium Safe";
//		else if (sum >= 3)cout << "Safe";
//	}
//
//	return 0;
//}

//2017.2

//bool a[100000];
//void bashu() {
//	for (int i = 79; i <= 10000; i++) {
//		int sum1 = 0, sum2 = 0,tmp2=i+1,tmp1=i;
//		while (tmp1) {
//			sum1 += tmp1 % 10;
//			tmp1 /= 10;
//		}
//		while (tmp2) {
//			sum2 += tmp2 % 10;
//			tmp2 /= 10;
//		}
//		if (sum1 % 8==0 && sum2 % 8==0)a[i] = 1;
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	bashu();
//	for (int j = 79; j <= 10000; j++) {
//		if (n==0)break;
//		if (a[j]) { 
//		cout << j << " " << j + 1 << endl;
//		n--;
//		}
//	}
//
//	return 0;
//}

//2017.4

//string s;
//int main() {
//	getline(cin, s);
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] <= 'z' && s[i] >= 'a')s[i] = char('z' - s[i] + 'a');
//		else if (s[i] <= 'Z' && s[i] >= 'A')s[i] = char('Z' - s[i] + 'A');
//	}
//	cout << s;
//
//	return 0;
//}

//2017.5

////StudybarCommentBegin
//#include <stdio.h>
//int search(int list[], int n, int x);
//
//int main()
//{
//	int i, index, n, x;
//	int a[100];
//
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//
//	scanf("%d", &x);
//
//	index = search(a, n, x);
//
//	if (index != -1)
//		printf("index = %d\n", index);
//	else
//		printf("Not found\n");
//
//	return 0;
//}
////StudybarCommentEnd
//
//int search(int list[], int n, int x) {
//	int flag = 1;
//	for (int i = 0; i < n; i++) {
//		if (list[i] == x) { flag = 0; return i; }
//	}
//	if (flag)return -1;
//}

//2017.6

//int main() {
//	double n,high=100;
//	cin >> n;
//	double sum=100;
//	if (n > 1) {
//		for (int i = 2; i <= n; i++) {
//			sum += high;
//			high /= 2;
//		}
//		printf("%.2lf\n", sum);
//		printf("%.2lf",100 / (pow(2, n)));
//	}
//	else if (n == 1) {
//		printf("100.00\n50.00");
//	}
//	else cout << "error";
//	return 0;
//}

//2017.7

//char s1[100],s2[20];
//int main() {
//	int count = 0;
//	cin >> s1 >> s2;
//	int len2 = strlen(s2);
//	char* p = strstr(s1, s2);
//	if (p == NULL)cout << 0;
//	else {
//		while (p != NULL) {
//			count++;
//			p = strstr(p+len2, s2);
//		}
//		cout << count;
//	}
//
//	return 0;
//}

//2018.1

//int main() {
//	judge(10000);
//	for (int i = 100; i <= 1000; i++) {
//		if (isprime[i]) {
//			int sum = 0,tmp=i;
//			while (tmp) {
//				sum = sum * 10 + tmp % 10;
//				tmp /= 10;
//			}
//			if (isprime[sum]) { 
//				isprime[i] = 0;
//				printf("%d,%d\n", i, sum); }
//		}
//	}
//
//	return 0;
//}

//2018.2

//string s;
//char a[9] = { '1','2','3','4','5','6','7','8','9' };
//int main() {
//	cin >> s;
//	int len = s.size();
//	int x = s[0] - '0';
//	for (int i = 0; i < x; i++) {
//		string s1;
//		for(int j=0;j<len;j++){ 
//			s1 += a[i]; 
//		}
//		if(s1<s)
//		cout << s1 << endl;
//	}
//
//	return 0;
//}

//2018.3

//int main() {
//	double n;
//	double sum = 0;
//	cin >> n;
//	if (n > 400) {
//		double tmp = n - 400;
//		n -= tmp;
//		sum += tmp * 0.83;
//	}
//	if (n >= 241) {
//		double tmp = n - 240;
//		n -= tmp;
//		sum += tmp * 0.58;
//	}
//	if (n <= 240) {
//		sum += 0.53 * n;
//	}
//	printf("%.2lf", sum);
//
//	return 0;
//}

//2018.6

//void fact(int n);
//double mypow(double x, int n);
////StudybarCommentBegin
//int main()
//{
//	double equation(double x, int n);
//	int n;
//	double x;
//	scanf("%lf%d", &x, &n);
//	printf("%.4lf\n", equation(x, n));
//	return 0;
//}
////StudybarCommentEnd
//double mypow(double x, int n) {
//	double tmp = x;
//	for (int j = 1; j < n; j++) {
//		tmp *= x;
//	}
//	return tmp;
//}
//int a[100];
//void fact(int n) {
//	a[1] = 1;
//	for (int i = 2; i <= n; i++) {
//		a[i] = a[i - 1] * i;
//	}
//}
//double equation(double x, int n) {
//	fact(n);
//	double sum = 0;
//	int k = -1;
//	for (int i = 1; i <= n; i++) {
//		k = -k;
//		sum += ((k * mypow(x, i)) / (double)a[i]);
//	}
//	return sum;
//}

//2018.7

//int main() {
//	int n;
//	cin >> n;
//	if ((!(n % 400)) || (!(n % 4) && n % 100))cout << 29;
//	else cout << 28;
//
//	return 0;
//}

//附带 1

//int gcd(int x, int y) {
//	if (y == 0)return x;
//	else return gcd(y, x % y);
//}
//int lcm(int x, int y) {
//	return (y / gcd(x, y)) * x;
//}
////StudybarCommentBegin
//void main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	printf("%d %d\n", gcd(x, y), lcm(x, y));
//}
////StudybarCommentEnd

//附带 2

//int D[] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
//int countday(int year, int month, int day) {
//	int total = 0;
//	total += D[month - 1] + day;
//	total += (month > 2 && ((!(year % 400)) || (!(year % 4) && year % 100))) ? 1 : 0;
//	total += (--year) * 365 + year / 400 + year / 4 - year / 100;
//	return total;
//}
//int main() {
//	int year, month, day;
//	cin >> year >> month >> day;
//	cout << countday(year, month, day) - countday(year, 1, 1) + 1;
//	return 0;
//}

//1

//string s;
//int main() {
//	int count = 0;
//	cin >> s;
//	int index = s.find("hello", 0);
//	while (index!=string::npos) {
//		count++;
//		index = s.find("hello", index + 1);
//	}
//	cout << count;
//
//	return 0;
//}

//2

//double a[3];
//int main() {
//	scanf("%lf,%lf,%lf", &a[0], &a[1], &a[2]);
//	sort(a, a + 3);
//	if (a[0] + a[1] <= a[2])cout << "不是三角形";
//	else {
//		if (a[0] == a[1]) {
//			if (a[0] * a[0] + a[1] * a[1] == ceil(a[2] * a[2]))cout << "等腰直角三角形";
//			else if (a[0] == a[2])cout << "等边三角形";
//			else cout << "等腰三角形";
//		}
//		else if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])cout << "直角三角形";
//		else cout << "一般三角形";
//	}
//
//	return 0;
//}

//3

//int num[2][10000];
//int main() {
//	int n, m;
//	int flag = 1;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> num[0][i];
//		num[1][i] = 1;
//	}
//	sort(num[0], num[0] + n);
//	for (int k = 0; k < n-1; k++) {
//		for (int j = k + 1; j < n; j++) {
//			if (num[0][k] + num[0][j] == m) {
//				if(num[1][k]&&num[1][j])printf("%d,%d\n", num[0][k], num[0][j]);
//				num[1][j] = 0,num[1][k]=0;
//				flag = 0;
//			}
//		}
//	}
//	if (flag)cout << "no";
//
//	return 0;
//}

//4

//string s1, s2;
//int main() {
//	getline(cin, s1);
//	getline(cin, s2);
//	char max = s1[0];
//	int maxn = 0;
//	for (int i = 1; i < s1.size(); i++) {
//		if (s1[i] > max) {
//			max = s1[i];
//			maxn = i;
//		}
//	}
//	s1.insert(maxn+1, s2);
//	cout << s1;
//
//	return 0;
//}

//5.

//string s1;
//string s[50];
//int main() {
//	int flag = 1;
//	int cnt = 0;
//	getline(cin, s1);
//	for (int i = 0; i < s1.size(); i++) {
//		if ((s1[i] == ' ' || s1[i] == ',' || s1[i] == ';'||s1[i]=='.')&&flag) {
//			flag = 0;
//			cnt++;
//			continue;
//		}
//		if(!(s1[i] == ' ' || s1[i] == ',' || s1[i] == ';' || s1[i] == '.'))
//		s[cnt] += s1[i],flag=1;
//	}
//	for (int j = 0; j < cnt; j++) {
//		char tmp = s[j][0];
//		for (int k = 0; k < s[j].size()- 1; k++) {
//			s[j][k] = s[j][k + 1];
//		}
//		s[j][s[j].size() - 1] = tmp;
//		s[j] += "ay";
//		if (j != cnt-1)cout << s[j] << " ";
//		else cout << s[j] << ".";
//	}
//
//	return 0;
//}

//6.阿拉伯数字转换汉字

//string s[] = { "零","一","二","三","四","五","六","七","八","九"};
//string s2[] = {"","十","百","千","万","十","百","千","亿"};
//int a[10];
//int main() {
//	int flag1 = 0, flag2 = 0;
//	string s1;
//	cin >> s1;
//	for (int i = 0; i < s1.size(); i++) {
//		a[i] = s1[i] - '0';
//	}
//	for (int j = 0; j < s1.size(); j++) {
//		if (a[j]) {
//			if (!flag1)flag1 = 1;
//			if (flag2)cout << "零";
//			cout << s[a[j]] << s2[s1.size() - 1 - j];
//		}
//		else {
//			if (flag1)flag2 = 1;
//			if (s1.size() - 1 - j == 4)cout << s2[4];
//		}
//	}
//
//	return 0;
//}

//7.

//int gcd(int a, int b) {
//	if (b == 0)return a;
//	else return gcd(b, a % b);
//}
//int main() {
//	int a, b;
//	scanf("%d/%d", &a, &b);
//	int ret = gcd(a, b);
//	printf("%d/%d", a / ret, b / ret);
//
//	return 0;
//}

//8.

//string s;
//int main() {
//	int n;
//	cin >> s >> n;
//	int minn = 0;
//	char min = s[0];
//	for (int i = 1; i <= s.size()-n; i++) {
//		int tmp = minn;
//		for (int j = tmp; j <=n+i-1; j++) {
//			//len - (j + 1)>=(len - n) - i  保证下一次可选范围大于等于需选长度
//			if (s[j] < min)min = s[j], minn = j;
//		}
//		cout << s[minn];
//		min=s[++minn];
//	}
//
//	return 0;
//}

//9.

//int judgeweek(int year,int month,int day) {
//	if (month == 1 || month == 2)month += 12, year--;
//	int w = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 400 + year / 4 - year / 100 + 1) % 7;
//	if (w == 5)return 1;
//	else return 0;
//}
//int main() {
//	int year, month, day=13;
//	int count = 0;
//	cin >> year;
//	for (month = 1; month <= 12; month++) {
//		if(judgeweek(year,month,day))count++;
//	}
//	cout << count;
//
//	return 0;
//}

//10.

//string s1, s2;
//int main() {
//	cin >> s1 >> s2;
//	int len1 = s1.size();
//	int len2 = s2.size();
//	if (len1 < len2) {
//		for (int i = 0; i < len2 - len1; i++) {
//			s1 = '0' + s1;
//		}
//	}
//	else {
//		for (int i = 0; i < len1 - len2; i++) {
//			s2 = '0' + s2;
//		}
//	}
//	len1 = s1.size();
//	int jw = 0;
//	for (int j = len1 - 1; j >= 0; j--) {
//		int tmp=s1[j] - '0' + s2[j] - '0'+ jw;
//		jw = tmp / 10;
//		s1[j] = char(tmp % 10 + '0');
//	}
//	if (jw) {
//		char happy = char(jw + '0');
//		s1 = happy + s1;
//	}
//	cout << s1;
//
//	return 0;
//}

//11.

//int tong[15];
//int ans[15];
//int n;
//void DFS(int num) {
//	if (num > 1) {
//		if (!isprime[ans[num] + ans[num - 1]])return;
//	}
//	if (num == n) {
//		if (isprime[1 + ans[num]]) {
//			for (int i = 1; i <= num; i++)cout << ans[i] << " ";
//			cout << endl;
//		}
//		else return;
//	}
//	for (int i = 2; i <= n; i++) {
//		if (!tong[i]) {
//			tong[i] = 1;
//			ans[num+1] = i;
//			DFS(num+1);
//			tong[i] = 0;
//		}
//	}
//
//}
//int main() {
//	judge(100);
//	cin >> n;
//	ans[1] = 1;
//	tong[1] = 1;
//	DFS(1);
//
//	return 0;
//}

//12.

//string s1, s2;
//int a[10000], b[10000], c[10000];
//int main() {
//	cin >> s1 >> s2;
//	int i = 0;
//	for (i = 1; i <= s1.size(); i++)a[i] = s1[s1.size() - i] - '0';
//	for (i = 1; i <= s1.size(); i++)b[i] = s2[s2.size() - i] - '0';
//	for (int j = 1; j <= s1.size(); j++) {
//		for (int k = 1; k <= s2.size(); k++) {
//			c[j + k - 1] += a[j] * b[k];
//		}
//	}
//	for (i = 1; i < s1.size() + s2.size(); i++) {
//		c[i + 1] += c[i] / 10;
//		c[i] %= 10;
//	}
//	int len = s1.size() + s2.size();
//	if (c[len] == 0 && len)len--;
//	for (i = len; i >= 1; i--)cout << c[i];
//
//	return 0;
//}

//13.

//int main() {
//	printf("A的名次是:3\n");
//	printf("B的名次是:1\n");
//	printf("C的名次是:5\n");
//	printf("D的名次是:2\n");
//	printf("E的名次是:4\n");
//	return 0;
//}

//14.

//int m, n;
//int rec(int pos, int turn) {
//	if (pos == 0)pos = n;
//	if (pos == n + 1)pos = 1;
//	if (turn == 0) {
//		if (pos == 1)return 1;
//		else return 0;
//	}
//	return rec(pos + 1, turn - 1) + rec(pos - 1, turn - 1);
//}
//int main() {
//	cin >> n >> m;
//	int count = rec(1, m);
//	cout << count;
//
//	return 0;
//}

//15.

//int a, b, c, d;
//int num[5][4] = { {2,1,0,2},{1,1,1,1},{0,0,2,1},{0,3,0,0},{1,0,0,1} };
//int ans[5];
//int main() {
//	int i = 0;
//	cin >> a >> b >> c >> d;
//	for (i = 0; i < 16; i++) {
//		int k = i % 5;
//		if (a - num[k][0] >= 0 && b - num[k][1] >= 0 && c - num[k][2] >= 0 && d - num[k][3] >= 0) {
//			a -= num[k][0], b -= num[k][1], c -= num[k][2], d -= num[k][3];
//			ans[k]++;
//		}
//	}
//	for (i = 0; i < 5; i++) {
//		cout << ans[i] << endl;
//	}
//
//	return 0;
//}

//16.

//int n, k, ans;
//void hanoi(int n, char a, char b, char c) {
//	if (n == 0)return;
//	hanoi(n - 1, a, c, b);
//	ans++;
//	if (ans == k)printf("%c->%c", a, c);
//	hanoi(n - 1, b, a, c);
//}
//int main() {
//	cin >> n >> k;
//	hanoi(n, 'a', 'b', 'c');
//
//	return 0;
//}

//17.

//string s1;
//string s[100];
//int main() {
//	getline(cin, s1);
//	int cnt = 1;
//	int flag = 0;
//	for (int i = 0; i < s1.size() - 1; i++) {
//		if (s1[i] != ' ') {
//			s[cnt] += s1[i];
//			flag = 1;
//		}
//		if (flag && s1[i] == ' ') {
//			cnt++;
//			flag = 0;
//		}
//	}
//	for (int j = 1; j <= cnt; j++) {
//		cout << s[j].size() << " ";
//	}
//
//	return 0;
//}

