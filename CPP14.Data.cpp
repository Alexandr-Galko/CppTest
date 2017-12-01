///////////////////////////////////////////////////////////////////////////////
/// brief    Data
///
/// author  Александр Галко - ОКБ ТСП
/// date    31.10.2017
////////////////////////////////////////////////////////////////////////////////
#include "CPP14.Data.h"

namespace CPP14 {

    void TestCpp()
    {
        cout<< "CPP14::TestCpp" << endl;
        auto data0 = Data();
        data0.isValid();
        decltype(data0) data1;
        data1 = data0;
        data1.isValid();
    }



} // namespace CPP14
