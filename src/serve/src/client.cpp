/*
 * @Author: BandieraRosa 3132716198@qq.com
 * @Date: 2025-03-18 21:33:44
 * @LastEditors: BandieraRosa 3132716198@qq.com
 * @LastEditTime: 2025-03-19 15:27:34
 * @FilePath: /ros2_learning/src/serve_sub/src/serve_sub.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "rclcpp/rclcpp.hpp"
#include"msgs/srv/add_ints.hpp"
#include<bits/stdc++.h>

using namespace std;
using namespace rclcpp;
using namespace msgs;
using namespace msgs::srv;

class AddIntsClient: public Node{
public:
    AddIntsClient():Node("add_ints"){
        RCLCPP_INFO(this->get_logger(),"客户端节点已创建");
        client_ = this->create_client<AddInts>("add_ints");

        this->declare_parameter<int>("param2",0);
        this->declare_parameter<int>("param3",1); // 获取yaml参数

        param2_ = this->get_parameter("param2").as_int();
        param3_ = this->get_parameter("param3").as_int();

        bool flag = this->connect(); // 判断适逢成功连接服务端
        if(flag){
            auto request = std::make_shared<AddInts::Request>();
            request->num1 = param2_;
            request->num2 = param3_;
            auto result = client_->async_send_request(request); // 发送请求到服务端
            if(rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS){
                RCLCPP_INFO(this->get_logger(), "服务端调用成功，结果为：%d", result.get()->sum);
            }
        }
    }
    bool connect(){ 
        while(!client_->wait_for_service(1s)){ 
            if(!rclcpp::ok()){
                RCLCPP_ERROR(this->get_logger(),"客户端被中断");
                return false;
            }
            RCLCPP_INFO(this->get_logger(),"等待服务端");
        }
        return true;
    }
    Client<AddInts>::SharedPtr client_;
private:
    int param2_; // yaml参数
    int param3_;
};



int main(int argc, char ** argv){
    init(argc, argv);
    auto client = std::make_shared<AddIntsClient>(); // 不使用spin
    shutdown();
    return 0;
}
