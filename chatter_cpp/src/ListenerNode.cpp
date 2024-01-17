#include "chatter_cpp/ListenerNode.hpp"

using namespace std::chrono_literals;
using arbor::chatter_cpp::ListenerNode;
using std::placeholders::_1;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

ListenerNode::ListenerNode()
    : Node("cpp_listener_node")
{
  subscriber_ = this->create_subscription<std_msgs::msg::String>("chatter", 10, std::bind(&ListenerNode::topic_cb, this, _1));
}

ListenerNode::~ListenerNode() {}

void ListenerNode::topic_cb(const String::SharedPtr msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}