#include <iomanip>
#include <sstream>
#include "movie.h"


using namespace std;
Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating) :
  Product("movie", name, price, qty),
	rating_(rating), 
  genre_(genre)
{

}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
{
  std::set<std::string> words = parseStringToWords(name_);
  words.insert(genre_);
  return words;
}

std::string Movie::displayString() const
{
  std::string info = "movie" + name_ + "\n" + to_string(price_) + "\n" + to_string(qty_) + "\n" + genre_ + "\n" + rating_ + "\n";
  return info;
}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ <<endl;
}