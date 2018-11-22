//-----------------------------------------------------------------------------
// Copyright (c) 2018 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#include <io_tools/io_std_array.hpp>

#include <sstream>
#include <string>

#include "gtest/gtest.h"


namespace{


	using namespace ::io_tools::io_std_array;


}


TEST(io_std_array, output_char_1){
	std::array< int, 1 > array{{1}};

	std::ostringstream os;
	os << array;

	EXPECT_TRUE(os);
	EXPECT_EQ(os.str(), "{1}");
}

TEST(io_std_array, output_char_2){
	std::array< int, 2 > array{{1, 2}};

	std::ostringstream os;
	os << array;

	EXPECT_TRUE(os);
	EXPECT_EQ(os.str(), "{1,2}");
}

TEST(io_std_array, output_char_3){
	std::array< int, 3 > array{{1, 2, 3}};

	std::ostringstream os;
	os << array;

	EXPECT_TRUE(os);
	EXPECT_EQ(os.str(), "{1,2,3}");
}


TEST(io_std_array, input_char_1){
	std::array< int, 1 > array{};

	std::istringstream is("{1}");
	is >> array;

	EXPECT_TRUE(is);
	EXPECT_EQ(array[0], 1);
}

TEST(io_std_array, input_char_2){
	std::array< int, 2 > array{};

	std::istringstream is("{1,2}");
	is >> array;

	EXPECT_TRUE(is);
	EXPECT_EQ(array[0], 1);
	EXPECT_EQ(array[1], 2);
}

TEST(io_std_array, input_char_3){
	std::array< int, 3 > array{};

	std::istringstream is("{1,2,3}");
	is >> array;

	EXPECT_TRUE(is);
	EXPECT_EQ(array[0], 1);
	EXPECT_EQ(array[1], 2);
	EXPECT_EQ(array[2], 3);
}
