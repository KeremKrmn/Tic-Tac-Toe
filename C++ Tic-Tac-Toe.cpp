#include <iostream>

using namespace std;

char matrix[3][3] = { {'1', '2', '3'}, {'4','5','6'}, {'7','8','9'} };


bool Draw=false;

char XorO;

int Row, Column;
int inputNumber;


void MainBoard() 
{
	system("cls");

	cout << endl;
	cout << "    |     |    " << endl;
	cout << " " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << endl;
	cout << "___ | ___ | ___" << endl;
	cout << "    |     |    " << endl;
	cout << " " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << endl;
	cout << "___ | ___ | ___" << endl;
	cout << "    |     |    " << endl;
	cout << " " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << endl;
	cout << "    |     |    " << endl;

	
}


void OXplacement() {

start:

	cout << "Enter a number from 1-9" << endl;
	
	while (true) //Show this message when user enters string
	{
		cin >> inputNumber;

		if (!cin)
		{
			cout << "Wrong value. Please try again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else { 
			break; 
		}
	}


	switch (inputNumber) {

	case 1:
		Row = 0;
		Column = 0;
		break;

	case 2:
		Row = 0;
		Column = 1;
		break;

	case 3:
		Row = 0;
		Column = 2;
		break;

	case 4:
		Row = 1;
		Column = 0;
		break;

	case 5:
		Row = 1;
		Column = 1;
		break;

	case 6:
		Row = 1;
		Column = 2;
		break;

	case 7:
		Row = 2;
		Column = 0;
		break;

	case 8:
		Row = 2;
		Column = 1;
		break;

	case 9:
		Row = 2;
		Column = 2;
		break;

	default:
		cout << "The number you entered is not between 1-9" << endl;
		goto start; //line 37
		break;		

	}

	if (XorO == 'X' && matrix[Row][Column] != 'X' && matrix[Row][Column] != 'O') {

		matrix[Row][Column] = 'X';
		XorO = 'O';
		
	}

    else if (XorO == 'O' && matrix[Row][Column] != 'X' && matrix[Row][Column] != 'O') {
	
		matrix[Row][Column] = 'O';
		XorO = 'X';
		
    }
	
	else if ((XorO == 'X' || XorO == 'O') && (matrix[Row][Column] == 'X' || matrix[Row][Column] == 'O')) {
		cout << "!!There is no room for your chosen location!! "<<endl;
		goto start; //line 37
	}
	
	
	MainBoard();

}
	

bool WhoistheWinner() {

	for (int i = 0; i < 3; i++) {
		if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] || matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
			return true;
		}
		
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] || matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {

		return true;
	}
	

	for (int k = 0; k < 3; k++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[k][j] != 'X' && matrix[k][j] != 'O')
				return false;
		}
	}

	Draw=true;
	return true;
}

int main() {

	XorO = 'X';
	
	while (WhoistheWinner()==false) {
		
		MainBoard();

		if (XorO=='X') {
			
			cout << XorO << "'s turn." << endl;
		}
		else if(XorO=='O') {
			cout << XorO << "'s turn." << endl;
		}

		OXplacement();
		WhoistheWinner();
	}

	

	if (XorO == 'O' && Draw == false) {
		cout << "\nWinner: X" << endl;
	}
	else if (XorO == 'X' && Draw == false) {
		cout << "\nWinner: O" << endl;
	}
	

	if(Draw==true){
			cout << "\nDraw" << endl;
	}
	
	
	return 0;
}