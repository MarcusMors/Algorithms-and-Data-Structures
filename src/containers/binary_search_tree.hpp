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

#include "./node/bin_node.hpp"

namespace fstd {

template<class T> class binary_search_tree
{
public:
  using node_type = bin_node<T>;
  // using size_type = std::size_t;
  using value_type = T;

private:
  // root
  node_type *root{};

public:
  binary_search_tree();
  ~binary_search_tree();
};

binary_search_tree::binary_search_tree() {}

binary_search_tree::~binary_search_tree() {}

}// namespace fstd
