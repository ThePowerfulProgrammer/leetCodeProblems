#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};


// Remember an iterator is a pointer that is used to traverse a container
template <class Type>
class linkedListIterator
{
    public:
        // default ctor
        linkedListIterator()
        {
            current = nullptr;
        }

        // overloaded ctor
        linkedListIterator(nodeType<Type> *ptr)
        {
            current = ptr;
        }

        // overload the dereference operator
        Type operator*()
        {
            return current->info;
        }

        linkedListIterator<Type> operator++()
        {
            current = current->link;
            return *this;
        }

        bool operator==(const linkedListIterator<Type>& other)
        {
            return current == other.current;
        }

        bool operator!=(const linkedListIterator<Type>& other)
        {
            return current != other.current;
        }


    protected:

    private:
        nodeType<Type> *current;
};

#endif // LINKEDLISTITERATOR_H
