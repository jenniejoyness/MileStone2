#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "StringReverser.h"
#include "State.h"
#include "BestFirstSearch.h"
using namespace std;

#include <queue>
int main() {
    std::cout << "Hello, World!" << std::endl;
    /*MySerialServer* d = new MySerialServer;
    Solver<string,string>* solver = new StringReverser();
    FileCacheManager* fileCacheManager = new FileCacheManager();
    ClientHandler* ds = new MyTestClientHandler(solver, fileCacheManager);
    d->open(5400,ds);*/

    // Using lambda to compare elements.
  //  auto cmp = [](State<int> left, State<int> right) { return (left.getCost()) > (right.getCost());};
    //priority_queue<State<int>, vector<State<int>>, decltype(cmp)> p(cmp);

    /*BestFirstSearch<int>* bestFirstSearch = new BestFirstSearch<int>();
    Searchable<int> searchable;
    bestFirstSearch->search(searchable);*/
    class Comp {
    public:
        bool operator () (State<int> left, State<int> right) {
            return (left.getCost()) > (right.getCost());
        }
    };

    priority_queue<State<int>, vector<State<int>>,Comp> p;

    p.push(State<int>(8, 3));
    p.push(State<int>(7, 2));
    p.push(State<int>(1, 2));
    p.push(State<int>(10, 5));
    cout << p.top().getCost() << endl;
    p.pop();
    cout << p.top().getCost() << endl;
    p.pop();
    cout << p.top().getCost() << endl;
    p.pop();
    cout << p.top().getCost() << endl;
    p.pop();

   // priority_queue<State<int>, vector<State<int>>, greater<>> pq;
    while(true){}
    return 0;
}