#include <iostream>
#include <chrono>
#include <format>
#include <string>
#include <vector>
#include <thread>
#include <cstdlib>


using namespace std;


/*void sum1(int katB, int& katA, int& katC);
void checkcategory1(string catName, int minAge, int userAge);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int vozract_B, vozract_vodiya;
    int katA = 0, katC = 0;

    cout << "Минимальный возраст для категории B: ";
    cin >> vozract_B;

    cout << "Введите ваш возраст: ";
    cin >> vozract_vodiya;

   
    sum1(vozract_B, katA, katC);

    checkcategory1("A", katA, vozract_vodiya);
    checkcategory1("B", vozract_B, vozract_vodiya);
    checkcategory1("C", katC, vozract_vodiya);

    return 0;
}


void sum1(int katB, int& katA, int& katC)
{
    katA = katB - 2;
    katC = katB + 3;
}


void checkcategory1(string catName, int minAge, int userAge)
{
    cout << "Категория " << catName << " (" << minAge << " лет): ";

    if (userAge >= minAge) {
        cout << "Вы можете получить права!\n";
    }
    else {
        int octaloc = minAge - userAge;
        if (octaloc == 1) {
            cout << "Вам остался " << octaloc << " год для получения прав\n";
        }
        else if (octaloc <= 4) {
            cout << "Вам осталось " << octaloc << " года для получения прав\n";
        }
        else {
            cout << "Вам осталось " << octaloc << " лет для получения прав\n";
        }
    }
}*/

//int main()
//{
    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    int a = rand() % 10 + 1;
    int vash;
    bool g = true;
    int b = 0;
   
    do  {
        b++;
        auto now = std::chrono::system_clock::now();
        std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
        cout << "Ваше число: ";
        cin >> vash;
        if (vash > a) {
            cout << "Ваше число больше: " << a << endl;
        }
        else if (vash < a) {
            cout << "Ваше число Меньше: " << a << endl;
        }
        else  {
            cout << "Ваше число ==: " << a << endl;
            cout << "Вы угадали за  " << b << " Попыток" << endl;
            auto now = std::chrono::system_clock::now();
            std::cout << now << std::endl;
            g = false;
        }
        
        
    } while (g);
    std::this_thread::sleep_for(std::chrono::seconds(20));
    

    return 0;*/
//}
struct Lesson {
    std::string day;
    std::string time;
    std::string ccilka;
    bool opened = false;

};

int main()
{
    setlocale(LC_ALL, "Russian");
    //if(//время == 6:30){
    //запускаем std::system(xdg-open "ccilka")
    //else if () {}
    std::vector<Lesson> timetable = {
      {"Monday", "08:30", "https://zoom.us1"},
      {"Monday", "10:15", "https://zoom.us2"},
      {"Tuesday", "08:30", "https://zoom.us3"},
      {"Wednesday", "12:00", "https://zoom.us4"}

    };
    
    
    while (true) {
        auto now = std::chrono::system_clock::now();
        auto local = std::chrono::zoned_time{ std::chrono::current_zone(), now };
        std::string time_str = std::format("{:%R}", local);
        std::string day_str = std::format("{:%A}", local);
       
        for (auto& lesson : timetable) {
            if (day_str == lesson.day && time_str == lesson.time && !lesson.opened) {
                std::string command = "xdg-open " + lesson.ccilka;
                std::system(command.c_str());
                lesson.opened = true;
            }
            if (time_str <= "17::00") {
                std::cout << "1";
                    break;

            }

        }

     
        
       
        
       
        
    }
}
     
    
    
   
   



   
    

        
 
    
    

 
    
    
   



    












