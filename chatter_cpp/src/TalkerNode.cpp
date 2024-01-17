#include "chatter_cpp/TalkerNode.hpp"

using namespace std::chrono_literals;
using arbor::chatter_cpp::TalkerNode;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

TalkerNode::TalkerNode()
    : Node("talker_node"), count_(0)
{
  publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
  timer_ = this->create_wall_timer(
      500ms, std::bind(&TalkerNode::timer_cb, this));
}

TalkerNode::~TalkerNode() {}

void TalkerNode::timer_cb()
{
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(count_++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
}