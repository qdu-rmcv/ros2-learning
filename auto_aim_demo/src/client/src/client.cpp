#include "rclcpp/rclcpp.hpp"
#include "interfaces/srv/auto_aim.hpp"
#include "interfaces/msg/point2.hpp"

using namespace std::chrono_literals;
using interfaces::srv::AutoAim;

class Client : public rclcpp::Node
{
public:
    Client() : Node("client")
    {
        // 创建客户端；
        client = this->create_client<AutoAim>("centre");
        RCLCPP_INFO(this->get_logger(), "客户端创建，等待连接服务端！");
    }
    // 等待服务连接；
    bool connect_server()
    {
        while (!client->wait_for_service(1s))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "强制退出！");
                return false;
            }

            RCLCPP_INFO(this->get_logger(), "服务连接中，请稍候...");
        }
        return true;
    }
    // 组织请求数据并发送；
    rclcpp::Client<AutoAim>::FutureAndRequestId send_request(int num1)
    {
        auto request = std::make_shared<AutoAim::Request>();
        request->num1 = num1;
        return client->async_send_request(request);
    }

private:
    rclcpp::Client<AutoAim>::SharedPtr client;
};

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "请输入1获取打击中心");
        return 1;
    }

    rclcpp::init(argc, argv);

    // 创建对象指针并调用其功能；
    auto client = std::make_shared<Client>();
    bool flag = client->connect_server();
    if (!flag)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "服务连接失败！");
        return 0;
    }

    auto response = client->send_request(atoi(argv[1]));

    // 处理响应
    if (rclcpp::spin_until_future_complete(client, response) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(client->get_logger(), "请求正常处理");
        auto result = response.get();
        RCLCPP_INFO(client->get_logger(), "响应结果:x:%f y:%f!", result->centre.x, result->centre.y);
    }
    else
    {
        RCLCPP_INFO(client->get_logger(), "请求异常");
    }
    rclcpp::shutdown();
    return 0;
}
