#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Фцнкция для вывода всех студенов из базы данных в алфавитном порядке
void displayStudentsInAlphabetOrder(const std::vector<Student>& database) {
    std::vector<Student> right_database = database;
    std::cout << "Список студентов:\n"; \
        int size = right_database.size() - 1;
    for (int step = 0; step < size; ++step) {
        for (int i = 0; i < size - step; ++i) {
            if (right_database[i].name > right_database[i + 1].name) {
                std::string temp = right_database[i].name;
                right_database[i].name = right_database[i + 1].name;
                right_database[i + 1].name = temp;
            }
        }
    }
    displayStudents(right_database);
}

// Пробный тест функции
void testFunction1(std::vector<Student>& database) {
    
    Student student;

   
    student.name = "владлен";
    student.age = 0;
    student.major = "марксист";
    student.gpa = 1;
    database.push_back(student);

    student.name = "владимир";
    student.age = 70;
    student.major = "политик";
    student.gpa = 3;
    database.push_back(student);

  



    displayStudentsInAlphabetOrder(database);
}
// Тест на несколько слов со схожими первыми буквами
void testFunction2(std::vector<Student>& database) {
    Student student;
    student.name = "катамаран";

    database.push_back(student);

    student.name = "катафалк";
    database.push_back(student);

    student.name = "картон";
    database.push_back(student);
    displayStudentsInAlphabetOrder(database);
}

// Тест на добавление слов в обратном алфавитном порядке
void testFunction3(std::vector<Student>& database) {
    Student student;
    student.name = "ярило";
    database.push_back(student);

    student.name = "орило";
    database.push_back(student);

    student.name = "антон";
    database.push_back(student);
    displayStudentsInAlphabetOrder(database);
}

// Тест на добавление двух одинаковых и одного отличного имени
void testFunction4(std::vector<Student>& database) {
    Student student;
    student.name = "киря";
    database.push_back(student);

    student.name = "тоха";
    database.push_back(student);

    student.name = "киря";
    database.push_back(student);

    displayStudentsInAlphabetOrder(database);
}

// Тест на добавление разных имен
void testFunction5(std::vector<Student>& database) {
    Student student;
    student.name = "киря";
    database.push_back(student);

    student.name = "тоха";
    database.push_back(student);

    student.name = "мотя";
    database.push_back(student);
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "17. Вывести список студентов в алвафитном порядке\n";
        std::cout << "4. Тестик\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addStudent(database);
            break;
        case 2:
            displayStudents(database);
            break;
        case 17:
            displayStudentsInAlphabetOrder(database);
            break;
        case 4:
            testFunction3(database);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
