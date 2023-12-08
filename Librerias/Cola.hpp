/**
 * @file COLA_HPP
 * @brief Contiene la implementación de una cola utilizando una estructura de nodos enlazados.
 * @namespace Cola
 */
#ifndef COLA_HPP
#define COLA_HPP

#include <cstdlib>
#include <iostream>

namespace Cola
{
    /**
     * @struct Node
     * @brief Estructura que representa un nodo en la cola.
     */
    template <class T>
    struct Node
    {
        T data;                   ///< Datos almacenados en el nodo.
        Node<T> *previous, *next; ///< Punteros al nodo anterior y siguiente.
    };

    /**
     * @class Queue
     * @brief Clase que implementa una cola utilizando nodos enlazados.
     */
    template <class T>
    class Queue
    {
    private:
        Node<T> *header, *z; ///< Punteros al nodo inicial (header) y final (z) de la cola.
        int size;            ///< Tamaño actual de la cola.

    public:
        /**
         * @brief Constructor que inicializa la cola.
         */
        Queue();

        /**
         * @brief Devuelve el tamaño de la cola.
         * @return Tamaño de la cola.
         */
        int Size() { return size; };

        /**
         * @brief Agrega un elemento a la cola.
         * @param data Datos a agregar.
         * @param opt Opción que indica el lado de la cola donde agregar (I: izquierda, D: derecha).
         */
        void Enqueue(T data, char opt);

        /**
         * @brief Elimina y devuelve un elemento de la cola.
         * @param opt Opción que indica el lado de la cola para eliminar (I: izquierda, D: derecha).
         * @return Elemento eliminado.
         */
        T Dequeue(char opt);

        /**
         * @brief Obtiene el dato en la posición especificada.
         * @param pos Posición del dato a obtener.
         * @return Dato en la posición especificada.
         */
        T Front(char opt);

        /**
         * @brief Verifica si la cola está vacía.
         * @return true si la cola está vacía, false de lo contrario.
         */
        bool IsEmpty() { return header->next == z; }
    };

    template <class T>
    Queue<T>::Queue()
    {
        header = new Node<T>; ///< Se crea el nodo header que servirá como el nodo inicial de la cola.
        z = new Node<T>;      ///< Se crea el nodo z que servirá como el nodo final de la cola.

        header->data = T(); ///< Asigna el valor nulo para el tipo T al campo data de header.

        header->next = z;     ///< Header apunta a z como siguiente nodo.
        z->previous = header; ///< Z apunta hacia el nodo anterior (header).

        z->next = z;   ///< Z apunta a sí mismo como siguiente nodo.
        z->data = T(); ///< Asigna el valor nulo para el tipo T al campo data de z.

        size = 0; ///< Inicializa el tamaño de la cola en 0.
    }

    template <class T>
    void Queue<T>::Enqueue(T data, char opt)
    {
        Node<T> *newNode, *temp, *auxiliaryNode;
        newNode = new Node<T>;
        newNode->data = data;

        switch (opt)
        {
        case 'I':
            auxiliaryNode = z->previous;       ///< Nodo auxiliar apunta al nodo antes de z
            z->previous = newNode;             ///< Z apunta al nuevo nodo como anterior
            newNode->next = z;                 ///< Nuevo nodo apunta a z como siguiente
            newNode->previous = auxiliaryNode; ///< Nuevo nodo apunta al nodo anterior como anterior
            auxiliaryNode->next = newNode;     ///< Nodo anterior apunta al nuevo nodo como siguiente
            break;
        case 'D':
            auxiliaryNode = header->next;      ///< Nodo auxiliar apunta al nodo siguiente al header
            header->next = newNode;            ///< Header apunta al nuevo nodo como siguiente
            newNode->previous = header;        ///< Nuevo nodo apunta al header como anterior
            auxiliaryNode->previous = newNode; ///< Nodo anterior apunta al nuevo nodo como anterior
            newNode->next = auxiliaryNode;     ///< Nuevo nodo apunta al nodo anterior como siguiente
            break;
        default:
            break;
        }

        size++;
    }

    template <class T>
    T Queue<T>::Dequeue(char opt)
    {
        Node<T> *temp, *auxiliaryNode;
        T data;
        if (header->next != z)
        {
            switch (opt)
            {
            case 'I':
                temp = header->next;        ///<  Nodo que se va a eliminar.
                auxiliaryNode = temp->next; ///< Nodo que está después de temp.

                data = temp->data;

                auxiliaryNode->previous = header; ///< El puntero del nodo auxiliar apunta al header.
                header->next = auxiliaryNode;     ///< El puntero al nodo siguiente del header es el nodo auxiliar.
                break;

            case 'D':
                temp = z->previous;             ///< Nodo que se va a eliminar.
                auxiliaryNode = temp->previous; ///< Nodo que está antes de temp.

                data = temp->data;

                auxiliaryNode->next = z;     ///< El puntero al nodo siguiente del nodo auxiliar es z.
                z->previous = auxiliaryNode; ///< El puntero al nodo anterior de z es el nodo auxiliar.
                break;

            default:
                break;
            }

            delete temp;
            size--;
        }
        return data;
    }

    template <class T>
    T Queue<T>::Front(char opt)
    {
        Node<T> *temp;
        switch (opt)
        {
        case 'I':
            temp = header->next; ///< Temp apunta al nodo siguiente al header
            return temp->data;
            break;

        case 'D':
            temp = z->previous; ///< Temp apunta al nodo anterior a z
            return temp->data;
        default:
            break;
        }
    }
}
#endif
