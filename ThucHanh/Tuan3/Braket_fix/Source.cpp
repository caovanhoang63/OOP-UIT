#include<iostream>
#include<stack>
#include<vector>
#include <complex>
using namespace std;

typedef std::complex<double> complexd;
class Matrix {
public:
	int type;
	complexd matrix[10][10];
	int row, col;
	Matrix() {
		type = 0;
		row = col = 1;
	}
	void Enter();
	Matrix Trans();
	Matrix to_bra();
	Matrix Scalar_x_Matrix(Matrix);
	Matrix Matrix_x_Scalar(Matrix);
	Matrix Matrix_x_Matrix(Matrix);
	Matrix Ket_x_Bra(Matrix);
	Matrix Ket_x_Ket(Matrix);
	Matrix Bra_x_Bra(Matrix);
	void Print() {
		if (col == 1 && row > 1)
			*this = to_bra();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout<<matrix[i][j].real()<<" "<<matrix[i][j].imag()<<" ";
			cout << endl;
		}
	}
};

class Calculator {
public:
	string expression;
	Matrix* list;
	Matrix result;
	Matrix calculator();
	void Enter() {
		int n;
		cin >> n;
		list = new Matrix[n];
		for (int i = 0; i < n; i++) {
			list[i].Enter();
		}
		cin.ignore();
		cin >> expression;
	}
	void Process() {
		result = calculator();
	}
	void Print() {
		result.Print();
	}
	~Calculator() {
		delete[] list;
	}
};

int main() {
	Calculator a;
	a.Enter();
	a.Process();
	a.Print();
	return 0;
}
void Matrix::Enter() {
	cin >> type;
	if (type == 1) {
		row = col = 1;
		double real, imag;
		cin >> real >> imag;
		complexd x(real, imag);
		matrix[0][0] = x;
	}
	if (type == 2) {
		cin >> col;
		row = 1;
		for (int i = 0; i < col; i++)
		{
			double real, imag;
			cin >> real >> imag;
			complexd x(real, imag);
			matrix[0][i] = x ;
		}
	}
	if (type == 3) {
		cin >> col;
		row = col;
		for (int i = 0; i < col; i++)
			for (int j = 0; j < col; j++)
			{
				double real, imag;
				cin >> real >> imag;
				complexd x(real, imag);
				matrix[i][j] = x;
			}
	}
}
Matrix Matrix::to_bra() {
	Matrix temp;
	temp.row = 1;
	temp.col = row;
	for (int i = 0; i < row; i++) {
		temp.matrix[0][i] = matrix[i][0];
		temp.matrix[0][i] = conj(matrix[i][0]);
	}
	return temp;
}
Matrix Matrix::Trans() {
	Matrix temp;
	temp.col = 1;
	temp.row = col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			temp.matrix[j][i] = matrix[i][j];
			temp.matrix[j][i] = conj(temp.matrix[j][i]);
		}
	return temp;
}
Matrix Matrix::Scalar_x_Matrix(Matrix s) {
	Matrix temp;
	temp.row = s.row;
	temp.col = s.col;
	for (int i = 0; i < s.row; i++)
		for (int j = 0; j < s.col; j++)
			temp.matrix[i][j] = matrix[0][0] * s.matrix[i][j];
	return temp;
}
Matrix Matrix::Matrix_x_Scalar(Matrix s) {
	Matrix temp;
	temp.row = row;
	temp.col = col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.matrix[i][j] = matrix[i][j] * s.matrix[0][0];
	return temp;
}
Matrix Matrix::Matrix_x_Matrix(Matrix s) {
	Matrix temp;
	temp.row = row;
	temp.col = s.col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < s.col; j++)
		{
			complexd sum = 0;
			for (int z = 0; z < col; z++)
			{
				sum += this->matrix[i][z] * s.matrix[z][j];
			}
			temp.matrix[i][j] = sum;
		}
	}
	return temp;
}
Matrix Matrix::Ket_x_Bra(Matrix s) {
	Matrix temp;
	temp.row = row;
	temp.col = s.col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < s.col; j++)
			temp.matrix[i][j] = matrix[i][0] * s.matrix[0][j];
	return temp;
}
Matrix Matrix::Ket_x_Ket(Matrix s) {
	Matrix temp;
	temp.row = row * s.row;
	temp.col = 1;
	int t = 0;
	for (int z = 0; z < row; z++)
		for (int i = 0; i < s.row; i++)
			temp.matrix[t++][0] = matrix[z][0] * s.matrix[i][0];
	return temp;
}
Matrix Matrix::Bra_x_Bra(Matrix s) {
	Matrix temp;
	temp.row = 1;
	temp.col = col * s.col;
	int t = 0;
	for (int z = 0; z < col; z++)
		for (int i = 0; i < s.col; i++)
			temp.matrix[0][t++] = matrix[0][z] * s.matrix[0][i];
	return temp;
}
Matrix Calculator::calculator() {
	vector<Matrix> List;
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '|' && expression[i + 2] == '>') {
			List.push_back(list[expression[i + 1] - 'a'].Trans());
			i = i + 2;
		}
		else if (i > 0 && expression[i - 1] == '|' && expression[i + 1] == '>') {
			List.push_back(list[expression[i] - 'a'].Trans());
			i = i + 1;
		}
		else if (expression[i] == '<') {
			List.push_back(list[expression[i + 1] - 'a']);
			i = i + 2;
		}
		else if (expression[i] == '|' && expression[i + 2] == '|') {
			List.push_back(list[expression[i + 1] - 'a']);
			i = i + 2;
		}
		else if (i > 0 && expression[i - 1] == '|' && expression[i + 1] == '|') {
			List.push_back(list[expression[i] - 'a']);
			i = i + 1;
		}
		else
			List.push_back(list[expression[i] - 'a']);
	}
	Matrix Result = List[0];
	for (int i = 1; i < List.size(); i++) {
		if (Result.row == 1 && Result.col == 1) {
			Result = Result.Scalar_x_Matrix(List[i]);
		}
		else if (List[i].row == 1 && List[i].col == 1) {
			Result = Result.Matrix_x_Scalar(List[i]);
		}
		else if (Result.row > 1 && Result.col == 1 && List[i].row > 1 && List[i].col == 1) {
			Result = Result.Ket_x_Ket(List[i]);
		}
		else if (Result.col == List[i].row && Result.col > 1) {
			Result = Result.Matrix_x_Matrix(List[i]);
		}
		else if (Result.row > 1 && Result.col == 1 && List[i].row == 1 && List[i].col > 1) {
			Result = Result.Ket_x_Bra(List[i]);
		}
		else if (Result.row == 1 && Result.col > 1 && List[i].row == 1 && List[i].col > 1) {
			Result = Result.Bra_x_Bra(List[i]);
		}
	}
	return Result;
}