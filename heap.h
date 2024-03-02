#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()): dim(m), cmp(c){}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> tree;
  int dim;
  PComparator cmp;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  
  tree.push_back(item);
  size_t index = tree.size() - 1;
  while (index != 0) {
  size_t parent_index = (index - 1) / dim;
  if (!cmp(tree[index], tree[parent_index])) {
    break;
  }
  std::swap(tree[index], tree[parent_index]);
  index = parent_index;
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return tree.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");
  }
  swap(tree[0], tree.back());
  tree.pop_back();
  size_t index = 0;
  while (index < tree.size()) {
    size_t leftChild = index * dim + 1;
    size_t rightChild = index * dim + dim;
    size_t target = leftChild;
    for (size_t i = leftChild + 1; i <= rightChild && i < tree.size(); ++i) {
      if (cmp(tree[i], tree[target])) {
        target = i;
      }
    }
    if (target < tree.size() && cmp(tree[target], tree[index])) {
      swap(tree[index], tree[target]);
      index = target;
    } 
    else {
      break;
    }
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const 
{
  return tree.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const 
{
  return tree.size();
}



#endif

