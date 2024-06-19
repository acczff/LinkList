#include <iostream>

class Mystring
{
private:

public:
    Mystring();
    ~Mystring();
    //拷贝构造函数
    Mystring(const Mystring& other)
    {
        std::cout << "KB" << std::endl;
    };

    //拷贝赋值运算符
    Mystring& operator=(const Mystring& other)
    {
         std::cout << "FZKB" << std::endl;
        if (this != &other) {
            // 赋值操作
        }
        return *this;
    };

    //移动构造函数
    Mystring(Mystring&& other) noexcept
    {
        std::cout << "YD" << std::endl;
    };

    //移动赋值运算符MAO
    Mystring& operator=(Mystring&& other) noexcept
    {
        if (this != &other) {
            // 移动赋值
        }
        return *this;
    }
};

Mystring::Mystring()
{
    std::cout << "GZ" << std::endl;
};

Mystring::~Mystring()
{
    
};

