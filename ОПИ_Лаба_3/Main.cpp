#include <iostream>
#include <Windows.h>
#include "car_obj.cpp"

#define DYNAMIC_MASS(int) car = new car_obj[num + 1]

using namespace std;
//обьявлены переменные
bool* music;
bool* light;
bool* door;
bool* alarm;
string name[100000];
string color[100000];

void car_create(int num)
{
	cout << "Машина создана:\nВведите название:" << endl;
	cin >> name[num];
	cout << "Введите цвет:" << endl;
	cin >> color[num];
}

void car_ch_name(int num)
{
	cout << "Введите новое название: ";
	name[num] = "";
	cin >> name[num];
	cout << "Имя было изменено." << endl;
	system("pause");
}

void car_ch_color(int num)
{
	cout << "Введите новый цвет: ";
	color[num] = "";
	cin >> color[num];
	cout << "Цвет был изменен." << endl;
	system("pause");
}

void car_ch_door(int num)
{
	if (door[num] == false) {
		door[num] = true;
		cout << "Двери были открыты." << endl;
		system("pause");
	}
	else {
		door[num] = false;
		cout << "Двери были закрыты." << endl;
		system("pause");
	}
}
void car_ch_light(int num)
{
	if (light[num] == false) {
		light[num] = true;
		cout << "Свет был включен." << endl;
		system("pause");
	}
	else {
		light[num] = false;
		cout << "Свет был выключен." << endl;
		system("pause");
	}
}


void car_ch_music(int num)
{
	if (music[num] == false) {
		music[num] = true;
		cout << "музыка была включена." << endl;
		system("pause");
	}
	else {
		music[num] = false;
		cout << "музыка была выключена." << endl;
		system("pause");
	}
}
void car_ch_alarm(int num)
{
	if (alarm[num] == false) {
		alarm[num] = true;
		cout << "Сигнализация была включена." << endl;
		system("pause");
	}
	else {
		alarm[num] = false;
		cout << "Сигнализация была выключена." << endl;
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
	if (door[num] == false) return("закрыта");
	else return("открыта");
}

string name_f(car_obj _s)
{
	string l;
	l = _s.car_name_f();
	return(l);
}

void car_list_out(int num)
{
	if (name[num] == "")	cout << num << " - машина не создана." << endl;
	else
	{
		cout << num << " - " << "Название: " << name[num] << "	Цвет: " << color[num] << " Свет: " << _l(light[num]) << "Музыка: " << _M(music[num]) << " Дверь: " << _d(door[num]) << endl;
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
	cout << "1 - ООП\n2 - Функциональное\n3 - Структурное" << endl;
	cin >> com_1;
	switch (com_1)
	{
	case 1:	/*ООП*/
	{
		car_obj* car;
		int num = 0, max = num;

		DYNAMIC_MASS(num);

		num++;

		while (num != 0)
		{
			cout << "Если вы хотите выйти из программы 0" << endl;

			cout << "If you want to check all car press: -1 . Else press enything else to select car." << endl;

			cout << "The car:" << endl;

			cin >> num;

			if (num == -1)
			{
				int k = 0;
				if (max == 0)
				{
					cout << "Машин нет" << endl;
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
					cout << "Машин нет" << endl;
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
	case 2:	/*Функциональное*/
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
			cout << "Если вы хотите выйти из программы, нажмите 0" << endl;

			cout << "If you want to check all car press: -1 . Else press enything else." << endl;

			cout << "Машина" << endl;
			cin >> num;

			bool flag = false;

			if (num == -1)
			{
				int k = 0;
				if (max == 0)
				{
					cout << "Машин нет" << endl;
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
					cout << "Машин нет" << endl;
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

				cout << endl << "Название: " << name[num] << endl << "Цвет: " << color[num] << endl;
				cout << "Музыка: " << _l(num) << endl << "Дверь: " << _d(num) << endl;

				cout << "Что вы хотите сделать?:" << endl <<
					"1 - Изменить имя" << endl <<
					"2 - Изменить цвет" << endl <<
					"3 - Отк/закр двери" << endl <<
					"4 - Вкл/выкл музыку" << endl <<
					"5 - Удалить авто" << endl <<
					"6 - Сменить авто" << endl;
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
	case 3:	/*Структурное*/
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
			cout << "Если вы хотите выйти из программы, нажмите 0" << endl;

			cout << "Если вы хотите посмотреть все машины, нажмите: -1 . Иначе нажмите другое." << endl;

			cout << "Машины:" << endl;

			cin >> NUM_STR;

			bool flag = false;

			if (NUM_STR == -1)
			{
				int k = 0;
				if (MAX_STR == 0)
				{
					cout << "Машин нет" << endl;
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
					cout << "Машин нет" << endl;
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
					cout << "Машина создана:\nВведите название:" << endl;
					cin >> name[NUM_STR];
					cout << "Введите цвет:" << endl;
					cin >> color[NUM_STR];
				}

				cout << endl << "Название: " << name[NUM_STR] << endl << "Color: " << color[NUM_STR] << endl;
				cout << "Музыка: " << _l(NUM_STR) << endl << "Door: " << _d(NUM_STR) << endl;

				cout << "Что вы хотите сделать?:" << endl <<
					"1 - Изменить имя" << endl <<
					"2 - Изменить цвет" << endl <<
					"3 - Отк/закр двери" << endl <<
					"4 - Вкл/выкл свет" << endl <<
					"5 - Удалить авто" << endl <<
					"6 - Сменить авто" << endl;
				int com = 0;
				cin >> com;

				//select start

				switch (com)
				{
				case 1: /*Name change	*/ {
					cout << "Введите новое имя: ";
					name[NUM_STR] = "";
					cin >> name[NUM_STR];
					cout << "Имя было изменено." << endl;
					system("pause");
					break;
				}
				case 2: /*Colore change	*/ {
					cout << "Введите новый цвет: ";
					color[NUM_STR] = "";
					cin >> color[NUM_STR];
					cout << "Цвет был изменен." << endl;
					system("pause");
					break; }
				case 3: /*Door change	*/ {
					if (door[NUM_STR] == false) {
						door[NUM_STR] = true;
						cout << "Двери были открыты." << endl;
						system("pause");
					}
					else {
						door[NUM_STR] = false;
						cout << "Двери были закрыты." << endl;
						system("pause");
					}; break; }
				case 4: /*music change	*/ {
					if (music[NUM_STR] == false) {
						music[NUM_STR] = true;
						cout << "Свет был включён." << endl;
						system("pause");
					}
					else {
						music[NUM_STR] = false;
						cout << "Свет был выключен." << endl;
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