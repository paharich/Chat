#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

map<string, string> knowladge = {  //База вопросов и ответов
    {"hello", "oh, hellow hooman!"}, //{"вопрос", "ответ"}
    {"how are you", "Not too bad for a machine"},
    {"what are you up to", "Ansering stupid question"},
};

void bot(string text) {
    cout << "[BOT]: " << text << "\n";
}

// Hello dude, how are you? And by the way what is your name?

void botAnswer(string question) {
    for (auto entry : knowladge) {
        //entry.first - вопрос
        //entry.second - ответ
        regex expression = regex(".*" + entry.first + ".*");
        if (regex_match(question, expression)) {

        }
    }

}

//Принимает на вход строку и возвращает её в нижний регистр
string to_lower(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}


int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Hellw, Welcome\n";

    string question;


    while (question != "exit") {
    getline(cin, question);
    question = to_lower(question); //Получим вопрос от пользователя
    cout << "Yuor question: " << question << "\n";

    botAnswer(question);
       /* if (question == "Hellow") {
            cout << "Helloow, bro\n";
        }

        if (question == "Hi") {
            cout << "Hi, bro\n";
        }
        if (question == "Baka") {
            cout << "Mb you baka, bro\n";
        }*/
    };
}

