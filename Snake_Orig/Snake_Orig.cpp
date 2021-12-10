#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <fstream>

using namespace std;
int const weight = 30;
int const hight = 28;
int x, y, apple_x, apple_y;
int score;
int g;
int tale_x[100], tale_y[100];
int tails_apple = 0;
int control_score_for_print = 0;
int number = 0;
enum movement { STOP = 0, RIGHT, LEFT, UP, DOWN };
movement trafic;
bool game_status_end;
struct date
{
	int score_2;
	string namesurname;;


};
void begin()
{
	game_status_end = false;
	trafic = STOP;
	x = weight / 2;
	y = hight / 2;
	apple_x = rand() % (weight - 1);
	apple_y = rand() % (hight - 1);
	while (apple_x > weight || apple_y > hight)
	{
		if (apple_x > weight || apple_y > hight)
		{
			apple_x = rand() % (weight - 1);
			apple_y = rand() % (hight - 1);
		}
	}

	score = 0;
}
void Draw()
{
	g = rand() % 10;
	system("cls");
	int a = 120;
	if (a == 10)
	{
		cout << '\n';
		if (control_score_for_print == 1)
		{
			cout << "SCORE " << score << " " << "YAMI" << endl;
			control_score_for_print = 0;

		}
		else cout << "SCORE " << score << endl;
	}
	else {
		cout << '\n';
		if (control_score_for_print == 1)
		{
			cout << "SCORE " << score << " " << "YAMI" << endl;
			control_score_for_print = 0;
			a = a - 10;
		}
		else cout << "SCORE " << score << endl;
	}


	for (int i = 0; i < weight + 1; i++)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
		while (g == 0)
		{
			g = rand() % 10;
		}
		cout << "#";
	}

	cout << endl;
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < weight + 1; j++)
		{
			if (j == 0 || j == weight - 1)
			{


				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
				while (g == 0)
				{
					g = rand() % 10;
				}
				cout << "#";
			}

			if (i == y && j == x)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
				while (g == 0)
				{
					g = rand() % 10;
				}
				cout << "*";
			}
			else
				if (i == apple_y && j == apple_x)
				{
					cout << "0";
				}

				else {
					bool print = false;
					for (int k = 0; k < tails_apple; k++)
					{

						if (tale_x[k] == j && tale_y[k] == i)
						{
							print = true;
							cout << "*";
						}
					}
					if (print == false)
					{
						cout << " ";
					}

				}
		}
		cout << endl;
	}

	for (int i = 0; i < weight + 1; i++)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
		while (g == 0)
		{
			g = rand() % 10;
		}
		cout << "#";
	}

	cout << endl;
	Sleep(10);

}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			trafic = LEFT;
			break;
		case 'w':
			trafic = UP;
			break;
		case'd':
			trafic = RIGHT;
			break;
		case 's':
			trafic = DOWN;
			break;
		case 'f':
			game_status_end = true;
			break;
		}
	}
}
void core()
{
	int pref_x = tale_x[0];
	int pref_y = tale_y[0];
	int pref_2x, pref_2y;
	tale_x[0] = x;
	tale_y[0] = y;
	for (int i = 1; i < tails_apple; i++)
	{
		pref_2x = tale_x[i];
		pref_2y = tale_y[i];
		tale_x[i] = pref_x;
		tale_y[i] = pref_y;
		pref_x = pref_2x;
		pref_y = pref_2y;
	}
	switch (trafic)
	{
	case LEFT:
		x--;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;


	}
	if (x >= weight || x < 0 || y >= hight || y < 0)
	{
		game_status_end = true;
	}
	for (int i = 0; i < tails_apple; i++)
	{
		if (tale_x[i] == x && tale_y[i] == y)
		{
			game_status_end = true;
		}
	}
	if (x == apple_x && y == apple_y)
	{
		score++;
		control_score_for_print = 1;
		apple_x = rand() % weight;
		apple_y = rand() % hight;
		tails_apple++;
	}
	while (apple_x >= weight || apple_y >= hight)
	{
		apple_x = rand() % (weight - 2);
		apple_y = rand() % (hight - 3);
	}
}
int main()
{
	ofstream core_file;
	ofstream core_file_number;
	ifstream core_file_number_vallue;
	core_file_number.open("core_number.txt", ofstream::app);
	core_file.open("core.txt", ofstream::app);
	core_file_number_vallue.open("core_number.txt");
	date* base = new date[10000];
	int solution = 6;
	string  g;
	int schetchik = 0;
	int number = 0;
	while (!core_file_number_vallue.eof())
	{
		core_file_number_vallue >> g;
		schetchik++;
	}
	if (schetchik==0)
	{
		 number = 1;
	}
	else
	{
		 number =schetchik;
	}
	int number_2[4];
	cout << " Proverka" << number;

	while ((solution != 0) || (solution != 0))
	{
		cout << '\n';
		cout << "PIN_11_PRODUCTION INK PRESENT by MrGoblin" << endl;
		cout << "SNAKE v2.0 'No back home '" << endl;
		cout << "__---__---__" << endl;
		cout << "==_+_==_+_==" << endl;
		cout << "  \\ |  | /" << endl;
		cout << "   \\____/" << endl;
		cout << "Main Menu" << endl;
		cout << "Input '0' if you scared else tab  f for run out in game " << endl;
		cout << "Please input '1' for start gamesssss....." << endl;
		cout << "Input '2' for watch Lider Bord" << endl;

		cin >> solution;

		switch (solution)
		{
		case 0:
		{
			solution = 0;
			game_status_end = true;
			break;
		}
		case 1:
		{

			game_status_end = false;
			system("cls");
			begin();
			while (!game_status_end)
			{
				Draw();
				input();
				core();
			}
			cout << "Please input your Name and Surname" << " ";
			string name, surname;
			cin >> name >> surname;
			base[number].namesurname = name + " " + surname;
			base[number].score_2 = score;
			score = 0;
			name = " ";
			surname = " ";
			core_file << base[number].namesurname << " " << base[number].score_2 << endl;
			core_file_number << number<<endl;
			number++;
			system("cls");
			x = weight / 2 - 1;
			y = hight / 2 - 1;
			solution = 5;
			tails_apple = 0;
			break;
		}
		case 2:
		{
				if (number > 0)
				{
					string copy_name;
					int copy_score;
					if (number >= 2)
					{
						for (int i = 0; i < number; i++)
						{
							for (int j = i; j < number; j++)
							{
								if (base[i].score_2 < base[j].score_2)
								{
									copy_name = base[i].namesurname;
									copy_score = base[i].score_2;
									base[i].score_2 = base[j].score_2;
									base[i].namesurname = base[j].namesurname;
									base[j].score_2 = copy_score;
									base[j].namesurname = copy_name;
									copy_score = 0;
									copy_name = " ";
								}
							}
						}
					}

					if (number > 10)
					{

						cout << "_______TOP____10___Player" << endl;
						for (int i = 0; i < 10; i++)
						{
							cout << i << " " << base[i].namesurname << " " << "Score" << " " << base[i].score_2 << endl;
						}
					}
					else
					{
						cout << "_______TOP____" << number << "___Player" << endl;
						for (int i = 0; i < number; i++)
						{
							cout << i << " " << base[i].namesurname << " " << "Score" << " " << base[i].score_2 << endl;
						}
					}


				}


				system("pause");
				system("cls");
				break;

			



		}

		case 5:
		{
			game_status_end = false;
			cout << '\n';
			cout << "PIN_11_PRODUCTION INK PRESENT by MrGoblin" << endl;
			cout << "SNAKE v2.0 'No back home '" << endl;
			cout << "__---__---__" << endl;
			cout << "==_+_==_+_==" << endl;
			cout << "  \\ |  | /" << endl;
			cout << "   \\____/" << endl;
			cout << "Main Menu" << endl;
			cout << "Input '0' if you scared else tab  f for run out in game " << endl;
			cout << "Please input '1' for start gamesssss....." << endl;
			cout << "Input '2' for watch Lider Bord" << endl;
			cout << "Input '3' if you want start game and  record your progresssssss...." << endl;
			cin >> solution;
			break;
		}

		}
		srand(time(0));
	}
	core_file.close();
	core_file_number.close();
	core_file_number_vallue.close();
}