///////////////////////////////////////////////////////////////////////////////
/// brief    Data
///
/// author  Александр Галко - ОКБ ТСП
/// date    31.10.2017
////////////////////////////////////////////////////////////////////////////////
#ifndef CPP14_DATA_H
#define CPP14_DATA_H

#include <iostream>

namespace CPP14 {

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

} // namespace CPP14

#endif // CPP14_DATA_H
