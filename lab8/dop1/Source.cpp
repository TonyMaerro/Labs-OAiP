#include <iostream>
#include <windows.h>
#include "check.h"

//������� ������� � ������������� �������, � ��������� �� � ����������.
//��������� ����������� ����� ��������� � ������� ���, ����� � �� ������
//��� ���������� ���������� �������.

bool isProvedFl(string num)
{
	if (num == "")
		return false;
	char nums[] = "-0123456789.";
	int cnt = 0;
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < strlen(nums); j++)
		{
			if (num[i] == nums[j])
			{
				if (num[i] == '.')
				{
					cnt++;
					if (cnt == 2)
						return false;
				}
				if (num[i] == '-' && i != 0)
					return false;
				if (num[i] == '-' && i == 0 && num.size() == 1)
					return false;

				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	return true;
}

int cnt = 0;
float MAX;

struct Float
{
	float num;
	Float* next;
	Float* end,
		* start;
} *queue, *newEl;

void input(float num)
{
	cnt++;
	newEl->num = num;
	queue->end->next = newEl;
	queue->end = newEl;
	queue->end->next = queue->start;
	newEl = new Float;
}
void output()
{
	for (int i = 0; i < cnt; i++)
	{
		cout << queue->num << "\t";
		queue = queue->next;
	}
	ent;
	queue = queue->start;
}

int main()
{
	ru;
	queue = new Float;
	string mFl,
		   mPoint;
	int point;
	float num;
	queue->start = queue;
	newEl = new Float;
	newEl->start = queue->start;
	newEl->end = queue->end;
	queue->start = queue->end = queue = newEl;
	bool isExit = false;

	while (!isExit)
	{
		cls;
		cout << "1) ������ �������\n"
			<< "2) ������� ��� �������\n"
			<< "3) ������� �����\n"
			<< "4) Exit\n"
			<< "������� ����� ����: ";
		getline(cin, mPoint);
		while (!isProved(mPoint, 1, 4))
		{
			cls;
			cout << "1) ������ �������\n"
				<< "2) ������� ��� �������\n"
				<< "3) ������� �����\n"
				<< "4) Exit\n"
				<< "������� ����� ���� �� 1 �� 3: ";
			getline(cin, mPoint);
		}
		cls;
		point = stoi(mPoint);
		switch (point)
		{
		case 1: // add
		{
			cout << "������� �����: ";
			getline(cin, mFl);
			while (!isProvedFl(mFl))
			{
				cls;
				cout << "������� �����: ";
				getline(cin, mFl);
			}
			num = stof(mFl);

			if (cnt == 0 || MAX < num)
				MAX = num;
			
			input(num);
			pause;
			break;
		}
		case 2: // out
		{
			if (cnt == 0)
			{
				cout << "�������� �������� � �������!\n";
				pause;
				break;
			}
			cout << "������� ������� ��: \t";
			output();
			pause;
			break;
		}
		case 3: // correct
		{
			if (cnt == 0)
			{
				cout << "��������� ������!" << endl;
				pause;
				break;
			}
			while (MAX != queue->num)
			{
				newEl = queue;
				queue = queue->next;
				queue->end = newEl;
			}

			queue->start = queue;
			queue = queue->start;
			cout << "����� ������!\n";
			newEl = new Float;
			pause;
			break;
		}
		case 4: // Exit
		{
			isExit = true;
			pause;
			break;
		}
		}
	}

	return 0;
}