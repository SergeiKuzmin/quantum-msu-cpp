#include "list.h"
#include <iostream>
#include <utility>

int main()
{
	List l0;
	l0.push_back(1);
	l0.push_back(2);
	l0.push_back(3);
	List lcopy(l0); // Копирование списка
	List l(std::move(lcopy)); // Явное перемещение
	std::cout << "List size = " << l.size() << std::endl;
	std::cout << l << std::endl; // Выводим весь список
	/* Выражение выше эквивалентно:
	 * std::operator<<(std::cout, l); // Вызвали оператор как обычную функцию
	 * std::cout << std::endl;
	 */
	auto iter = l.begin(); // Итератор указывает на начало списка
	if(*iter != 1)
		std::cout << "Test failed: the first element must be equal to 1" << std::endl;
	++iter; // Теперь итератор указывает на второй элемент
	*iter = 55.5; // Изменям второй элемент
	std::cout << l << std::endl; // Выводим изменённый список
	/* Перед выходом из функции будет автоматически вызван деструктор
	 * переменной "l", как будто здесь стоит строка
	 * l.~List();
	 */
	return 0;
}
