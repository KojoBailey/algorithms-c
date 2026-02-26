#include <iostream>

template<typename T>
struct Node {
	T value{};
	Node<T>* next{nullptr};
};

template<typename T>
class LinkedList {
public:
	LinkedList() = default;

	template<typename... Args>
	LinkedList(Args... values)
	{
		(append(values), ...);
	}

	void append(T _value)
	{
		Node<T>* new_element = new Node<T>();
		new_element->value = _value;

		if (start == nullptr) {
			start = new_element;
			end = start;
		} else {
			end->next = new_element;
			end = new_element;
		}
	}

	[[nodiscard]] T operator[](size_t index)
	{
		Node<T>* target_node = start;
		for (size_t i = 0; i < index; i++) {
			target_node = target_node->next;
		}
		return target_node->value;
	}

	[[nodiscard]] size_t length()
	{
		size_t result;
		Node<T>* current_node = start;
		for (result = 0; current_node != nullptr; result++) {
			current_node = current_node->next;
		}
		return result;
	}

private:
	Node<T>* start{nullptr};
	Node<T>* end{nullptr};
};

int main()
{
	LinkedList<int> list{5, 2, 7};
	list.append(23);
	
	for (int i = 0; i < list.length(); i++) {
		printf("%d ", list[i]);
	}
}
