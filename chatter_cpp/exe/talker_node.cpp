/*
 * -- Arbor Robotics --
 * Package:   chatter_cpp
 * Filename:  talker.cpp
 * Author:    Will Heitman
 * Email:     w@heit.mn
 * License:   MIT License
 */

#include <iostream>
#include <memory> // std::make_shared
#include "rclcpp/rclcpp.hpp"
#include "chatter_cpp/TalkerNode.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<arbor::chatter_cpp::TalkerNode>());
  rclcpp::shutdown();
  return 0;
}