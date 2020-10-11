#include "dna_storage.hpp"

DNAStorage::DNAStorage()
    : size_{0}, mol_{nullptr}
{
}
DNAStorage::DNAStorage(const DNAStorage &other)
    : size_{other.size_},
      mol_{new char[size_]}
{
  std::copy(other.mol_, other.mol_ + size_, mol_);
}
DNAStorage::DNAStorage(DNAStorage &&other)
    : size_{other.size_}, mol_{other.mol_}
{
  other.mol_ = nullptr;
}
DNAStorage &DNAStorage::operator=(const DNAStorage &other)
{
  return *this = DNAStorage{other};
}
DNAStorage &DNAStorage::operator=(DNAStorage &&other)
{
  delete[] mol_;
  size_ = other.size_;
  mol_ = other.mol_;
  other.mol_ = nullptr;
  return *this;
}
DNAStorage::~DNAStorage() { delete[] mol_; }

void DNAStorage::print(std::ostream &stream) const
{
  if (empty())
    throw std::logic_error{"DNA Storage is empty!\n"};
  int pos = 0, i = 0;
  std::string s1{};
  while (i < size_)
  {
    findMols(s1,i);
    if (!s1.empty())
    {
      stream << pos << "-" << i - 1 << ": " << s1 << '\n';
      s1.clear();
    }
    else
    {
    countNulls(i);
    stream << pos << "-" << i - 1 << ": NULL\n";
    }
    pos = i;
  }
}

void DNAStorage::print(std::ostream &stream, int pos, int len) const
{
  if (empty())
    throw std::logic_error{"DNA Storage is empty!\n"};
  if (pos < 0 || len < 0)
    throw std::out_of_range{"Bad index.\n"};
  if (mol_[pos] == 0)
    throw std::logic_error{"Nothing found here.\n"};
  int i = 0;
  int k = pos;
  std::string toPrint{};
  for (; i < len; ++i, ++pos)
  {
    if (mol_[pos] == 0)
      break;
    toPrint.push_back(mol_[pos]);
  }
  stream << k << "-" << k + i - 1 << ": " << toPrint << '\n';
}

void DNAStorage::insert(int pos, std::string lanac)
{
  if (pos < 0)
    throw std::logic_error{"Bad index.\n"};

  int charsToAdd = 0;
  for (const auto &item : lanac)
  {
    if (item == 'A' || item == 'G' || item == 'C' || item == 'T')
      ++charsToAdd;
  } //Count valid inputs - needed for possible new allocation

  if (!charsToAdd)
    return;

  if (charsToAdd > size_ - pos)
    reserve(pos + charsToAdd);

  //We will skip invalid inputs and chain together valid ones
  //example:
  //for input: AGfooTCbarAA 
  //AGTCAA of length 6 will be saved
  for (int i = 0; i < lanac.size(); ++i)
  {
    if (lanac[i] == 'A' || lanac[i] == 'G' || lanac[i] == 'C' || lanac[i] == 'T')
      mol_[pos++] = lanac[i];
    else
      continue;
  }
}

int DNAStorage::remove(int pos, int len)
{
  int charsDeleted = 0;
  if (pos >= size_ || len < 0 || pos < 0)
    throw std::logic_error("Nothing found here.\n");
  for (int i = pos; i < len + pos && i < size_; ++i)
  {
    if (mol_[i] == 0)
      break;
    mol_[i] = 0;
    ++charsDeleted;
  }

  while (size_ > 0 && mol_[size_ - 1] == 0)
    --size_;
  return charsDeleted;
}
void DNAStorage::store(std::string filename)
{
  std::ofstream output(filename);
  int i = 0, pos = 0;
  std::string s1{};
  while (i < size_)
  {
    findMols(s1,i);
    if (!s1.empty())
    {
      output << pos << " " << s1 << '\n';
      s1.clear();
    }
    else
    {
      countNulls(i);
    }
    pos = i;
  }
  output.close();
}
void DNAStorage::load(std::string filename)
{
  std::ifstream input(filename);
  if (!input.is_open())
    throw std::runtime_error("File not found.\n");
  int pos;
  std::string lanac;
  size_ = 0;
  while (input >> pos >> lanac)
  {
    insert(pos, lanac);
  }
  input.close();
}

void DNAStorage::reserve(const int &toReserve)
{
  char *temp = new char[toReserve];
  std::copy(mol_, mol_ + size_, temp);
  delete[] mol_;
  mol_ = temp;
  std::memset(mol_ + size_, 0, toReserve - size_); //Initalize newly allocated memory
  size_ = toReserve;
}

void DNAStorage::findMols(std::string& str, int& counter) const {

    while (mol_[counter] != 0)
    {
      str.push_back(mol_[counter]);
      ++counter;
    }
}

void DNAStorage::countNulls(int& counter) const {
  while(mol_[counter] == 0)
    ++counter;
}
