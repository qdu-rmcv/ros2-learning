#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float32.hpp>
#include <sstream>

class MetricNode : public rclcpp::Node {
public:
    MetricNode() : Node("metric_node") {
        // 创建/inch话题的订阅器
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "/inch", 10, 
            [this](const std_msgs::msg::Int32::SharedPtr msg) {
                this->topic_callback(msg);
            });
         //创建/meter话题的发布器
        publisher_ = this->create_publisher<std_msgs::msg::Float32>("/meter", 10);
    }

private:
    void topic_callback(const std_msgs::msg::Int32::SharedPtr msg) {
        if (msg->data < 0) {
            RCLCPP_WARN(this->get_logger(), 
                       "Received negative value %d, Ignored.",
                       msg->data);
            return;
        }
        
        float meters = static_cast<float>(msg->data) * 0.0254f;
         std::stringstream ss;
        ss << std::fixed << std::setprecision(3) << meters; // 强制三位小数
        ss >> meters;  // 将格式化后的值重新赋回变量
        
        auto message = std_msgs::msg::Float32();
        message.data = meters;
        publisher_->publish(message);
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
}; 

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MetricNode>()); 
    rclcpp::shutdown();
    return 0;
}