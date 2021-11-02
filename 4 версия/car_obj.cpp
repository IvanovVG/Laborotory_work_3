#include <iostream>
#include <Windows.h>

using namespace std;

class car_obj
{
	bool music = false;
	bool door = false;
	bool light = false;
	bool alarm = false;
	bool conder = false;
	string name = "";
	string color = "";

public:	car_obj() :music(false), door(false), light(false), name(""), color(""), alarm(false), conder(false) {}

	  car_obj car_list_ch(car_obj _s)
	  {
		  music = _s.music;
		  door = _s.door;
		  name = _s.name;
		  color = _s.color;
		  light = _s.light;
		  alarm = _s.alarm;
		  conder = _s.conder;
		  return(_s);
	  }

	  //car_obj car_list_add(int n, int max, car_obj* prot)
	  //{
		 // car_obj* caro;
		 // caro = new car_obj[n + 1];
		 // for (max = 0; max < n; max++)
		 // {
			//  caro[max].car_list_ch(prot[max]);
		 // }
		 // prot = new car_obj[n + 1];
		 // for (max = 0; max < n; max++)
		 // {
			//  prot[max].car_list_ch(caro[max]);
		 // }
		 // return(prot[n]);
	  //}

	  void car_create()
	  {
		  cout << "������ �������:\n������� ��������:" << endl;
		  cin >> name;
		  cout << "������� ����:" << endl;
		  cin >> color;
	  }

	  void car_ch_name()
	  {
		  cout << "������� ����� ���: ";
		  name = "";
		  cin >> name;
		  cout << "��� ���� ��������." << endl;
		  system("pause");
	  }

	  void car_ch_color()
	  {
		  cout << "������� ����� ����: ";
		  color = "";
		  cin >> color;
		  cout << "���� ��� �������." << endl;
		  system("pause");
	  }


	  void car_ch_door()
	  {
		  if (door == false) {
			  door = true;
			  cout << "����� ���� �������." << endl;
			  system("pause");
		  }
		  else {
			  door = false;
			  cout << "����� ���� �������." << endl;
			  system("pause");
		  }
	  }
	  void car_ch_light()
	  {
		  if (light == false) {
			  light = true;
			  cout << "���� ��� �������." << endl;
			  system("pause");
		  }
		  else {
			  door = false;
			  cout << "���� ��� ��������." << endl;
			  system("pause");
		  }
	  }

	  void car_ch_music()
	  {
		  if (music == false) {
			  music = true;
			  cout << "������ ���� ��������." << endl;
			  system("pause");
		  }
		  else {
			  music = false;
			  cout << "������ ���� ���������." << endl;
			  system("pause");
		  }
	  }
	  void car_ch_alarm()
	  {
		  if (alarm == false) {
			  alarm = true;
			  cout << "������������ ���� ��������." << endl;
			  system("pause");
		  }
		  else {
			  alarm = false;
			  cout << "������������ ���� ���������." << endl;
			  system("pause");
		  }
	  }
	  void car_ch_conder()
	  {
		  if (conder == false) {
			  conder = true;
			  cout << "����������� ��� ���������." << endl;
			  system("pause");
		  }
		  else {
			  conder = false;
			  cout << "����������� ��� ��������." << endl;
			  system("pause");
		  }
	  }

	  void car_delete()
	  {
		  music = false;
		  door = false;
		  name = "";
		  color = "";
		  light = false;
		  conder = false;
		  alarm = false;
	  }

	  string _M()
	  {
		  if (music == false) return("is Off");
		  else return("is on");
	  }
	  string _l()
	  {
		  if (light == false) return("����");
		  else return("���");
	  }
	  string _d()
	  {
		  if (door == false) return("�������");
		  else return("�������");
	  }
	  string _a()
	  {
		  if (alarm == false) return("is Off");
		  else return("is on");
	  }
	  string _c()
	  {
		  if (conder == false) return("is Off");
		  else return("is on");
	  }

	  string car_name_f()
	  {
		  return(name);
	  }

	  void car_list_out(int num)
	  {
		  if (name == "");
		  else
		  {
			  cout << num << " - " << "��������: " << name << "	����: " << color << "������: " << _M() << " ����: " << _l()<< "	�����: " << _d() << " ������������: " << _a() << " �����������: " << _c() << endl;
		  }
	  }

	  bool select(int com, bool flag)
	  {
		  switch (com)
		  {
		  case 1: {car_ch_name(); break; }
		  case 2: {car_ch_color(); break; }
		  case 3: {car_ch_door(); break; }
		  case 4: {car_ch_music(); break; }
		  case 5: {car_delete(); flag = true; break; }
		  case 6: {flag = true; break; }
		  case 7: {car_ch_light(); break; }
		  case 8: {car_ch_alarm(); break; }
		  case 9: {car_ch_conder(); break; }
				system("pause");
		  }
		  return(flag);
	  }

	  void car_mode()
	  {
		  bool flag = false;
		  while (flag == false)
		  {
			  if (name == "") car_create();

			  cout << endl << "��������: " << name << endl << "����: " << color << endl;
			  cout << "������: " << _M() << endl << "�����: " << _d()<<" ����: "<<_l() << " ������������: " << _a() << " �����������: " << _c() << endl;

			  cout << "��� �� ������ �������?:" << endl <<
				  "1 - �������� ���" << endl <<
				  "2 - �������� ����" << endl <<
				  "3 - ���/���� �����" << endl <<
				  "4 - ���/���� ������" << endl <<
				  "5 - ������� ����" << endl <<
				  "6 - ������� ����" << endl <<
				  "7 - ���/���� ����" << endl <<
				  "8 - ���/���� ������������" << endl <<
				  "9 - ���/���� �����������" << endl;
			  int com = 0;
			  cin >> com;
			  flag = select(com, flag);
		  }
	  }
};