///////////////////////////////////////////////////////////////////////////////
/// brief    Data
///
/// author  Александр Галко - ОКБ ТСП
/// date    31.10.2017
////////////////////////////////////////////////////////////////////////////////
#ifndef CPP17_DATA_H
#define CPP17_DATA_H

#include <iostream>

namespace CPP17 {

    using namespace std;

    template<typename... Args>
    auto Suml(Args... args)
    {
      return (args + ...);
    }
    template<typename... Args>
    auto Sumr(Args... args)
    {
      return (... + args);
    }
//    template<typename Arg, typename... Args>
//    auto Sumold(Arg first, Args... rest)
//    {
//      return first + Sumold(rest...);
//    }
    // C++17
    template<auto n>
    void Func17() { /* .... */ }
    // C++14
    template<typename Type, Type n>
    void Func14() { /* .... */ }

    class TestCpp
    {
    public:
        TestCpp()
        {
            cout<< "CPP17::TestCpp" << endl;
            FoldExpressions();
            TemplateAuto();

        }
        void FoldExpressions()
        {
            std::cout << Suml(1, 2, 3, 4, 5) << '\n'; // 15
            std::cout << Sumr(1, 2, 3, 4, 5) << '\n'; // 15
//            std::cout << Sumold(1, 2, 3, 4, 5) << '\n'; // 15
        }
        void TemplateAuto()
        {
            Func17<42>(); // выведет тип int
             Func17<'c'>(); // выведет тип char
             Func14<int, 42>();
             Func14<char, 'c'>();
        }
    };
    class Data
    {
    public:
        Data()
        {
            cout << "Data" << endl;
        }
        ~Data()
        {
            cout << "~Data" << endl;
        }
        bool isValid()
        {
            cout << "isValid" << endl;
            return _data != 0 ? true : false;
        }
    private:
         char* _data = 0;
    };
} // namespace CPP17

#endif // CPP17_DATA_H
