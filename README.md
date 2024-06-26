# MathWiz

MathWiz - это библиотека для вычисления математических выражений, написанная на C++. Она использует инструменты генерации парсера Bison и Flex для разбора и анализа входных выражений. Библиотека также содержит папку docker, позволяющую настроить среду Docker для последующей сборки и использования библиотеки.

## Сборка и установка

Для сборки MathWiz вам потребуется CMake. Вы можете склонировать репозиторий и выполнить следующие команды:

```bash
git clone git@github.com:Sireth/MathWiz.git
cd MathWiz
mkdir build && cd build
cmake ..
cmake --build .
```

Это сконфигурирует проект с помощью CMake и выполнит сборку библиотеки. После успешной сборки вы можете использовать библиотеку в своем проекте.

## Использование

Для использования MathWiz в вашем проекте, вам нужно будет подключить готовый бинарный файл или добавить MathWiz в ваш проект как зависимость и использовать его API для вычисления математических выражений.

```cpp
#include "Driver.h"
#include "EvalVisitor.h"

int main(){
    mw::Driver driver;
    auto &var_table = driver.variableTable();
    int64_t bar = -12345;

    std::string str = "Helly";

    var_table.setVariable("foo", 1234l);
    var_table.setVariable("bar", &bar);
    var_table.setVariable("help", false);
    var_table.setVariable("str", &str);

    const auto ast = driver.Parse(R"((!(foo < -455 + bar) || str <= "Hello world") && !help)");
    mw::EvalVisitor visitor;

    visitor.visit(ast);
    auto result = visitor.result(); // should be true
    return 0;
}
```

## Docker

Для удобства сборки и развертывания библиотеки MathWiz в Docker, мы предоставляем Dockerfile в папке docker. Вы можете использовать этот Dockerfile для создания контейнера Docker с предустановленными зависимостями и средой для сборки и использования библиотеки.

Подробнее можно узнать в [этом README](./docker/README.md)

## Самостоятельное тестирование

Вы также можете провести тестирование библиотеки MathWiz, создав собственную папку "test" в корне проекта. В этой папке добавьте файл CMakeLists.txt, в котором обязательно должен быть добавлен таргет `test`.

Пример CMakeLists.txt для тестирования:

```cmake
cmake_minimum_required(VERSION 3.5)
project(MathWizTests)

add_executable(test main.cpp)
```

Это позволит вам легко интегрировать библиотеку MathWiz в ваши собственные тесты и убедиться в её корректной работе.


## Лицензия

MathWiz лицензирован под лицензией LGPL. Подробности смотрите в файле LICENSE.

```
Этот README.md включает в себя описание библиотеки, инструкции по сборке и использованию, а также информацию о Docker и лицензии. Пожалуйста, уточните детали и адаптируйте его под вашу библиотеку, если необходимо.
```