#include "matrix.h"



std::istream& operator>>(std::istream& input_stream, Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            int temp_int = 0;
            input_stream >> temp_int;
            matrix.SetValue(y, x, temp_int);
        }
    }
    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Matrix& matrix)
{
	for (size_t y = 0; y < matrix.GetHeight(); y++)
	{	
		for (size_t x = 0; x < matrix.GetWidth(); x++)
		{
			output_stream << matrix.GetValue(y, x) << " ";
		}
		output_stream << "\n";
	}
	return output_stream;
}

Matrix::Matrix(const size_t height_index, const size_t width_index)
{
	for (size_t i = 0; i < height_index; i++)
	{
		std::vector<int> line;
		for (size_t j = 0; j < width_index; j++)
		{
			line.push_back(0);
		}
		data_.push_back(line);
	}
}

size_t Matrix::GetHeight() const
{
	return data_.size();
}

size_t Matrix::GetWidth() const
{	
	if (data_.size() > 0)
	{
		return data_[0].size();
	}
	else
		return -1;
		
}

int Matrix::GetValue(const size_t height_index, const size_t width_index) const
{
	return data_[height_index][width_index];
}

void Matrix::SetValue(const size_t height_index, const size_t width_index,
	const int value)
{
	data_[height_index][width_index] = value;
}

Matrix Matrix::Transpose() const
{
	Matrix trans(data_[0].size(), data_.size());
	
	for (size_t i = 0; i < trans.GetWidth(); i++)
	{
		for (size_t j = 0; j < trans.GetHeight(); j++)
		{
			trans.SetValue(j, i, data_[i][j]);
		}
	}
	return trans;
}

Matrix Matrix::operator*(const Matrix& rhs)
{
	if (data_[0].size() != rhs.GetHeight())
	{
		std::cout << "You cannot multiple these matrixes!";
		Matrix mn(0, 0);
		return mn;
	}
	Matrix mn(GetHeight(), rhs.GetWidth());

	int x = 0;

	for (size_t i = 0; i < data_.size(); i++)
	{
		for (size_t j = 0; j < rhs.GetWidth(); j++)
		{
			for (size_t k = 0; k < data_[0].size(); k++)
			{
				x = x + data_[i][k] * rhs.GetValue(k, j);
			}
			mn.SetValue(i, j, x);
			x = 0;
		}
	
	}

	return mn;

}