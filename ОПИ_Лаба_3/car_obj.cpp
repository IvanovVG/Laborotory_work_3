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
		  cout << "Машина создана:\nВведите название:" << endl;
		  cin >> name;
		  cout << "Введите цвет:" << endl;
		  cin >> color;
	  }

	  void car_ch_name()
	  {
		  cout << "Введите новое имя: ";
		  name = "";
		  cin >> name;
		  cout << "Имя было изменено." << endl;
		  system("pause");
	  }

	  void car_ch_color()
	  {
		  cout << "Введите новый цвет: ";
		  color = "";
		  cin >> color;
		  cout << "Цвет был изменен." << endl;
		  system("pause");
	  }


	  void car_ch_door()
	  {
		  if (door == false) {
			  door = true;
			  cout << "Двери были открыты." << endl;
			  system("pause");
		  }
		  else {
			  door = false;
			  cout << "Двери были закрыты." << endl;
			  system("pause");
		  }
	  }
	  void car_ch_light()
	  {
		  if (light == false) {
			  light = true;
			  cout << "Свет был включен." << endl;
			  system("pause");
		  }
		  else {
			  door = false;
			  cout << "Свет был выключен." << endl;
			  system("pause");
		  }
	  }

	  void car_ch_music()
	  {
		  if (music == false) {
			  music = true;
			  cout << "музыка была включена." << endl;
			  system("pause");
		  }
		  else {
			  music = false;
			  cout << "музыка была выключена." << endl;
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
		  if (light == false) return("закрыта");
		  else return("открыта");
	  }
	  string _d()
	  {
		  if (door == false) return("закрыта");
		  else return("открыта");
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
			  cout << num << " - " << "Название: " << name << "	Цвет: " << color << "	Музыка: " << _M() << " Свет: " << _l()<< "	дверь: " << _d() << endl;
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

			  cout << endl << "Название: " << name << endl << "Цвет: " << color << endl;
			  cout << "Музыка: " << _M() << endl << "дверь: " << _d()<<"Свет:"<<_l() << endl;

			  cout << "Что вы хотите сделать?:" << endl <<
				  "1 - Изменить имя" << endl <<
				  "2 - Изменить цвет" << endl <<
				  "3 - Отк/закр двери" << endl <<
				  "4 - Вкл/выкл музыку" << endl <<
				  "5 - Удалить авто" << endl <<
				  "6 - Сменить авто" << endl <<
				  "7 - вкл/выкл свет" << endl;
			  int com = 0;
			  cin >> com;
			  flag = select(com, flag);
		  }
	  }
};