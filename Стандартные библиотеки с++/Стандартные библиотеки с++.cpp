#include <iostream>
#include <vector>
#include <Windows.h>
#include <list>
#include <deque>


//стандартные коллекции языка с++
// категории:
//линейный массив -> std::array, std::vector
// деревья:
//          (бинарное и красно-чёрное) (левый узел всегда меньше своего корня, а правый больше)
//           библиотеки: std::set, std::multi_set(деревья)
//                       std::map, std::multi_map(бинарные)
//                       std::hashtable(хэш таблица-> красночёрные)
//
// связный список (знаем, где первый элемент,
//           но элементы разбиты в разные части памяти, но каждый элемент знает, где находится следующий элемент)
// списки: двусвязные и односвязные (библиотеки: std::list, std::forward_list)
// деревья отрезков ~> (похоже, но не является) std::deque
// графы
// 
// **очереди -> std::queue, std::stack
// 
//

class Test {
public:
    Test() = default;
    Test(int a_val, double b_val) :a(a_val), b(b_val){}

    int a;
    double b;

};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    int start{ 100 };
    int finish{ 99999 };

    std::vector<int> linArr;
    std::list<int> Link_list;
    std::deque<int> Busted_list;

    for (int i = start; i < finish; i++)
    {
        //linArr.push_back(i);
        linArr.insert(linArr.begin(), i);

    }
    for (int i = start; i < finish; i++)
    {
        //Link_list.push_back(i);
        Link_list.insert(Link_list.begin(), i);

    }
    for (int i = start; i < finish; i++)
    {
        //Busted_list.push_back(i);
        Busted_list.insert(Busted_list.begin(), i);
    }

    for (int i = 0; i < linArr.size(); i++) {
        linArr[i] -= 1;
    }

    /*for (int i = 0; i < Link_list.size(); i++) {
        Link_list.at(i) -= 1;
    }*/


    for (int i = 0; i < Busted_list.size(); i++) {
        Busted_list.at(i) -= 1;
    }

    while (linArr.size()) {
        //linArr.pop_back();
        linArr.erase(linArr.begin());

    }

    while (Link_list.size()) {
        //linArr.pop_back();
        Link_list.erase(Link_list.begin());

    }
    while (Busted_list.size()) {
        //linArr.pop_back();
        Busted_list.erase(Busted_list.begin());
    }

    return 0;
}


