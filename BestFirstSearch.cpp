//
// Created by renana on 1/7/19.
//

#include "BestFirstSearch.h"

using namespace std;


/*T BestFirstSearch<T>::search(Searchable<T> searchable) {
    State<T> current;
    vector<State<T>> neighbors;
    // Using lambda to compare elements.
    auto cmp = [](State<T> left, State<T> right) { return (left.getCost()) > (right.getCost());};
    priority_queue<State<T>, vector<State<T>>, decltype(cmp)> open(cmp);
    open.push(searchable.getInitialState());

    vector<State<T>> closed;

    while (!open.empty()) {
        current = open.top();
        open.pop();
        if (current.Equals(searchable.getGoalState())) {
            // todo  return get path
        }
        neighbors = searchable.getNeighbors(current);
        for (auto neighbor : neighbors) {
            findInOpen(open, neighbor);
        }
    }




}*/

