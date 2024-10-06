#include <iostream>
#include <cpr/cpr.h>
#include <map>
#include <string>

int main() {
    setlocale(LC_CTYPE, "rus");
    std::map<std::string, std::string> arguments;
    std::string key, value, method;

    while (true) {
        std::cout << "Введите название параметра (или 'get'/'post' для отправки запроса): ";
        std::cin >> key;
        if (key == "get" || key == "post") {
            method = key;
            break;
        }
        std::cout << "Введите значение параметра: ";
        std::cin >> value;
        arguments[key] = value;
    }

    cpr::Response response;

    if (method == "get") {
        cpr::Parameters params{};
        for (const auto& arg : arguments) {
            params.Add({ arg.first, arg.second });
        }
        response = cpr::Get(cpr::Url{ "http://httpbin.org/get" }, params);
    }
    else if (method == "post") {
        cpr::Payload payload{};
        for (const auto& arg : arguments) {
            payload.Add({ arg.first, arg.second });
        }
        response = cpr::Post(cpr::Url{ "http://httpbin.org/post" }, payload);
    }

    std::cout << "Ответ сервера:\n" << response.text << std::endl;

    return 0;
}
