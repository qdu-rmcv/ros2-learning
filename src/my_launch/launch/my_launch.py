'''
Author: BandieraRosa 3132716198@qq.com
Date: 2025-02-27 16:40:23
LastEditors: BandieraRosa 3132716198@qq.com
LastEditTime: 2025-03-19 15:24:34
FilePath: /ros2_learning/src/my_launch/launch/my_launch.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('serve')
    yaml_file = os.path.join(pkg_share, 'config', 'par.yaml') # 获取参数文件路径

    Node3 = Node(package="metric_system", 
                 executable="sub_node",
                 name="sub_node",
                 output = "screen")
    Node1 = Node(package="serve", 
                 executable="server", 
                 name="server",  
                 parameters=[yaml_file], # 传入参数
                 output = "screen")
    Node2 = Node(package="serve", 
                 executable="client", 
                 name="client", 
                 parameters=[yaml_file],
                 output = "screen")

    return LaunchDescription([Node3, Node1, Node2])