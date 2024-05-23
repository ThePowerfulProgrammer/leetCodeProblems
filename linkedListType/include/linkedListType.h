#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

#include "linkedListIterator.h"
#include <iostream>

using namespace std;

template <class Type>
class linkedListType
{
    public:
        // default ctor
        linkedListType()
        {
            count = 0;
            first = nullptr;
            last = nullptr;
        }

        // copy ctor
        linkedListType(const linkedListType<Type>& other)
        {
            first = nullptr;
            copyList(other);
        }

        const linkedListType<Type>& operator=(const linkedListType<Type>& otherList)
        {
            if (this != &otherList)
                {
                    copyList(otherList);
                }
        }

        Type front() const
        {
            assert(first != nullptr);

            return first->info;
        }

        Type back() const
        {
            assert(last != nullptr);

            return last->info;
        }

        linkedListIterator<Type> begin()
        {
            linkedListIterator<Type> temp(first);
        }

        linkedListIterator<Type> end()
        {
            linkedListIterator<Type> temp(nullptr);
        }

        void print() const
        {
            nodeType<Type> *temp;
            temp = first;
            while (temp != nullptr)
                {
                    cout << temp->info << " ";
                    temp = temp->link;
                }
        }

        int length() const
        {
            return count;
        }

        void destroyList()
        {
            nodeType<Type> *temp;
            temp = first;
            while (first != nullptr)
                {
                    first = first->link;
                    delete temp;
                    temp =  first;
                }
            last = nullptr;
            count = 0;
        }

        bool isEmptyList() const
        {
            return first == nullptr;
        }

        // delete and init list
        void initializeList()
        {
            destroyList();
        }

        // Must be implemented in children
        bool search(const Type& searchValue) const = 0;

        void insertFirst(const Type& insertNode) const = 0;

        void insertLast(const Type& insertNode) const = 0;

        void deleteNode(const Type& deleteNode) const = 0;
        // Must be implemented in children

        ~linkedListType()
        {
            destroyList();
        }

    protected:
        int count;
        nodeType<Type> *first;
        nodeType<Type> *last;

    private:
        void copyList(const linkedListType<Type> &other)
        {
            nodeType<Type> *newNode;
            nodeType<Type> *current;

            if (this->first != nullptr)
                {
                    this->destroyList();
                }

            if (other.first == nullptr)
                {
                    this->first = nullptr;
                    this->last = nullptr;
                    this->count = 0;
                }
            else
                {
                    current = other.first; // current points to list to be copied
                    this->count = other.count;

                    // begin copying
                    this->first = new nodeType<Type>;

                    this->first->info = current->info;
                    this->first->link = nullptr;

                    this->last = first;
                    current = current->link;
                    // copy rest

                    while (current != nullptr)
                        {
                            newNode = new nodeType<Type>;
                            newNode->info = current->info;
                            newNode->link = nullptr;

                            this->last->link = newNode;
                            this->last = newNode;

                            current = current->link;
                        }
                }
        }
};

#endif // LINKEDLISTTYPE_H
