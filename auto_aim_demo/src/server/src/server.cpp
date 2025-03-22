#include <rclcpp/rclcpp.hpp>
#include "interfaces/srv/auto_aim.hpp"
#include "interfaces/msg/point2.hpp"
#include "server/auto_centre.hpp"
#include "cv_bridge/cv_bridge.h"
#include <cstring>

using interfaces::srv::AutoAim;
using std::placeholders::_1;
using std::placeholders::_2;

class My_Server : public rclcpp::Node
{
public:
    My_Server() : Node("my_server")
    {
        server_ = this->create_service<AutoAim>("centre", std::bind(&My_Server::get_centre, this, _1, _2));
        RCLCPP_INFO(this->get_logger(), "server已启动,等待request...");
        this->declare_parameter<std::string>("PIC_PATH", "/home/find/code/cpp/auto_aim_demo/src/server/test/0.jpg");
        this->get_parameter("PIC_PATH", PIC_PATH);
    }
    std::string PIC_PATH;

private:
    rclcpp::Service<AutoAim>::SharedPtr server_;
    void get_centre(const AutoAim::Request::SharedPtr req, const AutoAim::Response::SharedPtr res)
    {
        if (req->num1 == 1)
        {
            res->centre.x = auto_centre(PIC_PATH).x;
            res->centre.y = auto_centre(PIC_PATH).y;
            RCLCPP_INFO(this->get_logger(), "中心:x %f,y %f", res->centre.x, res->centre.y);
        }
    }
};

int main(int argc, char const *argv[])
{

    // 2.初始化 ROS2 客户端；
    rclcpp::init(argc, argv);

    // 4.调用spin函数，并传入节点对象指针；
    auto server = std::make_shared<My_Server>();
    rclcpp::spin(server);

    // 5.释放资源。
    rclcpp::shutdown();
    return 0;
}
