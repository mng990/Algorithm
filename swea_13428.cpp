#include<bits/stdc++.h>

using namespace std;

class Number {
public:
	string numberStr;
	int numberInit;
	int numberMin;
	int numberMax;
	int minHead;
	int maxHead;


	Number(string numStr) {
		numberInit = stoi(numStr);
		numberStr = numStr;
		numberMin = numberInit;
		numberMax = numberInit;

		searchHead(0, true, true);
	}

	Number() {
		numberStr = "";
		numberInit = 0;
		numberMin = -1;
		numberMax = -1;
	}

	void searchHead(int depth, bool searchMin, bool searchMax) {

		if (depth == numberStr.length() || (!searchMin && !searchMax)) return;


		int pos, minIdx = -1, maxIdx = -1;
		int nowHead = numberStr[depth] - '0';
		
		minHead = nowHead;
		maxHead = nowHead;
		
		for (int i = depth + 1; i < numberStr.length() ; i++ ){
		
			pos = numberStr[i] - '0';
			if (searchMin && minHead >= pos && !(depth == 0 && pos == 0)) {
				minHead = pos;
				minIdx = i;
			}
			if (searchMax && maxHead <= pos) {
				maxHead = pos;
				maxIdx = i;
			}
		}

		if (minIdx != -1 ) searchMin = false;
		if (maxIdx != -1) searchMax = false;


		if (!searchMin && numberMin == numberInit) {
			searchMin = updateAnswer(numberMin, depth, minHead, minIdx);
		}

		if (!searchMax && numberMax == numberInit) {
			searchMax = updateAnswer(numberMax, depth, maxHead, maxIdx);
		}


		return searchHead(depth + 1, searchMin, searchMax);
	}

	bool updateAnswer(int& answer, int depth, int head, int headIdx) {
		string ansStr = numberStr;

		ansStr[headIdx] = ansStr[depth];
		ansStr[depth] = head + '0';

		answer = stoi(ansStr);

		return answer == numberInit;
	}

	friend ostream& operator<<(ostream& os, const Number& N) {
		os << N.numberMin << " " << N.numberMax << endl;

		return os;
	}

};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string num;
		cin >> num;

		Number testNum(num);


		cout << "#" << test_case << " " << testNum;

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}