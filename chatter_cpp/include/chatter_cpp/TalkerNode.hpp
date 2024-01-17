/*
 * -- Arbor Robotics --
 * Package:   chatter_cpp
 * Filename:  publisher.cpp
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

namespace arbor
{
    namespace chatter_cpp
    {

        class TalkerNode : public rclcpp::Node
        {
        public:
            TalkerNode();
            virtual ~TalkerNode();

        private:
            void timer_cb();

            rclcpp::TimerBase::SharedPtr timer_;
            rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
            size_t count_;
        };

    }
}