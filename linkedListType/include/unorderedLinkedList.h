#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H
#include "linkedListType.h"

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
    public:
        bool search(const Type& searchItem) const
        {
            nodeType<Type> *temp;
            temp = this->first;

            while (temp != nullptr)
                {
                    if (temp->info == searchItem)
                        {
                            return true;
                        }
                    temp = temp->link;
                }
            return false;
        }

        void insertFirst(const Type& newItem) const
        {
            nodeType<Type> *newNode;
            newNode = new nodeType<Type>;
            newNode->info = newItem;

            newNode->link = this->first;
            this->first = newNode;
            this->count++;
            if (this->last == nullptr)
                {
                    this->last = newNode;
                }
        }

        void insertLast(const Type& newItem) const
        {
            nodeType<Type> *newNode;
            newNode = new nodeType<Type>;
            newNode->info = newItem;
            newNode->link = nullptr;

            if (this->fist == nullptr)
                {
                    this->first = newNode;
                    this->last = newNode;
                    this->count++;
                }
            else
                {
                    this->last->link = newNode;
                    this->last = newNode;
                    this->count++;
                }

        }

        void deleteNode(const Type& deleteItem) const
        {
            nodeType<Type> *current;
            nodeType<Type> *trailCurrent; // pointer before current
            bool found;

            if (this->first == nullptr)
                {
                    cout << "List is empty, No object to delete" << endl;
                }
            else
                {
                    if (this->first->info == deleteItem)
                        {
                            current = this->first;
                            this->first = this->first->link;
                            this->count--;

                            if (this->first == nullptr)
                                {
                                    this->last = nullptr;
                                }
                            delete current;
                        }
                    else
                        {
                            found = false;
                            trailCurrent = this->first;

                            current = this->first->link;
                            while (current != nullptr & !found)
                                {
                                    if (current->info != deleteItem)
                                        {
                                            trailCurrent = current;
                                            current = current->link;
                                        }
                                    else
                                        {
                                            found = true;
                                        }
                                }
                            if (found)
                                {
                                    trailCurrent->link = current->link;
                                    this->count--;

                                    if (this->last==current)
                                        {
                                            this->last = trailCurrent;
                                        }
                                    delete current;
                                }
                            else
                                {
                                    cout << "The entire list has been searched and the item to be removed is not in the list :) " << endl;
                                }
                        }
                }
        }
    protected:

    private:
};

#endif // UNORDEREDLINKEDLIST_H
