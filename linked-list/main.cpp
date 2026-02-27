#include <iostream>

template<typename T>
struct Node {
	T value{};
	Node<T>* next{nullptr};

	Node(T _value) : value(_value) {}
};

// [TODO] Handle out-of-index safely.
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
		Node<T>* new_element = new Node<T>(_value);

		if (start == nullptr) {
			start = new_element;
			end = start;
			return;
		}

		end->next = new_element;
		end = new_element;
	}

	void insert(T _value, size_t index)
	{
		Node<T>* new_element = new Node<T>(_value);

		if (start == nullptr) {
			start = new_element;
			end = start;
			return;
		}

		Node<T>* node_to_replace = this->get_node(index);
		new_element->next = node_to_replace;
		if (node_to_replace != start) {
			this->get_node(index - 1)->next = new_element;
		} else {
			start = new_element;
		}
	}

	T remove(size_t index)
	{
		Node<T>* node_to_remove = this->get_node(index);
		T result = node_to_remove->value;
		Node<T>* next_node = node_to_remove->next;
		if (index != 0) {
			this->get_node(index - 1)->next = next_node;
		} else {
			start = next_node;
		}
		delete node_to_remove;
		return result;
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

	[[nodiscard]] Node<T>* get_node(size_t index)
	{
		Node<T>* target_node = start;
		for (size_t i = 0; i < index; i++) {
			target_node = target_node->next;
		}
		return target_node;
	}
};

template<typename T>
void print_list(LinkedList<T>& list)
{
	for (int i = 0; i < list.length(); i++) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	LinkedList<int> list{5, 2, 7};
	list.append(23);
	list.insert(18, 1);
	list.insert(19, 0);
	print_list(list);
	list.remove(3);
	print_list(list);
	list.remove(0);
	print_list(list);
}
