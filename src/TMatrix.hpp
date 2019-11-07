#ifndef BASIC_MATRIX_T_MATRIX_HH
#define BASIC_MATRIX_T_MATRIX_HH

#include <algorithm>
#include <cstdint>
#include <memory>
#include <sstream>
#include <type_traits>
#include <vector>

template<typename T>
class TMatrix {
public:
    std::string printMatrix();

    void setValue(uint64_t, uint64_t, T);

    T getValue(uint64_t, uint64_t);

    void resize(uint64_t, uint64_t);

    //adding
    template<typename T2>
    TMatrix<T> addMatrix(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> operator+(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> &operator+=(const TMatrix<T2> &);

    //subtracting
    template<typename T2>
    TMatrix<T> subMatrix(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> operator-(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> &operator-=(const TMatrix<T2> &);

    //multiplication
    template<typename T2>
    TMatrix<T> mulMatrix(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> operator*(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> &operator*=(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> mulMatrix(const T2 &);

    template<typename T2>
    TMatrix<T> operator*(const T2 &);

    template<typename T2>
    TMatrix<T> &operator*=(const T2 &);

    //dividing
    template<typename T2>
    TMatrix<T> divMatrix(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> operator/(const TMatrix<T2> &);

    template<typename T2>
    TMatrix<T> &operator/=(const TMatrix<T2> &);

    bool operator==(const TMatrix<T> &);

    // ctr dst
    TMatrix(uint64_t, uint64_t);

    TMatrix();

    ~TMatrix() {};

    TMatrix(const TMatrix<T> &);

    TMatrix<T> &operator=(const TMatrix<T> &);

private:
    std::vector<T> dataMatrix;
    uint64_t col, row;
};

template<typename T>
TMatrix<T>::TMatrix(uint64_t columns, uint64_t rows)
        : col(columns), row(rows) {
    dataMatrix.assign(col * row, 0);
}

template<typename T>
TMatrix<T>::TMatrix()
        : TMatrix(0, 0) {}

template<typename T>
std::string TMatrix<T>::printMatrix() {
    std::stringstream buf;

    size_t i = 0;
    for (auto const &x : dataMatrix) {
        buf << x << " ";
        if (++i % col == 0)
            buf << std::endl;
    }

    return buf.str();
}

template<typename T>
bool TMatrix<T>::operator==(const TMatrix<T> &tm) {
    return col == tm.col &&
           row == tm.row &&
           std::equal(dataMatrix.begin(), dataMatrix.end(), tm.dataMatrix.begin());
}

template<typename T>
void TMatrix<T>::resize(uint64_t columns, uint64_t rows) {
    col = columns;
    row = rows;
    dataMatrix.resize(col * row);
}

template<typename T>
void TMatrix<T>::setValue(uint64_t i, uint64_t j, T t) {
    if (i >= col || j >= row)
        throw std::out_of_range("TMatrix::out_of_range");

    dataMatrix[i + j * col] = t;
}

template<typename T>
T TMatrix<T>::getValue(uint64_t i, uint64_t j) {
    if (i >= col || j >= row)
        throw std::out_of_range("TMatrix::out_of_range");

    return dataMatrix[i + j * col];
}

template<typename T>
TMatrix<T>::TMatrix(const TMatrix<T> &tm) {
    *this = tm;
}

template<typename T>
TMatrix<T> &TMatrix<T>::operator=(const TMatrix<T> &tm) {
    row = tm.row;
    col = tm.col;
    dataMatrix = tm.dataMatrix;
    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, TMatrix<T> &tm) {
    os << tm.printMatrix();
    return os;
}

//adding
template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::addMatrix(const TMatrix<T2> &tm) {
    if (col != tm.col || row != tm.row)
        throw std::runtime_error("TMatrix::adding different sizes of matrix");

    TMatrix<T> resultMatrix(col, row);

    std::transform(
            dataMatrix.begin(),
            dataMatrix.end(),
            tm.dataMatrix.begin(),
            resultMatrix.dataMatrix.begin(),
            [](T a, T2 b) { return a + b; });

    return resultMatrix;
}

template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T2> &tm) {
    return addMatrix(tm);
}

template<typename T>
template<typename T2>
TMatrix<T> &TMatrix<T>::operator+=(const TMatrix<T2> &tm) {
    *this = this->addMatrix(tm);
    return *this;
}

//subtracting
template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::subMatrix(const TMatrix<T2> &tm) {
    if (col != tm.col || row != tm.row)
        throw std::runtime_error("TMatrix::subtracting different sizes of matrix");

    TMatrix<T> resultMatrix(col, row);

    std::transform(
            dataMatrix.begin(),
            dataMatrix.end(),
            tm.dataMatrix.begin(),
            resultMatrix.dataMatrix.begin(),
            [](T a, T2 b) { return a - b; });

    return resultMatrix;
}

template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T2> &tm) {
    return subMatrix(tm);
}

template<typename T>
template<typename T2>
TMatrix<T> &TMatrix<T>::operator-=(const TMatrix<T2> &tm) {
    *this = this->subMatrix(tm);
    return *this;
}

//multiplying
template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::mulMatrix(const TMatrix<T2> &tm) {
    if (row != tm.col)
        throw std::runtime_error("TMatrix::multiplying M1.row != M2.col");

    TMatrix<T> resultMatrix(tm.col, row);

    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < tm.col; j++)
            for (size_t k = 0; k < col; k++) {
                resultMatrix.dataMatrix[i * tm.col + j]
                        += dataMatrix[i * col + k] * tm.dataMatrix[k * row + j];
            }

    return resultMatrix;
}

template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T2> &tm) {
    return mulMatrix(tm);
}

template<typename T>
template<typename T2>
TMatrix<T> &TMatrix<T>::operator*=(const TMatrix<T2> &tm) {
    *this = this->mulMatrix(tm);

    return *this;
}

template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::mulMatrix(const T2 &scalar) {
    auto resultMatrix = *this;

    std::transform(
            dataMatrix.begin(),
            dataMatrix.end(),
            resultMatrix.dataMatrix.begin(),
            [&](T a) { return a * scalar; });

    return resultMatrix;
}

template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::operator*(const T2 &tm) {
    return mulMatrix(tm);
}

template<typename T>
template<typename T2>
TMatrix<T> &TMatrix<T>::operator*=(const T2 &tm) {
    *this = this->mulMatrix(tm);

    return *this;
}

//dividing
template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::divMatrix(const TMatrix<T2> &tm) {
    throw std::runtime_error("TMatrix does not support dividing yet:<");

    return tm;
}

template<typename T>
template<typename T2>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T2> &tm) {
    return divMatrix(tm);
}

template<typename T>
template<typename T2>
TMatrix<T> &TMatrix<T>::operator/=(const TMatrix<T2> &tm) {
    *this = this->divMatrix(tm);
    return *this;
}

#endif // BASIC_MATRIX_T_MATRIX_HH