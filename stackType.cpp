#include "stackType.h"

template<class T>
stackType<T>::stackType()
{
    location=-1;
}

template<class T>
void stackType<T>::push(T item){

    location++;
    data[location] = item;

}
template<class T>
void stackType<T>::pop(){

    location--;
}

template<class T>
bool stackType<T>::isFull(){

    return(location==5);
}

template<class T>
bool stackType<T>::isEmpty(){
    return (location =-1);
}

template<class T>
T stackType<T>::Top(){

    return data[location];
}

template<class T>
int stackType<T>::lengthIs(){

    return location;
}
