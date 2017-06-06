#include <sstream>

template <typename T>
TMatrix<T>::TMatrix(uint64_t columns, uint64_t rows)
  : col(columns), row(rows)
{
  dataMatrix.assign(col * row, 0);
}
  
template <typename T>
TMatrix<T>::TMatrix()
  : TMatrix(0, 0)
{

}

template <typename T>
std::string TMatrix<T>::printMatrix()
{
  std::stringstream buf;
  
  size_t i = 0;
  for (auto const &x : dataMatrix)
  {
    buf << x << " ";
    if (++i % col == 0)
      buf << std::endl;
  }
  
  return buf.str();
}
