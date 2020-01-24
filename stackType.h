#ifndef STACKTYPE_H
#define STACKTYPE_H
const int maximum =5;


template<class T>
class stackType
{
    public:
        stackType();
        void push(T);
        void pop();
        T Top();
        bool isFull();
        int lengthIs();
        bool isEmpty();


    private:
        T data[maximum];
        int location;
};

#endif // STACKTYPE_H
