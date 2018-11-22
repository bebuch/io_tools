//-----------------------------------------------------------------------------
// Copyright (c) 2018 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#include <io_tools/range_to_string.hpp>

#include "gtest/gtest.h"

#include <vector>
#include <list>


TEST(range_to_string, vector_0){
	std::vector< int > range;

	EXPECT_EQ(io_tools::range_to_string(range), "");
}

TEST(range_to_string, vector_1){
	std::vector< int > range{1};

	EXPECT_EQ(io_tools::range_to_string(range), "1");
}

TEST(range_to_string, vector_3){
	std::vector< int > range{1, 2, 3};

	EXPECT_EQ(io_tools::range_to_string(range), "1, 2, 3");
}

TEST(range_to_string, vector_separator){
	std::vector< int > range{1, 2, 3};

	EXPECT_EQ(io_tools::range_to_string(range, "x"), "1x2x3");
}


TEST(range_to_string, list_0){
	std::list< int > range;

	EXPECT_EQ(io_tools::range_to_string(range), "");
}

TEST(range_to_string, list_1){
	std::list< int > range{1};

	EXPECT_EQ(io_tools::range_to_string(range), "1");
}

TEST(range_to_string, list_3){
	std::list< int > range{1, 2, 3};

	EXPECT_EQ(io_tools::range_to_string(range), "1, 2, 3");
}

TEST(range_to_string, list_separator){
	std::list< int > range{1, 2, 3};

	EXPECT_EQ(io_tools::range_to_string(range, "x"), "1x2x3");
}


TEST(range_to_string, c_array_1){
	int range[1] = {1};

	EXPECT_EQ(io_tools::range_to_string(range), "1");
}

TEST(range_to_string, c_array_3){
	int range[3] = {1, 2, 3};

	EXPECT_EQ(io_tools::range_to_string(range), "1, 2, 3");
}

TEST(range_to_string, c_array_separator){
	int range[3] = {1, 2, 3};

	EXPECT_EQ(io_tools::range_to_string(range, "x"), "1x2x3");
}
