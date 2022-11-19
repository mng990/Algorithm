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
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string num;
		cin >> num;

		Number testNum(num);


		cout << "#" << test_case << " " << testNum;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}