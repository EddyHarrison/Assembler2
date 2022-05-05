#include<iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	int x, y, tmp = 0, result = 0, key = 0;
	int a[3];
	int b[3][3];
	bool infinity = true;
	// Флаг для ввода символов
	bool symb = true;

	while (infinity) {


		cout << "Массив A:\n";
		for (int i = 0; i < 3; i++) {
			cout << "A[" << i << "] = ";
			// Обработка ввода символов
			symb = true;
			while (symb == true) {
				cin >> a[i];
				if (cin) {
					symb = false;
				}
				else {
					cout << "ВЫ ВВЕЛИ НЕ ЧИСЛО! \n Введите значение заново:\t" << endl;
					cout << "A[" << i << "] = ";
					cin.clear();
					cin.ignore();
				}
				// Условие завершения программы
				if (a[i] == -228) {
					return 0;
				}
			}

		}

		cout << "\nМассив B: \n";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {

				cout << "B[" << i << "] [" << j << "] = ";
				// Обработка ввода буквы
				symb = true;
				while (symb == true) {
					cin >> b[i][j];
					if (cin) {
						symb = false;
					}
					else {
						cout << "ВЫ ВВЕЛИ НЕ ЧИСЛО! \n Введите значение заново:\t" << endl;
						cout << "B[" << i << "] [" << j << "] = ";
						cin.clear();
						cin.ignore();
					}
					// Условие завершения программы
					if (b[i][j] == -228) {
						return 0;
					}
				}

			}
		}


		cout << "\nX: ";
		// Обработка ввода буквы
		symb = true;
		while (symb == true) {
			cin >> x;
			if (cin) {
				symb = false;
			}
			else {
				cout << "ВЫ ВВЕЛИ НЕ ЧИСЛО! \n Введите значение заново:\t" << endl;
				cout << "X = ";
				cin.clear();
				cin.ignore();
			}
			// Условие завершения программы
			if (x == -228) {
				return 0;
			}
		}

		cout << "\nY: ";
		// Обработка ввода буквы
		symb = true;
		while (symb == true) {
			cin >> y;
			if (cin) {
				symb = false;
			}
			else {
				cout << "ВЫ ВВЕЛИ НЕ ЧИСЛО! \n Введите значение заново:\t" << endl;
				cout << "Y = ";
				cin.clear();
				cin.ignore();
			}
			// Условие завершения программы
			if (y == -228) {
				return 0;
			}
		}

		_asm {
			mov ecx, 3 //инициализация регистра значением 3
			xor eax, eax //обнуление регистра
			xor ebx, ebx //обнуление регистра
			xor edx, edx //обнуление регистра
			xor esi, esi //обнуление регистра

			m1 : //метка
			mov eax, a[ebx] //инициализация регистра элементами массива (0-2)
				add ebx, 4 //добавляем к значению регистра значние 4
				add esi, eax //суммируем значения регистров и присваиваем регистру edx
				jo mOverFlow //переход к метке
				loop m1 //переход к метке
				imul esi, x //операция умножение 
				mov tmp, esi //загружаем в переменную значение регистра
				xor eax, eax //обнуление регистра
				xor ebx, ebx //обнуление регистра
				mov ecx, 6 //инициализация регистра значением 3
			
				m2: //метка
			add eax, b[ebx] //инициализация регистра элементами массива (0-2)
				add ebx, 4 //добавляем к значению регистра значние 4
				//add eax, edx  
				jo mOverFlow //переход к метке
				loop m2 //переход к метке 
				imul eax, y //операция умножение 
				add eax, tmp //сложение значения регистра и переменной
				jo mOverFlow //переход к метке
				mov result, eax //присвоение переменной значения регистра eax
				jmp mEND //переход к метке
				mOverFlow : //метка
			mov key, 1 //переполнение
				mEND : //метка
		}

		if (!key) {
			result = abs(result);
			cout << "Результат: " << result << endl;
		}
		else
			cout << "Overflow" << endl;
	}

}