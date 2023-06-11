#include "admin.h"
#include "anonymous_user.h"     // подключаем все необходимые файлы

using namespace std;

void desk_loop();

unsigned int HashFunc(string); // ПАРОЛЬ УЧЁТКИ АДМИНА - Ksenia1234228
void show_head();       // функция вывода шапки с текущей датой и временем, а так же разработчиком и руководителем

int main()
{
    setlocale(LC_ALL, "Russian");   // подключаем русский язык      // русификация консоли на вывод

    desk_loop();    // запускаем цикл обработки запросов

    system("pause");
    return 0;
}

void desk_loop()
{
    string entered_pass;
    unsigned int Hash_of_pass;
    ifstream ifs("admin_data.txt");
    ifs >> Hash_of_pass;

    bool isProcess = true, isExit = false;
    int choice;
    do
    {
        show_head();
        cout << "Для завершения программы нажмите 'Q'\nВыберите режим входа:\n1)Администратор\n2)Анонимный пользователь\n\n";
        cin >> choice;      // выбираем режим входа: админ либо пользователь

        switch (choice)
        {
        case 1:     // режим админа
            do
            {
                system("pause");
                system("cls");
                show_head();
                while (cin.get() != '\n');
                cout << "Введите пароль учётной записи администратора: ";
                getline(cin, entered_pass);
                if (HashFunc(entered_pass) != Hash_of_pass)     // если введенный пароль не соответсвует настоящему, то не пускаем дальше
                {
                    cout << "Введён неверный пароль учётной записи администратора!\n\n";
                    system("pause");
                    system("cls");
                    break;
                }

                isProcess = true;
                try
                {
                    admin adm;
                Lobby_adm:
                    system("pause");
                    system("cls");

                    show_head();        // выбираем операцию над таблицей рейсов
                    cout << "1)Показать спиcок рейсов\n2)Добавить новый рейс\n3)Удалить существующий рейс\n" <<
                        "4)Сортировка по значению\n5)Поиск по значению\n6)Вернуться назад\n\n";
                    cin >> choice;
                    system("pause");

                    switch (choice)
                    {
                    case 1:
                        system("cls");      // показать таблицы рейсов
                        show_head();
                        adm.show_flight_table();
                        goto Lobby_adm;
                        break;
                    case 2:
                        system("cls");  // создать новый рейс и записать его в таблицу
                        show_head();
                        adm.insert_new_flight();
                        goto Lobby_adm;
                        break;
                    case 3:
                        system("cls");  // удаление конкретного выбранного рейса
                        show_head();
                        adm.show_flight_table();
                        adm.remove_chosen_flight();
                        goto Lobby_adm;
                        break;
                    case 4:
                        system("cls");
                        show_head();
                        adm.choosen_parameter_sorting();
                        adm.show_flight_table();
                        goto Lobby_adm;
                        break;
                    case 5:
                        system("cls");
                        show_head();
                        adm.choosen_parameter_searching();
                        goto Lobby_adm;
                        break;
                    default: isProcess = false; system("cls");
                    }
                    }
                catch (bad_opened_file& bof)    // в случае, если файл flight_table.txt был удален, то мы получим исключение с выводом того что произошло на экран консоли
                {
                    cout << bof.what() << endl;
                }
                } while (isProcess);
            break;
            
          case 2:       // режим пользователя
            do
            {
                isProcess = true;
                try
                {
                    anonymous_user user;

                Lobby_us:
                    system("pause");        
                    system("cls");
                    show_head();
                    cout << "1)Показать спиcок рейсов\n2)Купить билет на рейс\n3)Купить несколько билетов (индивид. задание согласно варианту)\n"
                         "4)Сортировка по значению\n5)Поиск по значению\n6)Вернуться назад\n\n";
                    cin >> choice;  // выбираем необходимую операцию пользователя

                    system("pause");

                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        show_head();
                        user.show_flight_table();   // вывод таблицы всех возможных рейсов
                        goto Lobby_us;
                        break;
                    case 2:
                        system("cls");
                        show_head();
                        user.buy_ticket();  // покупка 1 билета на указанный рейс
                        goto Lobby_us;
                        break;
                    case 3:
                        system("cls");
                        show_head();
                        user.personal_task();   // индивидуальное задание по варианту: покупка нескольких билетов на указанный рейс
                        goto Lobby_us;
                        break;
                    case 4:
                        system("cls");
                        show_head();
                        user.choosen_parameter_sorting();
                        user.show_flight_table();
                        goto Lobby_us;
                        break;
                    case 5:
                        system("cls");
                        show_head();
                        user.choosen_parameter_searching();
                        goto Lobby_us;
                        break;
                    default: isProcess = false; system("cls");
                    }
                }
                catch (bad_opened_file& bof) // в случае, если файл flight_table.txt был удален, то мы получим исключение с выводом того что произошло на экран консоли
                {
                    cout << bof.what() << endl;
                }
            } while (isProcess);
            break; 
        default: isExit = true; break;
        }
    } while (!isExit);
}

unsigned int HashFunc(string input)     // функция хеширования переданной строки input (в нашему случае хеширует пароль). просто магия, черный ящик, не более
{
    unsigned int Init = 124564352;
    unsigned int Magic = 5674356;
    unsigned int Hash = Init;
    for (size_t i(0); i < input.length(); ++i)
    {
        Hash = Hash ^ (input[i]);
        Hash = Hash * Magic;
    }
    return Hash;
}

void show_head()     // функция вывода "шапки" программы с ин-цией о разработчике , руководителе, с выводом времени и т.д.
{
    time_t now;
    std::tm nowLocal;

    now = time(NULL);
    localtime_s(&nowLocal, &now);

    std::cout << "=======================================================================================================================" << std::endl;
    std::cout << "\t\t\t\t\t      " << nowLocal.tm_mday << '.' << nowLocal.tm_mon + 1 << '.' << nowLocal.tm_year + 1900 << std::endl;
    std::cout << "\t\t\t\t\t\t" << nowLocal.tm_hour << ':' << nowLocal.tm_min << std::endl;
    std::cout << "=======================================================================================================================\n";
    std::cout << "\t\t\t\tРазработала: Рабкова Ксения Алексеевна, гр. 113871\n\t\t\t\t\tРуководитель: Рыбак Виктор Александрович\n\t\t\t\t\t\t© 2022" << std::endl;
    std::cout << "=======================================================================================================================\n\n\n";
}


