
#include <iostream>
#include <string.h>

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
    {
        type = LetType::Char;
        m_c = new char[strlen(c) + 1];
        for (int i = 0; i < strlen(c); i++)
        {
            m_c[i] = c[i];
        }
    };

    Let(int i)
    {
        type = LetType::Int;
        m_i = i;
    };

    Let(double d)
    {
        type = LetType::Double;
        m_d = d;
    };

    Let &operator+(int num)
    {
        m_i += num;
        return *this;
    };

    Let &operator+(double num)
    {
        m_d += num;
        return *this;
    }

    Let &operator+(const char *newString)
    {
        if (type == LetType::Char)
        {
            int length = strlen(m_c) + strlen(newString) + 1;
            char *temp = new char(length);
            strcpy(temp, m_c);
            strcat(temp, newString);

            delete[] m_c;
            m_c = temp;
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

    Let &operator<(Let &other)
    {
    }

    ~Let()
    {
        if (type == LetType::Char)
        {
            delete[] m_c;
        }
    };

    // void display()
    // {
    //     if (type == LetType::Int)
    //     {
    //         std::cout << m_i << "\n";
    //     }
    //     else if (type == LetType::Double)
    //     {
    //         std::cout << m_d << "\n";
    //     }
    //     else if (type == LetType::Char)
    //     {
    //         std::cout << m_c << "\n";
    //     }
    // };

    friend std::ostream &operator<<(std::ostream &os, const Let &let);

private:
    LetType type;
    char *m_c;
    int m_i = 0;
    double m_d = 0.0;
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
    else
    {
        os << let.m_c;
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

    s = s + " muji";

    std::cout << a << std::endl;
    std::cout << d << std::endl;
    std::cout << s << std::endl;
};