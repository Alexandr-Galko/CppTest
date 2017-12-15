///////////////////////////////////////////////////////////////////////////////
/// brief    Data
///
/// author  Александр Галко - ОКБ ТСП
/// date    31.10.2017
////////////////////////////////////////////////////////////////////////////////
#ifndef CPP17_DATA_H
#define CPP17_DATA_H

#include <array>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
/// has include
#include <experimental/optional>
#if __has_include(<optional>)
#include <optional>
#else
#include <experimental/optional>
#endif
#if __has_include(<filesystem>)
#include <experimental/filesystem>
#else
#include <experimental/filesystem>
#endif

namespace CPP17
{

    using namespace std;

    class TestCpp
    {
    public:
        TestCpp()
        {
            cout << "CPP17::TestCpp" << endl;
            FoldExpressions();
            TemplateAuto();
            TemplateTypes();
            ConstexprIf();
            ConstexprL();
            ThisLock();
            StructureBind();
            InitIf();
            FileSystem();
        }
        ///Свертка параметров шаблона (Fold expressions)
        template <typename... Args> auto Suml(Args... args)
        {
            return (args + ...);
        }
        template <typename... Args> auto Sumr(Args... args)
        {
            return (... + args);
        }
        //    template<typename Arg, typename... Args>
        //    auto Sumold(Arg first, Args... rest)
        //    {
        //      return first + Sumold(rest...);
        //    }
        void FoldExpressions()
        {
            std::cout << Suml(1, 2, 3, 4, 5) << '\n'; // 15
            std::cout << Sumr(1, 2, 3, 4, 5) << '\n'; // 15
                                                      //            std::cout << Sumold(1, 2, 3, 4, 5) << '\n'; // 15
        }

        /// template<auto>
        // C++17
        template <auto n> void Func17()
        { /* .... */
        }
        void TemplateAuto()
        {
            Func17<42>();  // выведет тип int
            Func17<'c'>(); // выведет тип char
        }
        ///Вывод типов шаблонных параметров для классов
        template <typename T, typename U> struct S
        {
            T _first;
            U _second;
            S(T first, U second)
                : _first(first)
                , _second(second)
            {
            }
        };
        template <typename T, typename U> struct S2
        {
            T _first;
            U _second;
        };
        // Мой deduction guide
        template <typename T, typename U> S2(const T& first, const U& second)->S2<T, U>;
        void TemplateTypes()
        {
            // C++17
            pair p2 = {'c', 42};
            //          tuple t2 = { 'c', 42, 3.14 };
            S s2  = {10, 'c'};
            S2 s3 = {10, 'c'};
        }
        template <typename T> auto GetValue(T t)
        {
            if constexpr (std::is_pointer<T>::value)
            {
                return *t;
            }
            else
            {
                return t;
            }
        }
        /// Constexpr if
        void ConstexprIf()
        {
            int v = 10;
            std::cout << GetValue(v) << '\n';  // 10
            std::cout << GetValue(&v) << '\n'; // 10
        }

        /// Constexpr лямбды
        void ConstexprL()
        {
            constexpr auto squared = [](int x) { return x * x; };
            constexpr int s        = squared(5);
            static_assert(s == 25);
        }
        ///Захват *this в лямбда-выражениях
        class SomeClass
        {
        public:
            int m_x = 0;

            void f() const
            {
                std::cout << m_x << '\n';
            }

            void g()
            {
                m_x++;
            }

            // С++17
            void FuncNew()
            {
                // const копия *this
                auto lambda1 = [*this]() { f(); };
                // non-const копия *this
                auto lambda2 = [*this]() mutable { g(); };
                lambda1();
                lambda2();
            }
        };
        void ThisLock()
        {
            SomeClass c;
            c.FuncNew();
        }
        /// inline переменные
        ///Структурное связывание (Structured bindings)
        void StructureBind()
        {
            set<int> mySet;
            auto [iter, ok]   = mySet.insert(42);
            int arr[]         = {1, 2, 3, 4};
            auto [a, b, c, d] = arr;
            std::cout << a << b << c << d << '\n';

            struct S
            {
                char x{'c'};
                int y{42};
                double z{3.14};
            } s;
            auto [e, f, g] = s;
            cout << e << ' ' << f << ' ' << g << ' ' << '\n';

            map<int, char> myMap = {{0, 'A'}, {1, 'B'}, {2, 'C'}};

            for (const auto& [key, value] : myMap)
            {
                cout << "key: " << key << ' ';
                cout << "value: " << value << '\n';
            }
        }
        ///Инициализатор в if и switch
        void InitIf()
        {
            map<int, char> myMap = {{0, 'A'}, {1, 'B'}, {2, 'C'}};
            if (auto [it, ok] = myMap.insert({2, 'E'}); ok)
            {
                cout << "inset ok";
            }
            else
            {
                cout << "inset error";
            }
        }
        ///В дополнение к уже существующим стандартным
        /// атрибутам `[[noreturn]]`, `[[carries_dependency]]` и `[[deprecated]]` в C++17 появились 3 новых атрибута:
        [[nodiscard]] int Sum(int a, int b)
        {
          return a + b;
        }
        void Attributes()
        {
            [[maybe_unused]] int a;
            int i = 7;
            switch (i)
            {
            case 1:
                cout << "1";
                break;
            case 2:
                cout << "2";
                break;
            case 3:
                cout << "3";
                break;
                [[fallthrough]]; // Предупреждение будет подавлено
            case 5:
                cout << "5";
            }
            ///  ###[[nodiscard]] Этот атрибут используется, чтобы обозначить, что возвращаемое значение функции
            Sum(1,2);
        }
        /// std::byte
        /// ##Динамическое выделение памяти для типов с нестандартным выравниванием (Dynamic allocation of over-aligned types)
        /// ##Более строгий порядок вычисления выражений
        /// ##Filesystem
//        using fs = std::experimental::filesystem;
        void FileSystem()
        {
//            fs::path file_path("/dir1/dir2/file.txt");
//            cout << file_path.parent_path() << '\n'; // Выведет "/dir1/dir2"
//            cout << file_path.filename() << '\n'; // Выведет "file.txt"
//            cout << file_path.extension() << '\n'; // Выведет ".txt"

//            file_path.replace_filename("file2.txt");
//            file_path.replace_extension(".cpp");
//            cout << file_path << '\n'; // Выведет "/dir1/dir2/file2.cpp"

//            fs::path dir_path("/dir1");
//            dir_path.append("dir2/file.txt");
//            cout << dir_path << '\n'; // Выведет "/dir1/dir2/file.txt"

//            // Получение текущей рабочей директории
//            fs::path current_path = fs::current_path();

//            // Создание директории
//            fs::create_directory("/dir");

//            // Создание нескольких директорий
//            fs::create_directories("/dir/subdir1/subdir2");

//            // Проверка существования директории
//            if (fs::exists("/dir/subdir1"))
//            {
//              cout << "yes\n";
//            }

//            // Нерекурсивный обход директории
//            for (auto &p : fs::directory_iterator(current_path))
//            {
//              cout << p.path() << '\n';
//            }

//            // Рекурсивный обход директории
//            for (auto &p : fs::recursive_directory_iterator(current_path))
//            {
//              cout << p.path() << '\n';
//            }

//            // Нерекурсивное копирование директории
//            fs::copy("/dir", "/dir_copy");

//            // Рекурсивное копирование директории
//            fs::copy("/dir", "/dir_copy", fs::copy_options::recursive);

//            // Удаление директории со всем содержимым, если она существует
//            fs::remove_all("/dir");

//            // Проверка существования файла
//            if (fs::exists("/dir/file.txt"))
//            {
//              cout << "yes\n";
//            }

//            // Копирование файла
//            fs::copy_file("/dir/file.txt", "/dir/file_copy.txt",
//              fs::copy_options::overwrite_existing);
//            // Получение размера файла (в байтах)
//            uintmax_t size = fs::file_size("/dir/file.txt");

//            // Переименование файла
//            fs::rename("/dir/file.txt", "/dir/file2.txt");

//            // Удаление файла, если он существует
//            fs::remove("/dir/file2.txt");
        }
            ///##std::optional
    };

} // namespace CPP17

#endif // CPP17_DATA_H
