/*
 * -- Arbor Robotics --
 * Package:   chatter_cpp
 * Filename:  listener.cpp
 * Author:    Will Heitman
 * Email:     w@heit.mn
 * License:   MIT License
 */

#include <iostream>
#include <memory> // std::make_shared
#include "rclcpp/rclcpp.hpp"
#include "chatter_cpp/ListenerNode.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<arbor::chatter_cpp::ListenerNode>());
  rclcpp::shutdown();
  return 0;
}