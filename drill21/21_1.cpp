#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;
//1.feladat
struct Item {
    string name;
    int iid;
    double value;
    Item() : name("unknown"), iid(-1), value(0) {}
    Item(string n, int id, double v) : name(n), iid(id), value(v) {}
};
//operatortulterheles
ostream& operator<<(ostream& os, const Item& item) {
    return os << "{ " << item.name << " " << item.iid << " " << item.value << " }" << std::endl;
}

istream& operator>>(istream& is, Item& item) {
    char dummy;
    is >> dummy;
    if (dummy != '{') {
        is.unget();
        return is;
    }
    is >> item.name >> item.iid >> item.value;
    return is;
}
//sortokhoz tartozo structok
struct by_name {
    bool operator()(const Item& a, const Item& b) const {
        return a.name < b.name;
    }
};

struct by_id {
    bool operator()(const Item& a, const Item& b) const {
        return a.iid < b.iid;
    }
};

struct by_value {
    bool operator()(const Item& a, const Item& b) const {
        return a.value > b.value;
    }
};

int main()
try { 

    //1. feladat masodik fele
    vector<Item> vi;
    ifstream fileIn {"data.txt"};
    for (int i = 0; i < 10; i++) {
        Item item;
        fileIn >> item;
        vi.push_back(item);
    }

    // 2,3,4 feladatok
    std::sort(vi.begin(), vi.end(), by_name());

    std::sort(vi.begin(), vi.end(), by_id());

    std::sort(vi.begin(), vi.end(), by_value());
    //5 feladat
    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});

    //6 feladat
    vi.erase(std::remove_if(vi.begin(), vi.end(), [](const Item& item) { return item.name == "apple" || item.name == "banana"; }));

    vi.erase(std::remove_if(vi.begin(), vi.end(), [](const Item& item) { return item.iid == 10 || item.iid == 12; }));
    //7. feladat listával ugyan ezek csak list szerint

    list<Item> li;
    std::copy(vi.begin(), vi.end(), li.begin());

    // sort by név, id, érték
    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });

    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });

    li.sort([](const Item& a, const Item& b) { return a.value < b.value; });

//pushback

    li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});

    //remove

    li.remove_if([](const Item& item) { return item.name == "apple" || item.name == "banana"; });
    
    li.remove_if([](const Item& item) { return item.iid == 10 || item.iid == 12; });
    
}catch(std::exception & e){

    std::cerr<<"Exception: " << e.what() << std::endl;
    return 1;

}catch(...){

    std::cerr << "Unknown exception\n";
    return 2;

}
