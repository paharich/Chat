#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

map<string, string> knowledge = {  //База вопросов и ответов
    {"hello", "oh, hellow hooman!"}, //{"вопрос", "ответ"}
    {"how are you", "Not too bad for a machine"},
    {"what are you up to", "Ansering stupid question"},
    {"bro", "wow wow wow, HELLOOO"},
};

string exitPhrases[] = { "exit", "bye", "have a good day" };

//Принимает на вход строку и возвращает такую же строку
//только в нижнем регистре
string to_lower(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

void botSay(string text) {
    cout << "[BOT]: " << text << "\n";
}

// Получить вопрос от пользователя
string userQuestion() {
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    question = to_lower(question);
    return question;
}

bool isExit(string text) {
    for (auto phrase : exitPhrases) {
        regex expression = regex(".*" + phrase + ".*");
        if (regex_match(text, expression)) {
            botSay("Ok, byeeee");
            return true; // Да, фраза для выхода
        }
    }
    return false; //Нет, не содержит
}

//Выводит на экран ответ на вопрос question
void botAnswer(string question) {
    bool foundAnswer = false; //Найден ответ?
    for (auto entry : knowledge) { //Для  каждой записи в базе
        //entry.first - вопрос
        //entry.second - ответ
        regex expression = regex(".*" + entry.first + ".*");
        if (regex_match(question, expression)) {
            //Дать ответ
            botSay(entry.second);
            foundAnswer = true;
        }
    }
    if (!foundAnswer) { // Если не найден ответ
        botSay("Do not comperende");
    }
}

int main()
{
    //setlocale(LC_ALL, "rus");
    //cout << "Hellw, Welcome\n";
    //string question;
    cout << "Hello, Welcome to Chatbot\n";

   
    string question; //Объявление переменной, тип+имя

    
    while (!isExit(question)) {// Выполняем код, пока вопрос не содержит фразы для выхода
        question = userQuestion();
        botAnswer(question);
    }

    // Getline - прочитать строчку
    // Из ввода программы (cin) в переменную question

    }