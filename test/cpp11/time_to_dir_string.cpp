//-----------------------------------------------------------------------------
// Copyright (c) 2018 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#include <io_tools/time_to_dir_string.hpp>

#include "gtest/gtest.h"

#include "time_zone_offset.hpp"


TEST(time_to_dir_string, test){
	auto time = std::chrono::system_clock::from_time_t(1234567890);

	time -= std::chrono::seconds(time_zone_offset());

	EXPECT_EQ(io_tools::time_to_dir_string(time), "20090213_233130");
}
