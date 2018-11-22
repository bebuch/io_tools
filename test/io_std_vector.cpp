//-----------------------------------------------------------------------------
// Copyright (c) 2018 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#include <io_tools/io_std_vector.hpp>

#include <sstream>
#include <string>

#include "gtest/gtest.h"


namespace{


	using namespace ::io_tools::io_std_vector;


}


TEST(io_std_vector, output_char_1){
	std::vector< int > array{1};

	std::ostringstream os;
	os << array;

	EXPECT_TRUE(os);
	EXPECT_EQ(os.str(), "{1}");
}

TEST(io_std_vector, output_char_2){
	std::vector< int > array{1, 2};

	std::ostringstream os;
	os << array;

	EXPECT_TRUE(os);
	EXPECT_EQ(os.str(), "{1,2}");
}

TEST(io_std_vector, output_char_3){
	std::vector< int > array{1, 2, 3};

	std::ostringstream os;
	os << array;

	EXPECT_TRUE(os);
	EXPECT_EQ(os.str(), "{1,2,3}");
}


TEST(io_std_vector, input_char_1){
	std::vector< int > array;

	std::istringstream is("{1}");
	is >> array;

	EXPECT_TRUE(is);
	ASSERT_EQ(array.size(), 1);
	EXPECT_EQ(array[0], 1);
}

TEST(io_std_vector, input_char_2){
	std::vector< int > array;

	std::istringstream is("{1,2}");
	is >> array;

	EXPECT_TRUE(is);
	ASSERT_EQ(array.size(), 2);
	EXPECT_EQ(array[0], 1);
	EXPECT_EQ(array[1], 2);
}

TEST(io_std_vector, input_char_3){
	std::vector< int > array;

	std::istringstream is("{1,2,3}");
	is >> array;

	EXPECT_TRUE(is);
	ASSERT_EQ(array.size(), 3);
	EXPECT_EQ(array[0], 1);
	EXPECT_EQ(array[1], 2);
	EXPECT_EQ(array[2], 3);
}
