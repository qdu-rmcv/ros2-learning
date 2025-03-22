from launch import LaunchDescription
from launch.actions import ExecuteProcess


def generate_launch_description():
	return LaunchDescription([
		ExecuteProcess(
            cmd=['gnome-terminal','--','ros2','run','client','client','1'],  # 使用外部命令打开客户端
            output='screen'
        )
    ])
