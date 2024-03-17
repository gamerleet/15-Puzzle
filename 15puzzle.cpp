#include <iostream>
#include <array>

using namespace std;

int main()
{
	srand(time(NULL));

	array<int, 16> arr{ 0 };

	short EmptyTileIndex = rand() % 16;

	arr[EmptyTileIndex] = 0;

	auto display{ [&]() -> void {
		cout << arr[0] << "  " << arr[1] << "  " << arr[2] << "  " << arr[3] << '\n';
		cout << arr[4] << "  " << arr[5] << "  " << arr[6] << "  " << arr[7] << '\n';
		cout << arr[8] << "  " << arr[9] << "  " << arr[10] << "  " << arr[11] << '\n';
		cout << arr[12] << "  " << arr[13] << "  " << arr[14] << "  " << arr[15] << '\n';
	} };



	for (auto i = 0; i < arr.size(); i++) {

		if (i == EmptyTileIndex)
			continue;

		int k = 0;

		while (find(arr.begin(), arr.end(), k) != arr.end())
			k = rand() % 16;

		arr[i] = k;

	}

	bool gameover = false, victory = false;
	char input = 0;
	int newIndex = 0, checkedCases = 0, moves = 0;
	int OtherValAtOtherIndexLolCoolName = 0;

	while (!gameover) {

		cin.clear();
		cin.ignore(300, '\n');
		system("cls");
		cout << "MOVES: " << moves << "\n\n\n";
		display();

		for (auto i = 0; i < 14; i++) {
			if (arr[i + 1] != arr[i] + 1) {
				checkedCases = 0;
				break;
			}
			else {
				checkedCases++;
			}
		}

		if (checkedCases == 14) {
			victory = true;
			gameover = true;
			break;
		}

		

		cout << "\n\nw(up), a(left), s(down), d(right), q(quit): ";
	inp:
		cin >> input;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(300, '\n');
			goto inp;
		}


		switch (input) {

		case 'w':
			(EmptyTileIndex - 4 >= 0) ? newIndex = (EmptyTileIndex - 4), moves++ : newIndex = EmptyTileIndex;
			OtherValAtOtherIndexLolCoolName = arr[newIndex];
			arr[EmptyTileIndex] = OtherValAtOtherIndexLolCoolName;
			EmptyTileIndex = newIndex;
			arr[EmptyTileIndex] = 0;
			break;

		case 'a':
			if (!(EmptyTileIndex - 1 == 3 || EmptyTileIndex - 1 == 7 || EmptyTileIndex - 1 == 11 || EmptyTileIndex - 1 < 0)) {
				newIndex = EmptyTileIndex - 1;
				moves++;
			}
			else {
				newIndex = EmptyTileIndex;
			}

			OtherValAtOtherIndexLolCoolName = arr[newIndex];
			arr[EmptyTileIndex] = OtherValAtOtherIndexLolCoolName;
			EmptyTileIndex = newIndex;
			arr[EmptyTileIndex] = 0;
			break;

		case 'd':
			if (!(EmptyTileIndex + 1 == 4 || EmptyTileIndex + 1 == 8 || EmptyTileIndex + 1 == 12 || EmptyTileIndex + 1 > 15)) {
				newIndex = EmptyTileIndex + 1;
				moves++;
			}
			else {
				newIndex = EmptyTileIndex;
			}

			OtherValAtOtherIndexLolCoolName = arr[newIndex];
			arr[EmptyTileIndex] = OtherValAtOtherIndexLolCoolName;
			EmptyTileIndex = newIndex;
			arr[EmptyTileIndex] = 0;
			break;

		case 's':
			if (EmptyTileIndex + 4 > 15) {
				newIndex = EmptyTileIndex;
			}
			else {
				newIndex = EmptyTileIndex + 4;
				moves++;
			}

			OtherValAtOtherIndexLolCoolName = arr[newIndex];
			arr[EmptyTileIndex] = OtherValAtOtherIndexLolCoolName;
			EmptyTileIndex = newIndex;
			arr[EmptyTileIndex] = 0;
			break;

		case 'q':
			gameover = true;
			break;


		default:
			cin.clear();
			cin.ignore(300, '\n');
			goto inp;

		}

	}

	(victory) ? cout << "\n\nYOU WON THE GAME!\n\n" : cout << "\n\nYOU LOST THE GAME!\n\n";

	system("pause");
	return 0;
}
