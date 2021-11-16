#include <iostream>
#include <Windows.h>
#include "car_obj.cpp"

#define DYNAMIC_MASS(int) car = new car_obj[num + 1]

using namespace std;
//��������� ����������
bool* music;
bool* light;
bool* door;
bool* alarm;
string name[100000];
string color[100000];

void car_create(int num)
{
	cout << "������ �������:\n������� ��������:" << endl;
	cin >> name[num];
	cout << "������� ����:" << endl;
	cin >> color[num];
}

void car_ch_name(int num)
{
	cout << "������� ����� ��������: ";
	name[num] = "";
	cin >> name[num];
	cout << "��� ���� ��������." << endl;
	system("pause");
}

void car_ch_color(int num)
{
	cout << "������� ����� ����: ";
	color[num] = "";
	cin >> color[num];
	cout << "���� ��� �������." << endl;
	system("pause");
}

void car_ch_door(int num)
{
	if (door[num] == false) {
		door[num] = true;
		cout << "����� ���� �������." << endl;
		system("pause");
	}
	else {
		door[num] = false;
		cout << "����� ���� �������." << endl;
		system("pause");
	}
}
void car_ch_light(int num)
{
	if (light[num] == false) {
		light[num] = true;
		cout << "���� ��� �������." << endl;
		system("pause");
	}
	else {
		light[num] = false;
		cout << "���� ��� ��������." << endl;
		system("pause");
	}
}


void car_ch_music(int num)
{
	if (music[num] == false) {
		music[num] = true;
		cout << "������ ���� ��������." << endl;
		system("pause");
	}
	else {
		music[num] = false;
		cout << "������ ���� ���������." << endl;
		system("pause");
	}
}
void car_ch_alarm(int num)
{
	if (alarm[num] == false) {
		alarm[num] = true;
		cout << "������������ ���� ��������." << endl;
		system("pause");
	}
	else {
		alarm[num] = false;
		cout << "������������ ���� ���������." << endl;
		system("pause");
	}
}
void car_delete(int num)
{
	music[num] = false;
	door[num] = false;
	light[num] = false;
	name[num] = "";
	color[num] = "";
}

string _M(int num)
{
	if (music[num] == false) return("is Off");
	else return("is on");
}
string _l(int num)
{
	if (light[num] == false) return("is Off");
	else return("is on");
}
string _a(int num)
{
	if (alarm[num] == false) return("is Off");
	else return("is on");
}


string _d(int num)
{
	if (door[num] == false) return("�������");
	else return("�������");
}

string name_f(car_obj _s)
{
	string l;
	l = _s.car_name_f();
	return(l);
}

void car_list_out(int num)
{
	if (name[num] == "")	cout << num << " - ������ �� �������." << endl;
	else
	{
		cout << num << " - " << "��������: " << name[num] << "	����: " << color[num] << " ����: " << _l(light[num]) << "������: " << _M(music[num]) << " �����: " << _d(door[num]) << endl;
	}
}

bool select(int com, bool flag, int num)
{
	switch (com)
	{
	case 1: {car_ch_name(num); break; }
	case 2: {car_ch_color(num); break; }
	case 3: {car_ch_door(num); break; }
	case 4: {car_ch_music(num); break; }
	case 5: {car_delete(num); flag = true; break; }
	case 6: {flag = true; break; }
	case 7: {car_ch_light(num); break; }
	case 8: {car_ch_alarm(num); break; }
		  system("pause");
	}
	return(flag);
}

void main()
{
	system("chcp 1251");

	int com_1;
	cout << "1 - ���\n2 - ��������������\n3 - �����������" << endl;
	cin >> com_1;
	switch (com_1)
	{
	case 1:	/*���*/
	{
		car_obj* car;
		int num = 0, max = num;

		DYNAMIC_MASS(num);

		num++;

		while (num != 0)
		{
			cout << "���� �� ������ ����� �� ��������� 0" << endl;

			cout << "If you want to check all car press: -1 . Else press enything else to select car." << endl;

			cout << "The car:" << endl;

			cin >> num;

			if (num == -1)
			{
				int k = 0;
				if (max == 0)
				{
					cout << "����� ���" << endl;
					goto end;
				}
				for (num = 1; num <= max; num++)
				{
					if (name_f(car[num]) != "")
					{
						k++;
						car[num].car_list_out(num);
					}
				}
				if (k == 0)
				{
					cout << "����� ���" << endl;
				}
				goto end;
			}

			if (num > max)
			{
				int end = max;
				car_obj* caro;
				caro = new car_obj[num + 1];
				for (max = 0; max < end; max++)
				{
					caro[max].car_list_ch(car[max]);
				}

				car = new car_obj[num + 1];
				for (max = 0; max < num; max++)
				{
					car[max].car_list_ch(caro[max]);
				}
			}

			if (num == 0) goto end;

			car[num].car_mode();

			system("pause");
			system("cls");

		end:;
		}
		break;
	}
	case 2:	/*��������������*/
	{
		int num = -1, max = num;

		/*cout << "Number of car:" << endl;
		cin >> num;*/
		/*num = 1;
		max = num;*/

		music = new bool[num + 1];
		door = new bool[num + 1];

		for (int n = 0; n < num + 1; n++)
		{
			music[n] = door[n] = false;
		}

		while (num != 0)
		{
			cout << "���� �� ������ ����� �� ���������, ������� 0" << endl;

			cout << "If you want to check all car press: -1 . Else press enything else." << endl;

			cout << "������" << endl;
			cin >> num;

			bool flag = false;

			if (num == -1)
			{
				int k = 0;
				if (max == 0)
				{
					cout << "����� ���" << endl;
					goto end2;
				}
				for (num = 1; num <= max; num++)
				{
					if (name[num] != "")
					{
						k++;
						car_list_out(num);
					}
				}
				if (k == 0)
				{
					cout << "����� ���" << endl;
				}
				goto end2;
			}

			if (max < num)
			{
				int end = max;

				bool* indx1;
				indx1 = new bool[num + 1];

				bool* indx2;
				indx2 = new bool[num + 1];

				for (int n = 0; n < num + 1; n++)
				{
					indx1[n] = indx2[n] = false;
				}

				for (max = 0; max < end; max++)
				{
					indx1[max] = music[max];
					indx2[max] = door[max];
				}

				door = new bool[num + 1];
				music = new bool[num + 1];

				for (int n = 0; n < num + 1; n++)
				{
					music[n] = door[n] = false;
				}

				for (max = 0; max < num; max++)
				{
					door[max] = indx2[max];
					music[max] = indx1[max];
				}

			}

			if (num == 0) goto end2;

			while (flag == false)
			{

				if (name[num] == "") car_create(num);

				cout << endl << "��������: " << name[num] << endl << "����: " << color[num] << endl;
				cout << "������: " << _l(num) << endl << "�����: " << _d(num) << endl;

				cout << "��� �� ������ �������?:" << endl <<
					"1 - �������� ���" << endl <<
					"2 - �������� ����" << endl <<
					"3 - ���/���� �����" << endl <<
					"4 - ���/���� ������" << endl <<
					"5 - ������� ����" << endl <<
					"6 - ������� ����" << endl;
				int com = 0;
				cin >> com;
				flag = select(com, flag, num);
			}

			system("pause");
			system("cls");
		end2:;
		}
		break;
	}
	case 3:	/*�����������*/
	{
		int COM_STR, NUM_STR = -1, MAX_STR = NUM_STR;

		/*cout << "Number of car:" << endl;
		cin >> NUM_STR;*/

		music = new bool[NUM_STR + 1];
		door = new bool[NUM_STR + 1];

		for (int n = 0; n < NUM_STR + 1; n++)
		{
			music[n] = door[n] = false;
		}

		while (NUM_STR != 0)
		{
			cout << "���� �� ������ ����� �� ���������, ������� 0" << endl;

			cout << "���� �� ������ ���������� ��� ������, �������: -1 . ����� ������� ������." << endl;

			cout << "������:" << endl;

			cin >> NUM_STR;

			bool flag = false;

			if (NUM_STR == -1)
			{
				int k = 0;
				if (MAX_STR == 0)
				{
					cout << "����� ���" << endl;
					goto end3;
				}
				for (NUM_STR = 1; NUM_STR <= MAX_STR; NUM_STR++)
				{
					if (name[NUM_STR] != "")
					{
						k++;
						car_list_out(NUM_STR);
					}
				}
				if (k == 0)
				{
					cout << "����� ���" << endl;
				}
				goto end3;
			}

			if (NUM_STR > MAX_STR)
			{
				int end = MAX_STR;

				bool* indx1;
				indx1 = new bool[NUM_STR + 1];

				bool* indx2;
				indx2 = new bool[NUM_STR + 1];

				for (int n = 0; n < NUM_STR + 1; n++)
				{
					indx1[n] = indx2[n] = false;
				}

				for (MAX_STR = 0; MAX_STR < end; MAX_STR++)
				{
					indx1[MAX_STR] = music[MAX_STR];
					indx2[MAX_STR] = door[MAX_STR];
				}

				door = new bool[NUM_STR + 1];
				music = new bool[NUM_STR + 1];

				for (int n = 0; n < NUM_STR + 1; n++)
				{
					music[n] = door[n] = false;
				}

				for (MAX_STR = 0; MAX_STR < NUM_STR; MAX_STR++)
				{
					door[MAX_STR] = indx2[MAX_STR];
					music[MAX_STR] = indx1[MAX_STR];
				}

			}

			if (NUM_STR == 0) goto end3;

			while (flag == false)
			{

				if (name[NUM_STR] == "")
				{
					cout << "������ �������:\n������� ��������:" << endl;
					cin >> name[NUM_STR];
					cout << "������� ����:" << endl;
					cin >> color[NUM_STR];
				}

				cout << endl << "��������: " << name[NUM_STR] << endl << "Color: " << color[NUM_STR] << endl;
				cout << "������: " << _l(NUM_STR) << endl << "Door: " << _d(NUM_STR) << endl;

				cout << "��� �� ������ �������?:" << endl <<
					"1 - �������� ���" << endl <<
					"2 - �������� ����" << endl <<
					"3 - ���/���� �����" << endl <<
					"4 - ���/���� ����" << endl <<
					"5 - ������� ����" << endl <<
					"6 - ������� ����" << endl;
				int com = 0;
				cin >> com;

				//select start

				switch (com)
				{
				case 1: /*Name change	*/ {
					cout << "������� ����� ���: ";
					name[NUM_STR] = "";
					cin >> name[NUM_STR];
					cout << "��� ���� ��������." << endl;
					system("pause");
					break;
				}
				case 2: /*Colore change	*/ {
					cout << "������� ����� ����: ";
					color[NUM_STR] = "";
					cin >> color[NUM_STR];
					cout << "���� ��� �������." << endl;
					system("pause");
					break; }
				case 3: /*Door change	*/ {
					if (door[NUM_STR] == false) {
						door[NUM_STR] = true;
						cout << "����� ���� �������." << endl;
						system("pause");
					}
					else {
						door[NUM_STR] = false;
						cout << "����� ���� �������." << endl;
						system("pause");
					}; break; }
				case 4: /*music change	*/ {
					if (music[NUM_STR] == false) {
						music[NUM_STR] = true;
						cout << "���� ��� �������." << endl;
						system("pause");
					}
					else {
						music[NUM_STR] = false;
						cout << "���� ��� ��������." << endl;
						system("pause");
					} break; }
				case 5: /*Delete car	*/ {
					music[NUM_STR] = false;
					door[NUM_STR] = false;
					name[NUM_STR] = "";
					color[NUM_STR] = "";; flag = true; break; }
				case 6: {flag = true; break; }
					  system("pause");
				}
			}

			system("pause");
			system("cls");
		end3:;
		}
		break;
	}
	}
};