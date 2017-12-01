///////////////////////////////////////////////////////////////////////////////
/// brief    Data
///
/// author  Александр Галко - ОКБ ТСП
/// date    31.10.2017
////////////////////////////////////////////////////////////////////////////////
#ifndef CPP11_DATA_H
#define CPP11_DATA_H

#include <iostream>

namespace CPP11 {

    using namespace std;

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

    void TestCpp();


} // namespace CPP11

#endif // CPP11_DATA_H
