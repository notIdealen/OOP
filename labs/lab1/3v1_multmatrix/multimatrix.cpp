#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>

using namespace std;

constexpr int MATRIX_SIZE = 3;
using Matrix3x3 = array<array<double, MATRIX_SIZE>, MATRIX_SIZE>;

void PrintMatrix3x3(const Matrix3x3 &matrix)
{
    for (const auto &row : matrix)
    {
        for (const double& el : row)
            cout << fixed << setprecision(3) << el << "\t";
        cout << endl;
    }
}

Matrix3x3 MulMatrix3x3(const Matrix3x3 &m1, const Matrix3x3 &m2)
{
    Matrix3x3 result{};
    for (size_t i = 0; i < MATRIX_SIZE; ++i)
        for (size_t j = 0; j < MATRIX_SIZE; ++j)
            for (size_t k = 0; k < MATRIX_SIZE; ++k)
                result[i][j] += (m1[i][k] * m2[k][j]);
    return result;
}

void OpenFileForRead(ifstream &file, const string &path)
{
    file.open(path);
    if (!file.is_open())
        throw runtime_error("INVALID path: " + path);
}

void CreateMatrix3x3(istream &file, Matrix3x3 &matrix)
{
    for (size_t i = 0; i < MATRIX_SIZE; ++i)
        for (size_t j = 0; j < MATRIX_SIZE; ++j)
            if (!(file >> matrix[i][j]))
                throw invalid_argument("ERROR");

    if (!file.eof() && file.fail())
        throw runtime_error("INVALID reading");
}

void ReadInput(string &matrix)
{
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            break;
        matrix.append(line).append("\n");
    }
}

void CalculateMatrixFromInput(Matrix3x3 &m1, Matrix3x3 &m2)
{
    string matrix1, matrix2;
    ReadInput(matrix1);
    ReadInput(matrix2);

    stringstream ss;
    // try
    // {
        ss << matrix1;
        CreateMatrix3x3(ss, m1);
        ss << matrix2;
        CreateMatrix3x3(ss, m2);
    // }
    // catch (const std::exception &e)
    // {
    //     throw runtime_error("CalculateMatrixFromInput:" + static_cast<string>(e.what()));
    //     // throw runtime_error(e.what() + "from CalculateMatrixFromInput");
    // }
}

void CalculateMatrixFromFiles(Matrix3x3 &m1, Matrix3x3 &m2, const string &&path1, const string &&path2)
{
    ifstream inF1, inF2;
    // try
    // {
        OpenFileForRead(inF1, path1);
        CreateMatrix3x3(inF1, m1);
        inF1.close();
        OpenFileForRead(inF2, path2);
        CreateMatrix3x3(inF2, m2);
        inF2.close();
    // }
    // catch (const std::exception &e)
    // {
    //     throw runtime_error("CalculateMatrixFromFiles:" + static_cast<string>(e.what()));
    //     // throw runtime_error("CalculateMatrixFromFiles:" + e.what());
    // }
}

int main(int argc, char const *argv[])
{
    Matrix3x3 m1{}, m2{};
    try
    {
        switch (argc)
        {
        case 1:
            CalculateMatrixFromInput(m1, m2);
            break;
        case 3:
            CalculateMatrixFromFiles(m1, m2, argv[1], argv[2]);
            break;
        default:
            cout << "INVALID number of args\n";
            return 0;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return 0;
    }
    Matrix3x3 &&result = MulMatrix3x3(m1, m2);
    PrintMatrix3x3(result);
    return 0;
}
// g++ multimatrix.cpp -o mm.exe
//.\mm.exe data/msimp1.txt data/msimp2.txt
