#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linkedlist.h"
#include <vector>
#include <iterator>
#include <ctime>

std::unordered_map<Link*,bool> TestFixture::allocations;
std::vector<Link*> TestFixture::links;

void reset_alloc(){
    TestFixture::allocations = std::unordered_map<Link*,bool>();
    TestFixture::links = std::vector<Link*>();
}
LinkedList *getList(bool dirty = false){
    // Deliberate memory leak to prevent errors in
    // ~LinkedList from crashing the test cases.
    if(dirty){
        throw string("Not implemented yet");
    }else{
        return new LinkedList();
    }
}

vector<int> fill_list(LinkedList *myList, size_t n){
    vector<int> numbers;
    Link* tmp;
    for(size_t i = 0; i < n; ++i){
        numbers.push_back(rand() % 10 + 5);
        tmp = new Link(numbers.back());
        tmp->next = myList->head;
        myList->head = tmp;
        if(i == 0) myList->tail = tmp;
    }
    reverse(numbers.begin(), numbers.end());
    return numbers;
}

TEST_CASE("test0"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A newly allocated list."){
        THEN("Check the constructor initialises members correctly."){
            REQUIRE(myList->head == nullptr);
            REQUIRE(myList->tail == nullptr);
            reset_alloc();
        }
    }
}

TEST_CASE("test1"){
    reset_alloc();
    auto myList = getList();
    int v = rand() % 10;
    myList->head = myList->tail = new Link(v);

    GIVEN("A correct list with 1 item already."){
        THEN("Adding multiple items with push_front"){
            vector<int> numbers;
            numbers.push_back(v);
            int n = rand()%10+5;
            for(int i = 0; i < n; ++i){
                numbers.push_back((rand()%10) + 5);
                myList->push_front(numbers.back());
            }
            n++;
            Link* tmp = myList->head;
            for(int i = 0; i < n; ++i){
                REQUIRE(tmp != nullptr);
                REQUIRE(tmp->value == numbers[n-i-1]);
                tmp = tmp->next;
            }
            REQUIRE(tmp == nullptr);
        }
    }
}

TEST_CASE("test2"){
    reset_alloc();
    auto myList = getList();

    GIVEN("An empty list."){
        THEN("Adding multiple items with push_front"){
            vector<int> numbers;
            int n = rand()%10+5;
            for(int i = 0; i < n; ++i){
                numbers.push_back((rand()%10) + 5);
                myList->push_front(numbers.back());
            }
            Link* tmp = myList->head;
            for(int i = 0; i < n; ++i){
                REQUIRE(tmp != nullptr);
                REQUIRE(tmp->value == numbers[n-i-1]);
                tmp = tmp->next;
            }
            REQUIRE(tmp == nullptr);
        }
    }
}

TEST_CASE("test3"){
    reset_alloc();
    auto myList = getList();
    int v = rand() % 10;
    myList->head = myList->tail = new Link(v);
    Link* correct_tail = myList->tail;

    GIVEN("A correct list with 1 item already."){
        THEN("Adding multiple items with push_front and check tail"){
            vector<int> numbers;
            numbers.push_back(v);
            int n = rand()%10+5;
            for(int i = 0; i < n; ++i){
                numbers.push_back((rand()%10) + 5);
                myList->push_front(numbers.back());
                REQUIRE(myList->tail == correct_tail);
            }
        }
    }
}

TEST_CASE("test4"){
    reset_alloc();
    auto myList = getList();

    GIVEN("An empty list."){
        THEN("Adding multiple items with push_front and check tail"){
            REQUIRE(myList->tail == nullptr);

            vector<int> numbers;
            int n = rand()%10+5;
            for(int i = 0; i < n; ++i){
                numbers.push_back((rand()%10) + 5);
                myList->push_front(numbers.back());
            }

            Link* tmp = myList->head;
            REQUIRE(myList->head != nullptr);
            for(int i = 0; i < n-1; ++i){
                tmp = tmp->next;
            }
            REQUIRE(myList->tail == tmp);
        }
    }
}

TEST_CASE("test5"){
    reset_alloc();
    auto myList = getList();
    int v = rand() % 10;
    myList->head = myList->tail = new Link(v);

    GIVEN("A correct list with 1 item already."){
        THEN("Adding multiple items with push_back"){
            vector<int> numbers;
            numbers.push_back(v);
            int n = rand()%10+5;
            for(int i = 0; i < n; ++i){
                numbers.push_back((rand()%10) + 5);
                myList->push_back(numbers.back());
            }
            n++;
            Link* tmp = myList->head;
            for(int i = 0; i < n; ++i){
                REQUIRE(tmp != nullptr);
                REQUIRE(tmp->value == numbers[i]);
                tmp = tmp->next;
            }
            REQUIRE(tmp == nullptr);
        }
    }
}

TEST_CASE("test6"){
    reset_alloc();
    auto myList = getList();

    GIVEN("An empty list."){
        THEN("Adding multiple items with push_back"){
            vector<int> numbers;
            int n = rand()%10+5;
            for(int i = 0; i < n; ++i){
                numbers.push_back((rand()%10) + 5);
                myList->push_back(numbers.back());
            }
            Link* tmp = myList->head;
            for(int i = 0; i < n; ++i){
                REQUIRE(tmp != nullptr);
                REQUIRE(tmp->value == numbers[i]);
                tmp = tmp->next;
            }
            REQUIRE(tmp == nullptr);
        }
    }
}

TEST_CASE("test7"){
    reset_alloc();
    auto myList = getList();
    int v = rand() % 10;
    myList->head = myList->tail = new Link(v);
    Link* correct_tail = myList->tail;

    GIVEN("A correct list with 1 item already."){
        THEN("Adding multiple items with push_back and check tail"){
            vector<int> numbers;
            numbers.push_back(v);
            int n = rand()%10+5;
            for(int i = 0; i < n; ++i){
                numbers.push_back((rand()%10) + 5);
                myList->push_back(numbers.back());
                correct_tail = TestFixture::links.back();
                REQUIRE(myList->tail == correct_tail);
            }
        }
    }
}

TEST_CASE("test8"){
    reset_alloc();
    auto myList = getList();

    GIVEN("An empty list."){
        THEN("Adding multiple items with push_back and check tail"){
            REQUIRE(myList->tail == nullptr);
            Link* correct_tail = myList->tail;

            vector<int> numbers;
            int n = rand()%10+5;
            for(int i = 0; i < n; ++i){
                numbers.push_back((rand()%10) + 5);
                myList->push_back(numbers.back());
                correct_tail = TestFixture::links.back();
                REQUIRE(myList->tail == correct_tail);
                REQUIRE(myList->tail->value == numbers.back());
            }
        }
    }
}

TEST_CASE("test9"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        vector<int> numbers;
        int n = rand() % 10 + 5;
        for(int i = 0; i < n; ++i){
            numbers.push_back(rand() % 10 + 5);
            Link* tmp = new Link(numbers.back());
            tmp->next = myList->head;
            myList->head = tmp;
        }
        myList->tail = TestFixture::links.back();

        THEN("pop front and check the values are correct"){
            myList->pop_front();
            numbers.pop_back();
            n = numbers.size();

            Link* tmp = myList->head;
            for(int i = 0; i < n; ++i){
                REQUIRE(tmp->value == numbers[n-i-1]);
                tmp = tmp->next;
            }
        }
    }
}

TEST_CASE("test10"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("pop front and check for memory leaks"){
            Link *l = myList->head;
            myList->pop_front();
            REQUIRE(TestFixture::is_deleted(l));
        }
    }
}


TEST_CASE("test11"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("pop front until the list is empty and check the values are correct"){
            while(n > 0){
                myList->pop_front();
                numbers.erase(numbers.begin());
                n = numbers.size();

                Link* tmp = myList->head;
                for(int i = 0; i < n; ++i){
                    REQUIRE(tmp->value == numbers[i]);
                    tmp = tmp->next;
                }
            }
            REQUIRE(myList->tail == nullptr);
            REQUIRE(myList->head == nullptr);
        }
    }
}

TEST_CASE("test12"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("pop back and check the values are correct"){
            myList->pop_back();
            numbers.pop_back();
            n = numbers.size();

            Link* tmp = myList->head;
            for(int i = 0; i < n-1; ++i){
                REQUIRE(tmp->value == numbers[i]);
                tmp = tmp->next;
            }
            int i = n-1;
            REQUIRE(tmp->value == numbers[i]);
            REQUIRE(myList->tail == tmp);
        }
    }
}

TEST_CASE("test13"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("pop back and check for memory leaks"){
            Link *l = myList->tail;
            myList->pop_back();
            REQUIRE(TestFixture::is_deleted(l));
        }
    }
}

TEST_CASE("test14"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("Insert before index 0 and check values"){
            int v = rand() % 10 + 5;
            numbers.insert(numbers.begin(), v);
            myList->insert_at_index(0,v);

            Link* tmp = myList->head;
            for(int i = 0; i < n; ++i){
                REQUIRE(tmp->value == numbers[i]);
                tmp = tmp->next;
            }
        }
    }
}

TEST_CASE("test15"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("Insert midway and check values"){
            int v = rand() % 10 + 5;
            int i = n / 2;
            numbers.insert(numbers.begin() + i, v);
            myList->insert_at_index(i,v);

            Link* tmp = myList->head;
            for(int i = 0; i < n; ++i){
                REQUIRE(tmp->value == numbers[i]);
                tmp = tmp->next;
            }
        }
    }
}

TEST_CASE("test16"){
    reset_alloc();
    auto myList = getList();
    GIVEN("An empty list"){
        THEN("Insert at index 0 and check values"){
            int v = rand() % 10 + 5;
            myList->insert_at_index(0,v);
            REQUIRE(myList->head != nullptr);
            REQUIRE(myList->head->value == v);
            REQUIRE(myList->head == myList->tail);
        }
    }
}

TEST_CASE("test17"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("Remove index 0, check values and memory leaks"){
            Link* l = TestFixture::links.back();

            numbers.erase(numbers.begin());
            myList->remove_at_index(0);

            Link* tmp = myList->head;
            for(int i = 0; i < n-2; ++i){
                REQUIRE(tmp->value == numbers[i]);
                tmp = tmp->next;
            }
            REQUIRE(tmp->value == numbers.back());
            REQUIRE(tmp->next == nullptr);
            REQUIRE(tmp == myList->tail);
            REQUIRE(TestFixture::is_deleted(l));
        }
    }
}

TEST_CASE("test18"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with 1 item in it already"){
        int n = 1;
        vector<int> numbers = fill_list(myList, n);

        THEN("Remove index 0, check values and memory leaks"){
            Link* l = TestFixture::links.back();

            numbers.erase(numbers.begin());
            myList->remove_at_index(0);

            REQUIRE(myList->head == nullptr);
            REQUIRE(myList->tail == nullptr);
            REQUIRE(TestFixture::is_deleted(l));
        }
    }
}

TEST_CASE("test19"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("Delete midway and check values"){
            int i = n / 2;
            Link* l = TestFixture::links[n-i-1];
            numbers.erase(numbers.begin() + i);
            myList->remove_at_index(i);

            Link* tmp = myList->head;
            for(int i = 0; i < n-2; ++i){
                REQUIRE(tmp->value == numbers[i]);
                tmp = tmp->next;
            }
            REQUIRE(tmp->value == numbers.back());
            REQUIRE(tmp->next == nullptr);
            REQUIRE(tmp == myList->tail);
            REQUIRE(TestFixture::is_deleted(l));
        }
    }
}

TEST_CASE("test20"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);

        THEN("Delete at the back, check values and tail"){
            Link* l = TestFixture::links[0];
            numbers.erase(numbers.begin() + n-1);
            myList->remove_at_index(n-1);

            Link* tmp = myList->head;
            for(int i = 0; i < n-2; ++i){
                REQUIRE(tmp->value == numbers[i]);
                tmp = tmp->next;
            }
            REQUIRE(tmp->value == numbers.back());
            REQUIRE(tmp->next == nullptr);
            REQUIRE(tmp == myList->tail);
            REQUIRE(TestFixture::is_deleted(l));
        }
    }
}

TEST_CASE("test21"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);
        THEN("Reverse the list and check the values"){
            myList->reverse();
            std::reverse(numbers.begin(), numbers.end());
            Link* curr = myList->head;
            for(int i : numbers){
                REQUIRE(curr->value == i);
                curr = curr->next;
            }
        }
    }
}

TEST_CASE("test22"){
    reset_alloc();
    auto myList = getList();
    GIVEN("A list with items in it already"){
        int n = rand() % 10 + 5;
        vector<int> numbers = fill_list(myList, n);
        THEN("Reverse the list and check the pointers were swapped"){
            Link* old_head = myList->head;
            Link* old_tail = myList->tail;
            myList->reverse();
            REQUIRE(myList->head == old_tail);
            REQUIRE(myList->tail == old_head);

            vector<Link*> links = TestFixture::links;
            std::reverse(numbers.begin(), numbers.end());
            Link* curr = myList->head;
            for(int i = 0; i < n; ++i){
                REQUIRE(curr->value == numbers[i]);
                REQUIRE(curr == links[i]);
                curr = curr->next;
            }
        }
    }
}

TEST_CASE("test23"){
    reset_alloc();
    vector<int> numbers1, numbers2;

    auto myList1 = getList();
    auto myList2 = getList();

    GIVEN("Two sorted linked lists."){
        THEN("Return a new list containing the sorted union of the two lists."){
            srand(time(nullptr));
            auto printer= [](std::string label, vector<int> &vec){
                cout << label << ": [";
                copy(vec.begin(), vec.end()-1, std::ostream_iterator<int>(std::cout, ","));
                cout << vec.back() << "]" << endl;
            };

            vector<int> un, nums1, nums2;
            int n1 = (rand() % 20) + 10;

            int base = 0;
            for(int i = 0; i < n1; ++i){
                int offset = (rand() % 30) + 1;
                base += offset;

                int choice = rand() % 3;
                if(choice == 0){
                    // Both
                    un.push_back(base);
                    nums1.push_back(base);
                    nums2.push_back(base);
                    myList1->push_back(base);
                    myList2->push_back(base);
                }else if(choice == 1){
                    // N1 only
                    myList1->push_back(base);
                    nums1.push_back(base);
                    un.push_back(base);
                }else{
                    // N2 only
                    myList2->push_back(base);
                    nums2.push_back(base);
                    un.push_back(base);
                }
            }
            printer("List1", nums1);
            printer("List2", nums2);
            auto output = list_union(*myList1, *myList2);

            Link* l = output->head;
            for(size_t i = 0; i < un.size(); ++i){
                REQUIRE(l != nullptr);
                REQUIRE(l->value == un[i]);
                l = l->next;
            }
            REQUIRE(l == nullptr);
        }
    }

    GIVEN("Two sorted linked lists."){
        THEN("Return a new list containing the sorted union of the two lists."){
            srand(time(nullptr));
            auto printer= [](std::string label, vector<int> &vec){
                cout << label << ": [";
                copy(vec.begin(), vec.end()-1, std::ostream_iterator<int>(std::cout, ","));
                cout << vec.back() << "]" << endl;
            };

            vector<int> un, nums1, nums2;
            int n1 = (rand() % 20) + 10;

            int base = 0;
            for(int i = 0; i < n1; ++i){
                int offset = (rand() % 30) + 1;
                base += offset;

                int choice = rand() % 3;
                if(i == n1/2){
                    un.push_back(base);
                    nums1.push_back(base);
                    nums1.push_back(base);
                    nums2.push_back(base);
                    myList1->push_back(base);
                    myList1->push_back(base);
                    myList2->push_back(base);
                }else if(choice == 0){
                    // Both
                    un.push_back(base);
                    nums1.push_back(base);
                    nums2.push_back(base);
                    myList1->push_back(base);
                    myList2->push_back(base);
                }else if(choice == 1){
                    // N1 only
                    myList1->push_back(base);
                    nums1.push_back(base);
                    un.push_back(base);
                }else{
                    // N2 only
                    myList2->push_back(base);
                    nums2.push_back(base);
                    un.push_back(base);
                }
            }
            printer("List1", nums1);
            printer("List2", nums2);
            auto output = list_union(*myList1, *myList2);

            Link* l = output->head;
            for(size_t i = 0; i < un.size(); ++i){
                REQUIRE(l != nullptr);
                REQUIRE(l->value == un[i]);
                l = l->next;
            }
            REQUIRE(l == nullptr);
        }
    }
}
