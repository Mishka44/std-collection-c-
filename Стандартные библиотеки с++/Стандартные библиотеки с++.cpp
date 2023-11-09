#include <iostream>
#include <vector>
#include <Windows.h>
#include <list>
#include <random>
#include<set>
#include <map>
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

    std::random_device rd;
    std::mt19937 distr{ rd() };
    std::uniform_int_distribution<int> prov(-10, 50);

    int start{1};
    int finish{19};

    std::vector<int> linArr;
    std::list<int> Link_list;
    std::deque<int> Busted_list;

    for (int i = start; i < finish; i++)
    {
        //linArr.push_back(i);
        linArr.insert(linArr.begin(), prov(distr));

    }
    for (int i = start; i < finish; i++)
    {
        //Link_list.push_back(i);
        Link_list.insert(Link_list.begin(), prov(distr));

    }
    for (int i = start; i < finish; i++)
    {
        //Busted_list.push_back(i);
        Busted_list.insert(Busted_list.begin(), prov(distr));
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

    /*for (auto &el : linArr) {
        el = 0;
    }
    std::cout << "\n";

    for (auto &el : Link_list) {
        el = 0;
    }
    std::cout << "\n";

    for (auto &el : Busted_list) {
        el = 0;
    }
    std::cout << "\n";*/

    std::vector<int> uniq;
    for (auto el : Busted_list) {
        bool flag{ true };
        for (auto el_uniq : uniq) {
            if (el == el_uniq) {
                flag = false;
                break;
            }
        }
        if (flag) {
            uniq.push_back(el);
        }
    }
    for (auto el : linArr) {
        bool flag{ true };
        for (auto el_uniq : uniq) {
            if (el == el_uniq) {
                flag = false;
                break;
            }
        }
        if (flag) {
            uniq.push_back(el);
        }
    }
    for (auto el : Link_list) {
        bool flag{ true };
        for (auto el_uniq : uniq) {
            if (el == el_uniq) {
                flag = false;
                break;
            }
        }
        if (flag) {
            uniq.push_back(el);
        }
    }


    


    std::cout << uniq.size() << " unique:\n";
    for (auto el_uniq : uniq) {
        std::cout << el_uniq<< ' ';
    }
    std::cout << "\n";


    //_____________________________
    std::set<int> unique;
    for (auto el : Link_list) { unique.insert(el); }
    for (auto el : linArr) { unique.insert(el); }
    for (auto el : Busted_list) { unique.insert(el); }
    std::cout << uniq.size() << " unique:\n";
    for (auto el_uniq : unique) {
        std::cout << el_uniq << ' ';
    }
    std::cout << "\n";



    {
        for (auto it = linArr.begin(); it != linArr.end(); ++it) {
            *it  += 2;
        }
    }

    {
        for (auto it = Link_list.begin(); it != Link_list.end(); ++it) {
            *it += 2;
        }
    }

    {
        for (auto it = Busted_list.begin(); it != Busted_list.end(); ++it) {
            *it += 2;
        }
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

    /*std::string Cat;
    std::cin >> Cat;

    std::cout << Cat;*/



    return 0;
}


