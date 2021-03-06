/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <thread>

#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>

#include "frc/SlewRateLimiter.h"
#include "gtest/gtest.h"

TEST(SlewRateLimiterTest, SlewRateLimitTest) {
  frc::SlewRateLimiter<units::meters> limiter(1_mps);

  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  EXPECT_TRUE(limiter.Calculate(2_m) < 2_m);
}

TEST(SlewRateLimiterTest, SlewRateNoLimitTest) {
  frc::SlewRateLimiter<units::meters> limiter(1_mps);

  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  EXPECT_EQ(limiter.Calculate(0.5_m), 0.5_m);
}
