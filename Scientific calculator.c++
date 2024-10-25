#include<bits/stdc++.h>
using namespace std;

class Calculator {
public:
    void showMenu();
    void arithmeticOperations();
    void matrixOperations();
    void calculateSin();
    void calculateCos();
    void calculateTan();
    void calculatePow();
    void calculateSqrt();
    void calculateExp();
};

void Calculator::showMenu() {
    int option;
    do {
        cout << "\n\nMenu:-(Press 0 for exit)\n";
        cout << " 1-arithmetic operation\n 2-matrix calculations\n 3-Sin(x)\n 4-Cos(x)\n 5-Tan(x)\n 6-X^Y(power)\n 7-Square Root\n 8-Exponential(e^x)\n select any one option = ";
        cin >> option;
        switch (option) {
            case 0: exit(0); break;
            case 1: arithmeticOperations(); break;
            case 2: matrixOperations(); break;
            case 3: calculateSin(); break;
            case 4: calculateCos(); break;
            case 5: calculateTan(); break;
            case 6: calculatePow(); break;
            case 7: calculateSqrt(); break;
            case 8: calculateExp(); break;
            default: cout << "\n\tInvalid Choice !!!!\n";
        }
    } while (true);
}

void Calculator::arithmeticOperations() {
    vector<int> numbers;
    int num, operation;
    cout << "\nType: 1-for addition\n\t2-for subtraction\n\t3-for multiplication\n\t4-for division\n\n\t";
    cin >> operation;

    cout << "\nEnter the quantity of numbers: ";
    cin >> num;
    numbers.resize(num);
    
    for (int i = 0; i < num; i++) {
        cout << "\nEnter the number " << char('A' + i) << ": ";
        cin >> numbers[i];
    }

    switch (operation) {
        case 1: {
            int sum = 0;
            for (int n : numbers) {
                sum += n;
            }
            cout << "\n\n==========================> Result=" << sum << endl;
            break;
        }
        case 2: {
            int result = numbers[0];
            for (int i = 1; i < num; i++) {
                result -= numbers[i];
            }
            cout << "\n==========================> Result=" << result << endl;
            break;
        }
        case 3: {
            int result = numbers[0];
            for (int i = 1; i < num; i++) {
                result *= numbers[i];
            }
            cout << "\n==========================> Result=" << result << endl;
            break;
        }
        case 4: {
            float result = static_cast<float>(numbers[0]);
            for (int i = 1; i < num; i++) {
                result /= numbers[i];
            }
            cout << "\n==========================> Result=" << result << endl;
            break;
        }
    }
}

void Calculator::matrixOperations() {
    int r1, c1, r2, c2, operation;
    cout << "\nWhat type of calculation do you want to do?\nType:\n";
    cout << "1-for matrix addition \n2-for matrix subtraction \n3-for matrix multiplication\n";
    cin >> operation;

    cout << "\nEnter the No of rows in Matrix A: "; cin >> r1;
    cout << "\nEnter the No of columns in Matrix A: "; cin >> c1;
    cout << "\nEnter the No of rows in Matrix B: "; cin >> r2;
    cout << "\nEnter the No of columns in Matrix B: "; cin >> c2;

    if (((operation == 1 || operation == 2) && (r1 != r2 || c1 != c2)) || (operation == 3 && c1 != r2)) {
        cout << "\n\n============================================> Not possible" << endl;
        return;
    }

    vector<vector<int>> A(r1, vector<int>(c1));
    vector<vector<int>> B(r2, vector<int>(c2));
    vector<vector<int>> C(r1, vector<int>(c2, 0));

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "Enter A[" << i << "][" << j << "] Element: ";
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "Enter B[" << i << "][" << j << "] Element: ";
            cin >> B[i][j];
        }
    }

    switch (operation) {
        case 1: {
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
            break;
        }
        case 3: {
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                    for (int k = 0; k < c1; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            break;
        }
    }

    cout << "\n\nMatrix C:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void Calculator::calculateSin() {
    double x, result;
    cout << "\nEnter the value of x in degrees: ";
    cin >> x;
    x = x * M_PI / 180;
    result = sin(x);
    cout << "\n\nsin(" << x << ") = " << result << endl;
}

void Calculator::calculateCos() {
    double x, result;
    cout << "\nEnter the value of x in degrees: ";
    cin >> x;
    x = x * M_PI / 180;
    result = cos(x);
    cout << "\n\ncos(" << x << ") = " << result << endl;
}

void Calculator::calculateTan() {
    double x, result;
    cout << "\nEnter the value of x in degrees: ";
    cin >> x;
    x = x * M_PI / 180;
    result = tan(x);
    cout << "\n\ntan(" << x << ") = " << result << endl;
}

void Calculator::calculatePow() {
    double x, y, result;
    cout << "\nEnter the base: ";
    cin >> x;
    cout << "\nEnter the exponent: ";
    cin >> y;
    result = pow(x, y);
    cout << "\n\n" << x << " raised to the power of " << y << " = " << result << endl;
}

void Calculator::calculateSqrt() {
    double x, result;
    cout << "\nEnter the number: ";
    cin >> x;
    result = sqrt(x);
    cout << "\n\nSquare root of " << x << " = " << result << endl;
}

void Calculator::calculateExp() {
    double x, result;
    cout << "\nEnter the number: ";
    cin >> x;
    result = exp(x);
    cout << "\n\nExponential of " << x << " = " << result << endl;
}

int main() {
    Calculator calculator;
    calculator.showMenu();
    return 0;
}