#include <iostream>
#include <vector>

#include "matrix.h"
#include "profile.h"


//#define UNIQ_ID_FINAL(line_number) local_var_##line_number
//#define UNIQ_ID_INTERMEDIATE(line_number) UNIQ_ID_FINAL(line_number)
//#define UNIQ_ID UNIQ_ID_INTERMEDIATE(__LINE__)



/*int main()
{
    //int UNIQ_ID = 123;
    LOG_DURATION("main start");
    int n = 0;
    std::cin >> n;

    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        std::cin >> temp;
        v.push_back(temp);
    }

    int sum = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        sum += v[i];
    }

    std::cout << "Average temperature = " << sum / v.size() << std::endl;


    //std::cout << "Hello! :)" << std::endl;
    //system("pause");
    return 0;
}*/





int main()
{
    int matrix_height = 0;
    int matrix_width = 0;

    std::cin >> matrix_height >> matrix_width;
    Matrix matrix1(matrix_height, matrix_width);
    std::cin >> matrix1;

    std::cin >> matrix_height >> matrix_width;
    Matrix matrix2(matrix_height, matrix_width);
    std::cin >> matrix2;

    Matrix res = matrix1 * matrix2;
    std::cout << res << std::endl;

    return 0;
}

