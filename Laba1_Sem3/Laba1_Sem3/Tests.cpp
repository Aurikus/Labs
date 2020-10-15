/* Тест на ввод данных с последующим выводом:
ID: 3754dff323
sumBank: 10000
sumMaxGet: 5000

Сработало верно. */ 


/* Тест на ввод заведомо неверных данных 
ID: 34fldfsl
sumBank: -100
sumMaxGet:0

Программа не принимает введенные значения, так как они не удовлетворяют условию 
*/


/* int sum, sumGet;
	char* n = new char[20];
	cout << " Input ID " << endl; 
	cin.getline(n, 20);
	while (1) 
	{
		cout << "Input sum of money " << endl;
		cin >> sum;
		if (sum > 0) break;
		else cout << "Input valid sum of money " << endl;
	}
	while (1)
	{
		cout << "Input max sum of Get" << endl;
		cin >> sumGet;
		if (sumGet > 0) break;
		else cout << "Input valid max sum of Get" << endl;
	}*/