#ifndef LIST
#define LIST

#include <ostream>

class List
{
private:
	// Узел списка
	struct Node
	{
		double value = 0.0; // Значение узла
		Node *prev = nullptr; // Указатель на предыдущий узел
		Node *next = nullptr; // Указатель на следующий узел
	};

public:
	/* Итератор двусвязного списка.
	 * В данном случае итератор представляет собой класс-обёртку над указателем
	 * на узел, но для других структур данных это может быть иначе.
	 */
	struct Iterator
	{
		Iterator(): n(nullptr) {} // Конструктор по умолчанию
		Iterator(Node *node): n(node) {} // Конструктор для удобства
		Iterator& operator++() { n = n->next; return *this; } // Инкремент итератора
		Iterator& operator--() { n = n->prev; return *this; } // Декремент итератора
		double& operator*() { return n->value; } // Оператор разыменования итератора
		const double& operator*() const { return n->value; } // То же, но константный
		bool operator==(const Iterator &other) const { return n == other.n; } // Сравнение итераторов
		bool operator!=(const Iterator &other) const { return n != other.n; }

		Node *n; // Указатель на узел, куда ссылается итератор
	};

	/* Итератор на первый элемент.
	 * Итератор может коструироваться из объектов типа Node* (см. конструкторы
	 * выше), поэтому компилятор автоматически подставит вызов конструктора.
	 * То есть запись "return first;" эквивалентна "return Iterator(first);"
	 */
	Iterator begin() { return first; }

	/* Итератор на элемент, следующий за последним.
	 * Этот элемент не является валидным, поэтому nullptr здесь уместен.
	 */
	Iterator end() { return nullptr; }

	/* Варианты методов для константного экземпляра класса.
	 * Более правильная реализация должна вводить новый тип СonstIterator,
	 * как это сделано, например, в стандартной библиотеке C++, и возвращать
	 * его здесь. По смыслу СonstIterator должен быть аналогичен указателю
	 * на константу, то есть, например, изменение значения через СonstIterator
	 * должно быть невозможным.
	 * Однако для простоты, здесь тоже возвращается Iterator.
	 */
	Iterator begin() const { return first; }
	Iterator end() const { return nullptr; }

	size_t size() const { return cached_size; } // Число элементов в списке

	List() = default; // Попросить компилятор создать конструктор по умолчанию,
	                  // т.к. компилятор согласно стандарту C++ удаляет неявно
					  // созданный конструктор, потому что ниже объявлены
					  // явные копирующий и перемещающий конструкторы
	List(const List &other); // Копирующий конструктор
	List(List &&other); // Перемещающий конструктор
	~List() { clear(); } // Деструктор
	void push_before(Iterator it, double value);
	void push_after(Iterator it, double value);
	void pop(Iterator it);
	void push_back(double value);
	void push_front(double value);
	void pop_back();
	void pop_front();
	void clear();

private:
	Node *first = nullptr;
	Node *last = nullptr;
	size_t cached_size = 0;
};

namespace std
{
	// Вывести все элементы списка в поток (вместо функции print)
	ostream& operator<<(ostream &stream, const List &l);
}

#endif
