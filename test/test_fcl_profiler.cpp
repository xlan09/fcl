/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2011-2014, Willow Garage, Inc.
 *  Copyright (c) 2014-2016, Open Source Robotics Foundation
 *  Copyright (c) 2016, Toyota Research Institute
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Open Source Robotics Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/* Author Jeongseok Lee <jslee02@gmail.com> */

#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include <iostream>
#define FCL_ENABLE_PROFILING 1
#include "fcl/common/profiler.h"
#include "fcl/shape/sphere.h"
#include "fcl/collision.h"
#include "test_fcl_utility.h"

using namespace fcl;

//==============================================================================
GTEST_TEST(FCL_PROFILER, basic)
{
  detail::Profiler::Start();
  {
    detail::Profiler::Begin("Section 1");
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));

      detail::Profiler::Begin("Section 1.1");
      {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }
      detail::Profiler::End("Section 1.1");

    }
    detail::Profiler::End("Section 1");

    detail::Profiler::Begin("Section 2");
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    detail::Profiler::End("Section 2");
  }
  detail::Profiler::Stop();

  detail::Profiler::Status(std::cout);
}

//==============================================================================
int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
