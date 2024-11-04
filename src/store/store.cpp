#include "item.cpp"
#include <string>
#include <vector>
#include <optional>
#include <stdexcept>

using std::optional;
using std::out_of_range;
using std::string;
using std::vector;

class Store
{
private:
  optional<int> max_itens;
  std::vector<Item> car;

public:
  Store(optional<int> max_itens = 10);
  ~Store() = default;

  void reset()
  {
    max_itens.reset();
    car.clear();
  }

  void *addToCart(Item item)
  {

    if (max_itens && car.size() >= max_itens.value())
    {
      throw std::out_of_range("Cart is full");
    }
    car.push_back(item);
  }

  void removeFromCart(unsigned int index)
  {
    if (index < car.size())
      car.erase(car.begin() + index);
  }

  void removeAllFromCart() { car.clear(); }

  void removeFromCartById(int id)
  {
    for (auto it = car.begin(); it != car.end(); it++)
    {
      if (it->id == id)
      {
        car.erase(it);
        break;
      }
    }
  }
};

Store::Store(optional<int> max_itens = 10) : max_itens(max_itens) {}

Store::~Store()
{
  reset();
}
