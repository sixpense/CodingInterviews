// 048-不能被继承的类
// 在C/C++中, 子类的构造函数自动调用父类的构造函数, 析构函数也是如此
// 要想一个类不能被继承, 我们只要把它的构造函数和析构函数定义为私有函数
// 那么当一个类试图从它那继承时, 必然会由于试图调用构造和析构函数而导致编译错误


#include <iostream>
using namespace std;


// 如果类的构造函数和析构函数都是私有函数, 该如何得到该类的实例:
// 定义静态函数或者静态变量来创建和释放类的实例
// 友元函数可以访问类的私有成员
// 友元类可以访问类的私有成员



class SealedClass {
public:
    static SealedClass* GetInstance() {
        return new SealedClass();
    }
private:
    SealedClass() { }

    ~SealedClass() { };
};

class Base: public SealedClass {

};

int main1() {
    SealedClass *pd = Base::GetInstance();
    Base base;

    return 0;
}


// 友元函数实现

class SealedClass_one {
private:
    SealedClass_one() { }
    ~SealedClass_one() {  }
public:
    friend SealedClass_one* GetInstance();
};

SealedClass_one GetInstance() {
    return new SealedClass_one();
}

class Base_one: public SealedClass_one {

};

int main2() {
    SealedClass_one *p = GetInstance();

    // Base base;                   // error
    return 0;
}

int main() {
    main1();
    main2();

    return 0;
}


