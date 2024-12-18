#include <iostream>

template <typename _Tp>
class SharedPointer
{
public:
    SharedPointer() = delete;
    template <typename Tu>
    friend std::ostream &operator<<(std::ostream &os, const SharedPointer<Tu> &pointer);
    // Constructor
    SharedPointer(_Tp *val)
    {
        value = val;

        refCount = new int(0);

        (*refCount)++;
        std::cout << "Constructor: Reference Count = " << *refCount << std::endl;
    }

    // Copy Constructor
    SharedPointer(const SharedPointer &other)
    {
        value = other.value;
        refCount = other.refCount;
        (*refCount)++;
        std::cout << "Copy Constructor: Reference Count = " << *refCount << std::endl;
    }

    // Destructor
    ~SharedPointer()
    {
        (*refCount)--;
        std::cout << "Destructor: Reference Count = " << *refCount << std::endl;

        if (*refCount == 0)
        {
            delete value;
            delete refCount;
            value = nullptr;
            refCount = nullptr;
            std::cout << "Memory Released" << std::endl;
        }
    }

private:
    _Tp *value;
    int *refCount;
};

template <typename Tu>
std::ostream &operator<<(std::ostream &os, const SharedPointer<Tu> &pointer)
{
    os << pointer.value;
    return os;
}

int main()
{
    int *val = new int(100);
    SharedPointer<int> p1 = val;
    SharedPointer<int> p2 = p1;
    SharedPointer<int> p3 = p2;

    return 0;
}