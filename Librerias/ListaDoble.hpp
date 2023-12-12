

#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include <iostream>
#include <stdexcept>

/**
 * @namespace ListaDoble
 * @brief Namespace que encapsula la implementación de una lista doblemente enlazada.
 */
namespace ListaDoble
{

	/**
	 * @struct Node
	 * @brief Estructura que representa un nodo en la lista doblemente enlazada.
	 */
	template <class T>
	struct Node
	{
		T data;			   ///< Datos almacenados en el nodo.
		Node<T> *previous; ///< Puntero al nodo anterior.
		Node<T> *next;	   ///< Puntero al nodo siguiente.
	};

	/**
	 * @class DoubleLinkedList
	 * @brief Clase que implementa una lista doblemente enlazada.
	 */
	template <class T>
	class DoubleLinkedList
	{
	private:
		Node<T> *header; ///< Puntero al nodo inicial de la lista.
		Node<T> *z;		 ///< Puntero al nodo final de la lista.
		int size;		 ///< Tamaño actual de la lista.

	public:
		/**
		 * @brief Constructor que inicializa la lista.
		 */
		DoubleLinkedList();

		/**
		 * @brief Devuelve el tamaño de la lista.
		 * @return Tamaño de la lista.
		 */
		int Size();

		void AddFirst(T data);
		/**
		 * @brief Añade un elemento al final de la lista.
		 * @param data Datos a añadir.
		 */
		void AddLast(T data);

		/**
		 * @brief Añade un elemento en orden ascendente.
		 * @param data Datos a añadir.
		 */
		void AddDirectly(T data);

		/**
		 * @brief Elimina un elemento en la posición indicada.
		 * @param pos Posición del elemento a eliminar.
		 * @return true si se eliminó correctamente, false si la posición es inválida.
		 */
		bool RemovePos(int pos);

		/**
		 * @brief Elimina un elemento con el valor indicado.
		 * @param data Valor del elemento a eliminar.
		 * @return true si se eliminó correctamente, false si el elemento no se encontró.
		 */
		bool RemoveData(T data);

		/**
		 * @brief Modifica el valor de un elemento en la posición indicada.
		 * @param pos Posición del elemento a modificar.
		 * @param data Nuevo valor para el elemento.
		 */
		void SetDataPos(int pos, T data);

		/**
		 * @brief Obtiene el valor de un elemento en la posición indicada.
		 * @param pos Posición del elemento a obtener.
		 * @return Valor del elemento en la posición indicada.
		 *
		 * *IMPORTANTE, el primer dato comienza desde 1, no desde 0, es asi porque asi la profe lo quizo xd
		 */
		T getData(int pos);

		/**
		 * @brief Modifica el valor de un elemento con el valor antiguo indicado.
		 * @param oldData Valor antiguo del elemento.
		 * @param newData Nuevo valor para el elemento.
		 * @return true si se modificó correctamente, false si el elemento antiguo no se encontró.
		 */
		bool SetData(T oldData, T newData);

		/**
		 * @brief Elimina un nodo dado un puntero al nodo.
		 * @param node Puntero al nodo que se desea eliminar.
		 * @return true si se eliminó correctamente, false si el nodo no pertenece a la lista.
		 */
		bool RemoveNode(Node<T> *node);
	};

	template <class T>
	int DoubleLinkedList<T>::Size() { return size; }

	template <class T>
	DoubleLinkedList<T>::DoubleLinkedList()
	{
		// * Declaración de dos punteros auxiliares que facilitarán la manipulación de la lista.

		// Inicialización de la lista doblemente enlazada.
		header = new Node<T>; ///< Nodo inicial de la lista.
		z = new Node<T>;	  ///< Nodo final de la lista.

		// Configuración de punteros para formar una lista vacía.
		header->data = T();	  ///< Valor nulo para el tipo T.
		z->data = T();		  ///< Valor nulo para el tipo T.
		header->next = z;	  ///< Header apunta a z.
		z->previous = header; ///< z apunta al nodo anterior (header).
		z->next = z;		  ///< z apunta a sí mismo como siguiente nodo.

		size = 0;
	}

	template <class T>
	void DoubleLinkedList<T>::AddFirst(T Data)
	{
		Node<T> *newNode = new Node<T>; ///< Se inicializa un nuevo nodo con el nuevo dato.
		newNode->data = Data;

		newNode->next = header->next;
		newNode->previous = header;

		header->next->previous = newNode;
		header->next = newNode;
	}
	template <class T>
	void DoubleLinkedList<T>::AddLast(T Data)
	{

		Node<T> *newNode = new Node<T>; ///< Se inicializa un nuevo nodo con el nuevo dato.
		newNode->data = Data;

		newNode->previous = z->previous; ///< El nuevo nodo apunta al nodo anterior al que apunta z.

		z->previous->next = newNode; ///<  El nodo anterior a z ahora apunta al nuevo nodo.

		z->previous = newNode; ///< z ahora apunta al nuevo nodo como último nodo.

		newNode->next = z; ///< El nuevo nodo apunta a z como siguiente nodo.

		size++;
	}

	template <class T>
	void DoubleLinkedList<T>::AddDirectly(T data)
	{
		Node<T> *newNode, *temp, *previousNode;

		newNode = new Node<T>; ///<  Incializo el nuevo nodo con el dato
		newNode->data = data;

		temp = header; ///< A temp le asigno la direccion de la cabecera

		// Recorro la lista para saber donde ubicar el nodo
		// El metodo es asi ya que de lo contrario dev se muere xd
		// * Temp termina en el nodo inmediatamente mayor al dato nuevo
		// * Si tengo 1,2,3,5 y quiero agregar el 4, temp tendria el valor de 5 depués del while
		while (temp != z)
		{
			if (temp->data != T())
			{
				if (data < temp->data)
				{
					break;
				}
			}
			temp = temp->next;
		}

		// El nodo anterior a temp
		previousNode = temp->previous;

		// El nuevo nodo apunta a temp
		newNode->next = temp;

		// El nuevo nodo apunta al previousNode, el que era el nodo anterior a temp
		newNode->previous = previousNode;

		// EL nodo anterior apunta al nuevo nodo
		previousNode->next = newNode;

		// temp ahora apunta al nuevo nodo
		temp->previous = newNode;

		size++;
	}

	template <class T>
	bool DoubleLinkedList<T>::RemoveNode(Node<T> *node)
	{
		if (!node || node == header || node == z)
		{
			return false;
		}

		Node<T> *previousNode = node->previous;
		Node<T> *nextNode = node->next;

		// Actualiza los punteros del nodo anterior y posterior para saltar el nodo que se eliminará.
		previousNode->next = nextNode;
		nextNode->previous = previousNode;

		// Libera la memoria del nodo que se eliminó.
		delete node;

		// Actualiza el tamaño de la lista.
		size--;

		return true;
	}

	template <class T>
	T DoubleLinkedList<T>::getData(int pos)
	{
		if (pos < 1 || pos > size)
		{
			return T(); // Devuelve un valor nulo para el tipo T
			throw std::out_of_range("Invalid position.");
		}
		else
		{
			Node<T> *aux = header;
			for (int i = 1; i <= pos; i++)
				aux = aux->next;

			return aux->data;
		}
	}

	template <class T>
	bool DoubleLinkedList<T>::RemovePos(int pos)
	{
		// Primero verifica que la posición si sea válida
		if (pos <= size)
		{
			// Luego busca al nodo
			Node<T> *temp = header;

			for (int i = 1; i <= pos; i++)
				temp = temp->next;

			// Luego lo elimina
			return RemoveNode(temp);
		}
		else
		{
			throw std::out_of_range("Invalid position.");
			return false;
		}
	}

	template <class T>
	bool DoubleLinkedList<T>::RemoveData(T data)
	{
		// Asigno un nodo temp que servirá para ir recorriendo la lista
		Node<T> *temp = header;

		// Se recorre la lista hasta encontrar el dato
		while (temp != z && temp->data != data)
			temp = temp->next;

		// Si temp es igual a z significa que no existe
		if (temp == z)
			return false;
		else
			// De lo contrario se eliminará el nodo usando el metodo removeNode
			return RemoveNode(temp);
	}

	template <class T>
	void DoubleLinkedList<T>::SetDataPos(int pos, T data)
	{
		if (pos < 1 || pos > size)
		{
			throw std::out_of_range("Invalid position.");
		}
		else
		{
			Node<T> *aux = header->next;
			for (int i = 1; i < pos; i++)
				aux = aux->next;
			aux->data = data;
		}
	}

	template <class T>
	bool DoubleLinkedList<T>::SetData(T oldData, T newData)
	{
		Node<T> *aux = header;
		while (aux != z && aux->data != oldData)
			aux = aux->next;

		if (aux == z)
			return false;
		else
		{
			aux->data = newData;
			return true;
		}
	}
}
#endif
