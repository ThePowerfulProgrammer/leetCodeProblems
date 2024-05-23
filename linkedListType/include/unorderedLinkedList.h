#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

template <class Type>
class unorderedLinkedList
{
    public:
        bool search(const Type& searchValue) const
        {
            nodeType<Type> *temp;

            temp = first;

            while (temp != nullptr)
                {
                    if (temp->info == searchValue)
                        {
                            return true;
                        }
                    temp = temp->link;
                }
            return false;
        }

        void insertFirst(const Type& data) const
        {
            if (first != nullptr)
                {
                    nodeType<Type> *newNode;
                    newNode->info = data;

                    newNode->link = first;
                    first = newNode;
                }
            else
                {

                }
        }

        void insertLast(const Type& data) const;

        void deleteNode(const Type& deleteNode) const;
    protected:

    private:
};

#endif // UNORDEREDLINKEDLIST_H
