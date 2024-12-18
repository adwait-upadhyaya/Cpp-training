#include <iostream>
#include <memory>
#include <string>
#include <cstring>

enum class LetType
{
    Char,
    Int,
    Double,
};

class Let
{
public:
    Let(const char *c)
        : type(LetType::Char), m_str(std::make_shared<std::string>(c)) {}

    Let(int i)
        : type(LetType::Int), m_i(i) {}

    Let(double d)
        : type(LetType::Double), m_d(d) {}

    Let &operator+(int num)
    {
        if (type == LetType::Int)
        {
            m_i += num;
        }
        return *this;
    }

    Let &operator+(double num)
    {
        if (type == LetType::Double)
        {
            m_d += num;
        }
        return *this;
    }

    Let &operator+(const char *newString)
    {
        if (type == LetType::Char)
        {
            *m_str += newString;
        }
        return *this;
    }

    Let &operator+=(int newNum)
    {
        if (type == LetType::Int)
        {
            m_i += newNum;
        }
        return *this;
    }

    Let &operator+=(double newNum)
    {
        if (type == LetType::Double)
        {
            m_d += newNum;
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Let &let);

private:
    LetType type;
    int m_i = 0;
    double m_d = 0.0;
    std::shared_ptr<std::string> m_str;
};

std::ostream &operator<<(std::ostream &os, const Let &let)
{
    if (let.type == LetType::Int)
    {
        os << let.m_i;
    }
    else if (let.type == LetType::Double)
    {
        os << let.m_d;
    }
    else if (let.type == LetType::Char)
    {
        os << *let.m_str;
    }
    return os;
}

int main()
{
    Let a = 1234;
    Let d = 35.5;
    Let s = "hello";

    a = a + 5;
    d = d + 5.5;
    d = d + 4.5;
    s = s + " world";

    std::cout << a << std::endl;
    std::cout << d << std::endl;
    std::cout << s << std::endl;

    return 0;
}
