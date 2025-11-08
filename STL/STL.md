# 📚 C++ STL (Standard Template Library) Guide – Complete Functions Reference
---

## 🧳 Vector (`<vector>`)

Vectors are dynamic arrays that resize automatically. They offer many functions for element insertion, access, and manipulation.

### Key Functions:

* **`push_back()`**: Adds an element to the end of the vector.
* **`pop_back()`**: Removes the last element of the vector.
* **`size()`**: Returns the number of elements in the vector.
* **`empty()`**: Returns `true` if the vector is empty, `false` otherwise.
* **`resize()`**: Changes the size of the vector.
* **`clear()`**: Removes all elements from the vector.
* **`at()`**: Accesses an element with bounds checking (throws `std::out_of_range` if out of bounds).
* **`front()`**: Accesses the first element of the vector.
* **`back()`**: Accesses the last element of the vector.
* **`begin()`**: Returns an iterator to the first element.
* **`end()`**: Returns an iterator to one past the last element.
* **`insert()`**: Inserts elements at a specified position.
* **`erase()`**: Removes elements at a specified position or range.
* **`emplace_back()`**: Adds an element to the end of the vector, directly constructing it in place.
* **`swap()`**: Swaps the contents of two vectors.

### Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};

    vec.push_back(4);  // Adds 4 to the end of the vector
    vec.erase(vec.begin() + 1);  // Removes element at index 1

    for (auto v : vec) {
        cout << v << " ";  // Output: 1 3 4
    }
}
````

---

## ⚙️ Algorithm (`<algorithm>`)

The `<algorithm>` header contains various algorithms to work with STL containers (including vectors, lists, etc.). It is a versatile library providing everything from sorting to searching.

### Key Functions:

* **`sort()`**: Sorts the elements in a container.
* **`reverse()`**: Reverses the order of elements in the container.
* **`max()`** / **`min()`**: Returns the maximum or minimum of two elements.
* **`find()`**: Finds the first occurrence of an element in the container.
* **`count()`**: Counts the occurrences of an element.
* **`binary_search()`**: Checks if an element exists in a sorted range.
* **`lower_bound()`** / **`upper_bound()`**: Finds the first or last position where a value can be inserted in a sorted container without changing order.
* **`copy()`**: Copies elements from one container to another.
* **`remove()`**: Removes elements with a specific value (works with containers like `std::vector`).

### Example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {5, 3, 8, 6, 2};

    sort(vec.begin(), vec.end());  // Sorts the vector

    if (binary_search(vec.begin(), vec.end(), 5)) {
        cout << "Found 5!" << endl;
    }
}
```

---

## 🏗️ Stack (`<stack>`)

A stack is a LIFO (Last In, First Out) container, which only allows access to the top element.

### Key Functions:

* **`push()`**: Adds an element to the top of the stack.
* **`pop()`**: Removes the top element.
* **`top()`**: Returns a reference to the top element.
* **`empty()`**: Returns `true` if the stack is empty, `false` otherwise.
* **`size()`**: Returns the number of elements in the stack.

### Example:

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);

    cout << stk.top() << endl;  // Output: 3
    stk.pop();
    cout << stk.top() << endl;  // Output: 2
}
```

---

## 🏢 Queue (`<queue>`)

A queue is a FIFO (First In, First Out) container that allows efficient insertion at the back and removal from the front.

### Key Functions:

* **`push()`**: Adds an element to the back of the queue.
* **`pop()`**: Removes the front element.
* **`front()`**: Returns a reference to the front element.
* **`back()`**: Returns a reference to the back element.
* **`empty()`**: Returns `true` if the queue is empty, `false` otherwise.
* **`size()`**: Returns the number of elements in the queue.

### Example:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;  // Output: 1
    q.pop();
    cout << q.front() << endl;  // Output: 2
}
```

---

## 🌀 Deque (`<deque>`)

A deque (double-ended queue) allows fast insertions and deletions from both the front and the back.

### Key Functions:

* **`push_front()`** / **`push_back()`**: Adds an element to the front or back.
* **`pop_front()`** / **`pop_back()`**: Removes an element from the front or back.
* **`front()`**: Accesses the front element.
* **`back()`**: Accesses the back element.
* **`size()`**: Returns the number of elements in the deque.
* **`empty()`**: Returns `true` if the deque is empty, `false` otherwise.
* **`insert()`**: Inserts an element at a specified position.
* **`erase()`**: Removes an element from a specified position.

### Example:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq = {10, 20, 30};
    dq.push_front(5);  // Adds 5 at the front
    dq.push_back(40);  // Adds 40 at the back

    for (auto d : dq) {
        cout << d << " ";  // Output: 5 10 20 30 40
    }
}
```

---

## 📝 List (`<list>`)

A `list` is a doubly linked list, providing efficient insertions and deletions at any point in the sequence.

### Key Functions:

* **`push_front()`** / **`push_back()`**: Adds an element at the front or back.
* **`pop_front()`** / **`pop_back()`**: Removes an element from the front or back.
* **`size()`**: Returns the number of elements in the list.
* **`empty()`**: Returns `true` if the list is empty, `false` otherwise.
* **`insert()`**: Inserts an element at a specific position.
* **`erase()`**: Removes an element at a specific position.
* **`clear()`**: Removes all elements from the list.
* **`front()`**: Returns the first element.
* **`back()`**: Returns the last element.

### Example:

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lst = {1, 2, 3, 4};
    lst.push_front(0);  // Adds 0 at the front
    lst.push_back(5);   // Adds 5 at the back

    for (auto l : lst) {
        cout << l << " ";  // Output: 0 1 2 3 4 5
    }
}
```

---

## 🗺️ Map (`<map>`)

A `map` stores key-value pairs in sorted order based on keys. It automatically handles key uniqueness and sorting.

### Key Functions:

* **`insert()`**: Inserts a key-value pair.
* **`erase()`**: Removes an element by key or by position.
* **`find()`**: Finds an element by key and returns an iterator.
* **`at()`**: Accesses an element by key with bounds checking.
* **`operator[]`**: Accesses or inserts a value by key.
* **`size()`**: Returns the number of elements in the map.
* **`empty()`**: Returns `true` if the map is empty, `false` otherwise.

### Example:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";

    for (auto& p : m) {
        cout <<

