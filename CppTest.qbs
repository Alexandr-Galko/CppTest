import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
//        Depends { name: "Qt.core" }

        cpp.cxxLanguageVersion: "c++1z"

        consoleApplication: true
        files: [
            "CPP03.Data.cpp",
            "CPP03.Data.h",
            "CPP11.Data.cpp",
            "CPP11.Data.h",
            "CPP14.Data.cpp",
            "CPP14.Data.h",
            "CPP17.Data.cpp",
            "CPP17.Data.h",
            "main.cpp",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: product.type
            qbs.install: true
        }
    }
}
