#include <iostream>
#include <Windows.h>

using namespace std;

class car_obj
{
	bool music = false;
	bool door = false;
	bool light = false;
	string name = "";
	string color = "";

public:	car_obj() :music(false), door(false), light(false), name(""), color("") {}

	  car_obj car_list_ch(car_obj _s)
	  {
		  music = _s.music;
		  door = _s.door;
		  name = _s.name;
		  color = _s.color;
		  light = _s.light;
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

	  void car_delete()
	  {
		  music = false;
		  door = false;
		  name = "";
		  color = "";
	  }

	  string _M()
	  {
		  if (music == false) return("is Off");
		  else return("is on");
	  }
	  string _l()
	  {
		  if (light == false) return("�������");
		  else return("�������");
	  }
	  string _d()
	  {
		  if (door == false) return("�������");
		  else return("�������");
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
			  cout << num << " - " << "��������: " << name << "	����: " << color << "	������: " << _M() << " ����: " << _l()<< "	�����: " << _d() << endl;
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
			  cout << "������: " << _M() << endl << "�����: " << _d()<<"����:"<<_l() << endl;

			  cout << "��� �� ������ �������?:" << endl <<
				  "1 - �������� ���" << endl <<
				  "2 - �������� ����" << endl <<
				  "3 - ���/���� �����" << endl <<
				  "4 - ���/���� ������" << endl <<
				  "5 - ������� ����" << endl <<
				  "6 - ������� ����" << endl <<
				  "7 - ���/���� ����" << endl;
			  int com = 0;
			  cin >> com;
			  flag = select(com, flag);
		  }
	  }
};