/*implement stack using Linked list*/
#ifndef STACK_H
#define STACK_H

#include "error.h"

template <typename ValueType>
class Stack
{
public:
    Stack();
    
    Stack(const Stack<ValueType> & src);

    ~Stack();
    
    Stack<ValueType> & operator=(const Stack<ValueType>& src);

    int size() const;

    bool isEmpty() const;

    void clear();

    void push(ValueType value);

    ValueType pop();

    ValueType peek() const;

    // the private section of the class goes here.

private:
    struct Cell {
        ValueType data; // The data value
        Cell *link;     // link to the next cell
    };

    Cell *list;         // Initial pointer
    int count;          // Number of element
    
    void deepCopy(const Stack<ValueType>& src);
};

template <typename ValueType>
Stack<ValueType>::Stack(){
    list = NULL;
    count = 0;
}

template <typename ValueType>
Stack<ValueType>::~Stack<ValueType>(){
    clear();
}

template <typename ValueType>
int Stack<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool Stack<ValueType>::isEmpty() const {
    return (count == 0);
}

template <typename ValueType>
void Stack<ValueType>::clear() {
    while (count > 0){
        pop();
    }
}

template <typename ValueType>
void Stack<ValueType>::push(ValueType value){
    Cell *cp = new Cell;
    cp->data = value;
    cp->link = list;
    list = cp;
    count ++;
}

template <typename ValueType>
ValueType Stack<ValueType>::pop(){
    if (isEmpty()) error("pop: Attempting to pop an empty stack");
    Cell *cp = list;
    ValueType result = cp->data;
    list = list->link;
    count--;
    delete cp;
    return result;
}

template <typename ValueType>
ValueType Stack<ValueType>::peek() const{
    if (isEmpty()) error("peek: Attempting to peek at an empty stack");
    return list->data;
}



#endif // STACK_H
