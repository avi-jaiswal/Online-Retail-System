#include <iomanip>
#include <sstream>
#include "clothing.h"


using namespace std;
Clothing::Clothing(const std::string name, double price, int qty, const std::string clothingSize, const std::string brand) :
  Product("clothing", name, price, qty), 
  brand_(brand),
	size_(clothingSize)

{

}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const
{
	std::set<std::string> brandWords = parseStringToWords(brand_);
  std::set<std::string> nameWords = parseStringToWords(name_);
  std::set<std::string> words = setUnion(nameWords, brandWords);
  return words;
}

std::string Clothing::displayString() const
{
  std::string info = "Clothing" + name_ + "\n" + to_string(price_) + "\n" + to_string(qty_) + "\n" + size_ + "\n" + brand_ + "\n";
  return info;
}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ <<endl;
}