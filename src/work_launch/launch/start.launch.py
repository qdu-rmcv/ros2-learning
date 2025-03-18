import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    
    node1_package_share_dir = get_package_share_directory('cli_ser') #获取当前功能包的路径
    params_file = os.path.join(node1_package_share_dir, 'config', 'canshu.yaml') #加载YAML参数文件
    node1 = Node(
        package='cli_ser',
        executable='node_ser',
        name='ser',
        parameters=[params_file],  # 加载 YAML 参数
        output='screen'
    ) #启动cli_ser功能包的服务端

    
    node2 = Node(
        package='cli_ser',
        executable='node_cli',
        name='cli',
        output='screen'
    ) #启动cli_ser功能包的客户端

    node3 = Node(
        package='other_packages',
        executable='node_pub',
        name='pub',
        output='screen'
    ) #调用other_packages功能包的node_sub节点

    return LaunchDescription([
        node1,
        node2,
        node3
    ])