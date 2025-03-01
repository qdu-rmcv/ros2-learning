from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    Node1 = Node(package="british_system", executable="british_pub", name="inch_pub")
    Node2 = Node(package="metric_system", executable="metric_system", name="metre_sub")
    return LaunchDescription([Node1, Node2])
