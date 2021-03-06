// Copyright (C) 2022 José Enrique Vilca Campana
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <limits>
#include <fstream>

template <typename T>
T bit_number(unsigned bits)
{
	// static_assert(sizeof(T) < bits, "the type isn't able to hold that much bits");
	if (sizeof(T) < bits)
	{
		std::cerr << "the type isn't able to hold " << bits << "bits\n";
		std::cerr << "sizeof(T)\t: " << sizeof(T) << "\n";
		std::cerr << "bits\t\t: " << bits << " \n";
		return 0;
	}
	T n{1};
	for (unsigned i = 0; i <= bits; i++)
	{
		n <<= 1;
	}

	return n;
}
template <typename T>
std::string to_str(const T &number)
{
	std::stringstream ss;
	ss << number;
	std::string str;
	ss >> str;
	return str;
}

int main()
{
	using Seed = std::random_device;
	using Engine = std::default_random_engine;
	// supported int Types // check https://en.cppreference.com/w/cpp/header/random
	// short, int, long, long long,
	// unsigned short, unsigned int, unsigned long, or unsigned long long
	using intType = short;
	using Distribution = std::uniform_int_distribution<intType>;

	Seed seed;
	Engine engine{seed()};
	const intType max = std::numeric_limits<intType>::max();
	const intType min = std::numeric_limits<intType>::min();
	Distribution distribution(min, max);
	auto generate_random_number = [&]()
	{ return distribution(engine); };

	using it_type = unsigned long long;
	const unsigned bits = 4;
	const it_type data_size = bit_number<it_type>(bits);
	// const it_type data_size = std::numeric_limits<it_type>::max();

	std::ofstream out;
	// const std::string file_name = "GD_uniform_distribution__" + to_str(sizeof(intType)) + '-' + to_str(data_size) + ".csv";
	const std::string file_name = "GD_uniform_distribution__" + to_str(sizeof(intType)) + "b-" + to_str(bits) + "b.csv";

	out.open(file_name);

	out << data_size << "\n";
	for (it_type i = 0; i < data_size; i++)
		out << generate_random_number() << ',';

	out.close();

	return 0;
}
