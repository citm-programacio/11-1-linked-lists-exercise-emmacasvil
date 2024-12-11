// Linked_Lists.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

// Declaration of a doubly-linked list
class List {
private:
	// Internal struct for list nodes
	struct Node {
		int value;
		Node* next;
		Node* prev;

		Node(int val) : value(val), next(nullptr), prev(nullptr) {}
	};

	// List internals
	Node* first = nullptr;
	Node* last = nullptr;
	unsigned int num_elems = 0;

public:
	// Constructor and destructor
	List() : first(nullptr), last(nullptr), num_elems(0) {}
	~List();

	// Modifiers

	void push_back(const int& value)
	{
		Node* new_node = new Node(value); //We create a new node
		if (last) { //If the list is not empty
			last->next = new_node; //This pointer should point to the next position after the last. By setting the new node we're saying that the new one is the last now. 
			new_node->prev = last; //Pointer in the new node that points to the previous one (old last). It's used to link them in both directions. 
			last = new_node; //Update the last pointer to point the new last node. 
		}
		else {
			first = last = new_node; //If the list is empty
		}

		num_elems++;
	}

	void push_front(const int& value)
	{
		Node* new_node = new Node(value);
		if (first) //If the list is not empty
		{
			first->prev = new_node;
			new_node->next = first;
			first = new_node;
		}
		else //If the list is empty
		{
			first = last = new_node; //If the list is empty
		}

		num_elems++;
	}


	void insert(unsigned int position, const int& value)
	{
		Node* new_node = new Node(value);

		if (position == 0) // If it's the first position
		{
			if (first)
			{
				new_node->next = first;
				first->prev = new_node;
				first = new_node;
			}
			else //If it's empty
			{
				first = last = new_node;
			}
		}
		else if (position == num_elems) //If it's the last position
		{
			push_back(value);
			return;
		}
		else //If the position is in the middle 
		{
			Node* current = first; //We create a new node
			for (int i = 0; i < position; i++) //We move it to the desired position
			{
				current = current->next;
			}

			//Set and link the new node to the "sides"
			new_node->next = current;
			new_node->prev = current->prev;
			current->prev->next = new_node;
			current->prev = new_node;
		}
		num_elems++;
	}

	void print_list(Node* node)
	{
		//base case
		if (node == nullptr)
		{
			cout << endl; 
			return;
		}
		//recursive case
		cout << node->value << "  "; 
		print_list(node->next); 
	}


	void print_list()
	{
		print_list(first); 
	}
};


int main()
{
	List myList;

	myList.push_back(3);
	myList.print_list();
	myList.push_back(7);
	myList.print_list();
	myList.push_front(10);
	myList.print_list();
	myList.insert(2, 8);
	myList.print_list();
	myList.insert(0, 2);
	myList.print_list();

	system("pause");
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

List::~List()
{
}
