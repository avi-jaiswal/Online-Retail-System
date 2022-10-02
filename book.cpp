#include <iomanip>
#include <sstream>
#include "book.h"


using namespace std;
Book::Book(const std::string name, double price, int qty, const std::string ISBN, const std::string author):
  Product("book", name, price, qty), 
  author_(author),
	isbn_(ISBN)
{

}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
	std::set<std::string> authorWords = parseStringToWords(author_);
  std::set<std::string> nameWords = parseStringToWords(name_);
  std::set<std::string> words = setUnion(nameWords, authorWords);
  words.insert(isbn_);
  return words;
}

std::string Book::displayString() const
{
  std::string info = "Book" + name_ + "\n" + to_string(price_) + "\n" + to_string(qty_) + "\n" + isbn_ + "\n" + author_ + "\n";
  return info;
}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ <<endl;
}