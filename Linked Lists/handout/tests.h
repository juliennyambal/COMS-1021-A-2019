#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::find;
using std::vector;
using std::unordered_map;

class Link;

class TestFixture{
public:
    friend void reset_alloc();
    static unordered_map<Link*,bool> allocations;
    static vector<Link*> links;

public:
    TestFixture(){
        allocations[this->getLink()] = true;
        links.push_back(getLink());
    }
    ~TestFixture(){
        allocations[this->getLink()] = false;
        links.erase(find(links.begin(), links.end(), getLink()));
    }
    Link* getLink(){
        return reinterpret_cast<Link*>(this);
    }

    static bool check_memory_leaks(){
        bool out = false;
        for(auto &iter : allocations){
            Link* l = iter.first;
            const bool& alloc = iter.second;
            out |= alloc;
            if(alloc){
                cout << "Memory Leak at " << l << endl;
            }
        }
        return out;
    }

    static bool is_deleted(Link* l){
        auto it = allocations.find(l);
        if(it == allocations.end()){
            throw std::string("Link not allocated correctly");
        }else{
            return !it->second;
        }
    }
};


#endif // TESTS_H
