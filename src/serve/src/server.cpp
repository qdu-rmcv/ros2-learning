/*
 * @Author: BandieraRosa 3132716198@qq.com
 * @Date: 2025-03-18 21:33:29
 * @LastEditors: BandieraRosa 3132716198@qq.com
 * @LastEditTime: 2025-03-19 15:30:01
 * @FilePath: /ros2_learning/src/serve_pub/src/serve_pub.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "rclcpp/rclcpp.hpp"
#include"msgs/srv/add_ints.hpp"
#include"msgs/msg/inch_to_meter.hpp"
#include<bits/stdc++.h>

using namespace std;
using namespace rclcpp;
using namespace msgs;
using namespace msgs::srv;
using namespace msgs::msg;

class AddIntsServer: public Node{
public:
    AddIntsServer():Node("add_ints"){
      RCLCPP_INFO(this->get_logger(),"服务端节点已创建");
      service_ = this->create_service<msgs::srv::AddInts>("add_ints", 
          [this](const msgs::srv::AddInts::Request::SharedPtr request, // 对于接收到的请求，调用add函数
                 msgs::srv::AddInts::Response::SharedPtr response) {
              this->add(request, response);
          }
      );
      this->declare_parameter<int>("param1",0); // 获取yaml参数
      param = this->get_parameter("param1").as_int();
      publisher_ = this->create_publisher<msgs::msg::InchToMeter>("sub", 10); // 创建发布名为"sub"的话题的发布者
    }

    void add(const AddInts::Request::SharedPtr request, const AddInts::Response::SharedPtr response){
        response->sum = request->num1 + request->num2 + param; // 将请求中的两个数字相加，并加上yaml参数的值，将结果赋值给响应的sum字段
        RCLCPP_INFO(this->get_logger(),"收到客户端请求，请求数据为：%d、%d，返回结果：%d",request->num1, request->num2, response->sum);
        auto message = std::make_shared<InchToMeter>();
        message->num = response->sum;
        publisher_->publish(*message); // 发布消息给sub_node
    }

private:
    Service<AddInts>::SharedPtr service_;
    Publisher<InchToMeter>::SharedPtr publisher_;
    int param;
};




int main(int argc, char ** argv){
  init(argc, argv);
  spin(std::make_shared<AddIntsServer>());
  shutdown();
  return 0;
}
