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

#include <initializer_list>
#include <iostream>

using namespace std;

namespace fstd {

template<typename T> struct deque
{
  deque(std::initializer_list<T> t_arr)
  {
    for (size_t i = 0; i < t_arr.size(); ++i) { arr[i] = *(t_arr.begin() + i); }
  }
  size_t size() const { return sz; }
  T operator[](const size_t &i) { return arr[i]; }
  T operator[](const size_t &i) const { return arr[i]; }

private:
  main;
};

}// namespace fstd
