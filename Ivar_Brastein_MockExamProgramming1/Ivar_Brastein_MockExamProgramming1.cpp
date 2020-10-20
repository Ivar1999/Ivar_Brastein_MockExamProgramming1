#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>

using namespace std;

//char loginboard[9] = {'1','2','3','4','5','6','7','8','9' };


void DrawBoard(char board[9], int attempts);
void DrawBoard(char board[9], int attempts) {
	cout << "Login using 'W A S D'\nYou have " << attempts << " attempts left\n";
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			cout << endl;
			cout << " -------------";
			cout << endl;
			cout << " | ";
		}
		cout << board[i] << " | ";
	}
	cout << "\n -------------" << endl;
}

int login();
int login() {

	int attempts = 3;

	do
	{
		//char board[9];
		char board[9] = { '1','2','3','4','5','6','7','8','9' };
		int code = 1;
		int codevalue = 0;
		board[0] = '*';
		int current = 0;
		system("cls");
		DrawBoard(board, attempts);
		do
		{
			//cout << code;
			int key = _getch();
			board[current] = '*';
			key = tolower(key);
			switch (key)
			{
			case 'w':
				current -= 3;
				code++;
				codevalue += 20;
				break;
			case 'a':
				current--;
				code++;
				break;
			case 's':
				current += 3;
				code++;
				codevalue += 15;
				break;
			case 'd':
				current++;
				code++;
				codevalue += 10;
			default:
				break;
			}
			board[current] = '*';
			system("cls");
			DrawBoard(board, attempts);

		} while (code < 5);
		if (board[3] == '*' && board[4] == '*' && board[1] == '*' && board[2] == '*') // if code is right adds +5, if code is wrong adds +1, you have 3 attempts.
		{
			attempts -= 5;
		}
		else
		{
			attempts--;
		}
	} while (attempts > 0);

	if (attempts < -1)
		return 1;
	else if (attempts == 0)
		return 0;
}

void task1();
void task1() {
	int throws = 0;
	srand(time(NULL));
	int dicenumber;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	cout << "Press any key to start the task" << endl;
	system("pause");
	do
	{
		dicenumber = rand() % 6 + 1;
		throws++;
		switch (dicenumber)
		{
		case 1:
			one++;
			break;
		case 2:
			two++;
			break;
		case 3:
			three++;
			break;
		case 4:
			four++;
			break;
		case 5:
			five++;
			break;
		case 6:
			six++;
			break;
		default:
			break;
		}
	} while (throws < 2000);
	system("cls");
	cout << "The dice has been thrown 2000 times.\nThe different numbers were hit this many times:\n" << endl;
	cout << "1: " << one << " times" << endl;
	cout << "2: " << two << " times" << endl;
	cout << "3: " << three << " times" << endl;
	cout << "4: " << four << " times" << endl;
	cout << "5: " << five << " times" << endl;
	cout << "6: " << six << " times" << endl;
	cout << "\nPress any key to get back to the menu" << endl;
	system("pause");
}

void task2(); // task 2 is incomplete, got stuck so went to the other tasks
void task2() {
	srand(time(NULL));
	const int randomnumber = rand() % 20 + 1;

	char array[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', };

	struct Task2
	{
		char name;
		int value;
	};
	vector <Task2> task_2;

	for (int i = 0; i < 10; i++)
	{
		Task2 task;
		task.name = array[i];
		task.value = randomnumber;
		task_2.push_back(task);
	}

	system("pause");
}

char grid[10][10] = { // grid for task 3
{'+','#','#','#','#','#','#','#','#','|'},
{'|','E',' ',' ',' ',' ',' ',' ',' ','|'},
{'|','#','#',' ','#','#','#','#','#','|'},
{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|',' ','|',' ','|','#','#','#','|','|'},
{'|',' ','|',' ','|',' ',' ',' ','|','|'},
{'|',' ','|',' ',' ',' ',' ',' ',' ','|'},
{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|',' ',' ','#','#','#','#','#','H','|'},
{'|','_','_','_','_','_','_','_','_','|'},
};

void boardtask3(); // board for task 3
void boardtask3() {
	system("cls");
	cout << "\nGet to the letter 'H'\n\nMove around by using 'W A S D' keys\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
void task3();
void task3() {


	int a = 1;
	int b = 1;
	grid[a][b] = 'E';
	boardtask3();
	do
	{

		int key = _getch();
		grid[a][b] = ' ';
		key = tolower(key);
		switch (key)
		{
		case 'a':if (grid[a][b - 1] == ' ' || grid[a][b - 1] == '+' || grid[a][b - 1] == '.')
		{
			b--;
		}
				break;
		case 'w':if (grid[a - 1][b] == ' ' || grid[a - 1][b] == '+' || grid[a - 1][b] == '.')
		{
			a--;
		}
				break;
		case 's':if (grid[a + 1][b] == ' ' || grid[a + 1][b] == '+' || grid[a + 1][b] == '.' || grid[a + 1][b] == 'H')
		{
			a++;
		}

				break;
		case 'd':if (grid[a][b + 1] == ' ' || grid[a][b + 1] == '+' || grid[a][b + 1] == '.')
		{
			b++;
		}
				break;
		default:
			break;
		}
		grid[a][b] = 'E';
		system("cls");
		boardtask3();
	} while (grid[a][b] != grid[8][8]);
	system("pause");
}

char grid1[10][10] = { // grid for task 4
{'+','#','#','#','#','#','#','#','#','|'},
{'|','E',' ',' ',' ','.','.','.','+','|'},
{'|','#','#',' ','#','#','#','#','#','|'},
{'|','+','.','.','.','.','.','.','.','|'},
{'|','.','|','.','|','#','#','#','|','|'},
{'|','.','|','.','|','.','.','+','|','|'},
{'|','.','|','.','.','.',' ',' ',' ','|'},
{'|','.',' ',' ',' ',' ',' ',' ',' ','|'},
{'|','+',' ','#','#','#','#','#','H','|'},
{'|','_','_','_','_','_','_','_','_','|'},
};

void boardtask4(); // board for task 4
void boardtask4() {
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << grid1[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\nMove around by using 'W A S D' keys\n" << endl;
	cout << "\nGet to the letter 'H'" << endl;
	cout << "Collect '+ and '.' to recieve extra points" << endl;
	cout << "Max number of points possible is '1690', (hint collect the '+' after all the '.' are gone)" << endl;

}

void task4();
void task4() {

	int a = 1;
	int b = 1;
	int points = 0;
	grid1[a][b] = 'E';
	boardtask4();
	do
	{

		int key = _getch();
		grid1[a][b] = ' ';
		key = tolower(key);
		switch (key)
		{
		case 'a':if (grid1[a][b - 1] == ' ')
		{
			b--;
		}
				else if (grid1[a][b - 1] == '.')
		{
			b--;
			points += 5;
		}
				else if (grid1[a][b - 1] == '+')
		{
			b--;
			points *= 2;
		}
				break;
		case 'w':if (grid1[a - 1][b] == ' ')
		{
			a--;
		}
				else if (grid1[a - 1][b] == '.')
		{
			a--;
			points += 5;
		}
				else if (grid1[a - 1][b] == '+')
		{
			a--;
			points *= 2;
		}
				break;
		case 's':if (grid1[a + 1][b] == ' ' || grid1[a + 1][b] == 'H')
		{
			a++;
		}
				else if (grid1[a + 1][b] == '.')
		{
			a++;
			points += 5;
		}
				else if (grid1[a + 1][b] == '+')
		{
			a++;
			points *= 2;
		}

				break;
		case 'd':if (grid1[a][b + 1] == ' ')
		{
			b++;
		}
				else if (grid1[a][b + 1] == '.')
		{
			b++;
			points += 5;
		}
				else if (grid1[a][b + 1] == '+')
		{
			b++;
			points *= 2;
		}
				break;
		default:
			break;
		}
		grid1[a][b] = 'E';
		system("cls");
		boardtask4();
		cout << "Total points: " << points;
	} while (grid1[a][b] != grid1[8][8]);
	points += 10;
	system("cls");
	cout << "You earn a total of '" << points << "' points. Good job!\n" << endl;
	cout << "Press any button to get back to the menu" << endl;
	system("pause");



}

int main()
{
	int test = 0;
	test = login();

	if (test == 1)
	{




		int option = 0;
		do
		{
			system("cls");
			cout << "1. Task 1\n" << endl;
			cout << "2. Task 2\n" << endl;
			cout << "3. Task 3\n" << endl;
			cout << "4. Task 4\n" << endl;
			cout << "5. Log out\n" << endl;
			cout << "Enter number from 1 to 5\n";
			cin >> option;
			switch (option)
			{
			case 1: task1();
				break;
			case 2: task2();
				break;
			case 3: task3();
				break;
			case 4: task4();
				break;
			default:
				break;
			}
		} while (option < 5);

	}
	system("cls");
	cout << "Program will now terminate." << endl;

	if (test == 0)
	{
		system("cls");
		cout << "0 attempts left, Program will now terminate." << endl;

	}


	return 0;
}