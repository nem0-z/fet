#include <iostream>
#include <functional>
template <typename T>
struct mat
{
public:
    int getRed() const { return red; }
    int getCol() const { return kol; }
    mat(int x, int y) : red{x}, kol{y},
                        pos{new T *[red]}
    {
        for (auto i = 0; i < red; ++i)
            pos[i] = new T[kol];
    }
    void popuni(std::function<T(int, int)> fun)
    {
        for (auto i = 0; i < getRed(); ++i)
        {
            for (auto j = 0; j < getCol(); ++j)
            {
                pos[i][j] = fun(i, j);
            }
        }
    }
    template <typename U>
   friend std::ostream &operator<<(std::ostream &, const mat<U> &);
    ~mat(){
      for(int i = 0; i<red; ++i)
        delete [] pos[i];
      delete [] pos;
    }
private:
    int red{}, kol{};
    T **pos{nullptr};
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, const mat<T> &matrix)
{
    for (auto i = 0; i < matrix.red; ++i)
    {
        stream<<'(';
        for (auto j = 0; j < matrix.kol; ++j)
            stream << matrix.pos[i][j];
        stream << ')' << std::endl;
    }
    return stream;
}

char diag(int i, int j)
{
    if (i == j)
        return 'x';
    else
        return '-';
}

double kolona(int i, int j)
{
    return j;
}

int main(int argc, const char **argv)
{
    mat<char> m1{3, 5};
    mat<double> m2{2, 7};
    m1.popuni(diag);
    m2.popuni(kolona);
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    return 0;
}
