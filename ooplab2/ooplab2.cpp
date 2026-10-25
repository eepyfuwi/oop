

#include "ooplab2.h"
#include "cstr.h"

using namespace std;

int main()
{
	srand(time(0));
    setlocale(LC_ALL, "Russian");
    Cstr str1;
    std::cout << "1. Случайная строка (по умолчанию): " << str1 << " (длина: " << str1.len() << ")\n";

    // Пункт 3: Конструктор от си-строки
    Cstr str2("Hello");
    std::cout << "2. Строка из C-строки: " << str2 << "\n";

    // Пункт 4: Конструктор с длиной
    Cstr str3(10);
    std::cout << "3. Случайная строка длиной 10: " << str3 << "\n";

    // Пункт 5: Конструктор копирования
    Cstr str4(str2);
    std::cout << "4. Копия str2: " << str4 << "\n";

    // Пункт 7: Присваивание объекта
    str1 = str2;
    std::cout << "5. str1 = str2: " << str1 << "\n";

    // Пункт 8: Присваивание си-строки
    str1 = "World";
    std::cout << "6. str1 = 'World': " << str1 << "\n";

    // Пункт 9: Сравнение
    std::cout << "7. 'Hello' > 'World'? " << (str2 > str1 ? "Да" : "Нет") << "\n";

    // Пункт 10: Конкатенация
    Cstr str5 = str2 + str1;
    std::cout << "8. 'Hello' + 'World' = " << str5 << "\n";
    str2 += str1;
    std::cout << "   str2 += str1: " << str2 << "\n";

    // Пункт 11: Индексация
    std::cout << "9. str5[0] = '" << str5[0] << "'\n";
    str5[0] = 'h';
    std::cout << "   После str5[0] = 'h': " << str5 << "\n";

    // Пункт 14: Ввод
    std::cout << "\n10. Введите строку (до 20 символов): ";
    std::cin >> str5;
    std::cout << "Вы ввели: " << str5 << " (длина: " << str5.len() << ")\n";
}
