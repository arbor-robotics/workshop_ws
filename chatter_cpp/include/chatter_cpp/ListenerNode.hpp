/*
 * -- Arbor Robotics --
 * Package:   chatter_cpp
 * Filename:  ListenerNode.hpp
 * Author:    Will Heitman
 * Email:     w@heit.mn
 * License:   MIT License
 */

#pragma once

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "rclcpp/rclcpp.hpp"

using std_msgs::msg::String;


namespace arbor
{
    namespace chatter_cpp
    {

        class ListenerNode : public rclcpp::Node
        {
        public:
            ListenerNode();
            virtual ~ListenerNode();

        private:
            void topic_cb(const String::SharedPtr msg) const;

            rclcpp::Subscription<String>::SharedPtr subscriber_;
        };

    }
}