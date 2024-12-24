template <class T>
class Stack
{
public:
    void clear();
    bool push(const T item);
    bool pop(T &item);
    bool top(T &item);
    bool isEmpty();
    bool isFull();
};

template <class T>
class ArrStack : public Stack<T>
{
private:
    int maxSize;
    int top;
    T *st;

public:
    ArrStack(int size)
    {
        maxSize = size;
        top = -1;
        st = new T[maxSize];
    }

    ArrStack()
    {
        top = -1;
    }

    ~ArrStack()
    {
        delete[] st;
    }

    void clear()
    {
        top = -1;
    }

    bool push(const T item)
    {
        if (top == maxSize - 1)
        {
            std::cout << "stack overflow" << std::endl;
            return false;
        }
        else
        {
            st[++top] = item;
            return true;
        }
    }

    bool pop(T &item)
    {
        if (top == -1)
        {
            std::cont << "can not pot" << std::endl;
            return false;
        }
        else
        {
            item = st[top--];
            return true;
        }
    }
};

template <class T>
class LinkStack : public Stack<T>
{
private:
    Link<T> *top;
    int size;

public:
    LinkStack(int defSize)
    {
        top = nullptr;
        size = 0;
    }
};
