#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
void progresive_map();
void progresive_Sleep();
int savad1, savad2;
int m = 20, m1 = 20, head1 = m / 2, head2 = m1 / 2;
bool game_over = true;
enum directions {STOP,LEFT,RIGHT,UP,DOWN};
directions hold;
int fruiti = rand() %(m-1);
int fruitj = rand() %(m1-1);
char head_form;
char fruit_form = '*';
char tale_form = 'o';
int for_talex[50];
int for_taley[50];
int score = 0, hold_score = 1, hight_score=1010;
bool primul_fruct_mancat = false;
int eaten_fruits = 0;

 void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			hold = LEFT;
			break;
		case 'd':
			hold = RIGHT;
			break;
		case 'w':
			hold = UP;
			break;
		case 's':
			hold = DOWN;
			break;
		case'q':
			system("pause");
			break;
		}
	}
	
}
 
void logic() {
	switch (hold)
	{
	case LEFT:
		head2--;
		break;
	case RIGHT:
		head2++;
		break;
	case DOWN:
		head1++;
		break;
	case UP:
		head1--;
		break;
	}
}

void draw() {
	system("cls");
	for (int i = 0;i < m + 2;i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 0;i < m - 1;i++) {
		for (int j = 0;j < m1;j++) {
			if (j == 0)
				cout << "#";
			//head printed//
			if ((i == head1) && (j == head2)) {
				cout << head_form;
				
			}
			//fruit printed//
			else if ((i == fruiti) && (j == fruitj))
				cout << fruit_form;
			else if ((for_talex[0]==i)&&(for_taley[0] == i))
			{
				for (int k = 0; k < eaten_fruits; k++) {
					if ((i == for_talex[k]) && (j == for_taley[k])) {
						cout << tale_form;
					}

				}
			}
			else
				cout << " ";

			if ((head1 == fruiti) && (head2 == fruitj)) {
				//if (head1 == (m - 2))
			//{
				//	head1 = m - 3;
			//	}
				//else {
				primul_fruct_mancat = true;
				eaten_fruits++;

					fruiti = rand() % (m - 1);
					fruitj = rand() % (m1 - 1);
				//}
				progresive_map();
				score =score+10;
			}
	
			//When you lose//
			if ((head1 == -1) || (head1 == m-1) || (head2 == -1) || (head2 == m1)){
				game_over = false;
			}
			if (j == m1 - 1) {
				cout << "#" << endl;
			}

		}//For End
		
	}//For End
	for (int i = 0;i < m + 2;i++) {
		cout << "#";
	}
	//savad1 = head1;
	//savad2 = head2;
	cout << "\n               SCORE: "<< score << endl;
	cout << endl;
}//function draw End

void progresive_Sleep() {
	if (score < 100)
		Sleep(150);
	else if ((score >= 100) && (score < 200))
		Sleep(130);
	else if ((score >= 200) && (score < 300))
		Sleep(110);
	else if ((score >= 300) && (score < 400))
		Sleep(90);
	else if ((score >= 400) && (score < 500))
		Sleep(80);
	else if ((score >= 500) && (score < 600))
		Sleep(70);
	else if ((score >= 600) && (score < 700))
		Sleep(60);
	else if ((score >= 700) && (score < 800))
		Sleep(50);
	else
		Sleep(40);
}

void progresive_map() {
	
	if (((score == 40) || (score == hold_score))&&(score<=1040))
	{
		hold_score = score + 100;
		
		if (head1 == (m - 2))
			{
					head1 = m - 3;
				}
		m--;m1--;
	}
}


void tale() {
	//for_tale[0] = head_form;




}

int main() {
	cout << "For pausing the game press 'q'\nPress any key to start the game:";
	_getch();
	hold = STOP;
	cout << "\nPlease enter your name: ";
	cin >> head_form;
	while (game_over != false) {
		for_talex[0] = head1;
		for_taley[0] = head2;
		if (primul_fruct_mancat==true) {
			for (int n = 1; n < eaten_fruits; n++) {
				for_talex[n] = for_talex[n - 1];
				for_taley[n] = for_taley[n - 1];
			}
		}
			input();
			logic();
			//aici se schimba valoarea lui head1 si head2 cand este rulata functia logic
			draw();
			progresive_Sleep();
	}

	if (game_over == false) 
		cout << "     GAME OVER!\n  " << head_form << ": Your final score is: " << score << " POINTS" << endl << endl;

		system("pause");
		_getch();
	
}




