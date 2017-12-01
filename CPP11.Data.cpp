///////////////////////////////////////////////////////////////////////////////
/// brief    Data
///
/// author  Александр Галко - ОКБ ТСП
/// date    31.10.2017
////////////////////////////////////////////////////////////////////////////////
#include "CPP11.Data.h"

namespace CPP11 {

    void TestCpp()
    {
        cout<< "CPP11::TestCpp" << endl;
        auto data0 = Data();
        data0.isValid();
        decltype(data0) data1;
        data1 = data0;
        data1.isValid();
    }


} // namespace CPP11
