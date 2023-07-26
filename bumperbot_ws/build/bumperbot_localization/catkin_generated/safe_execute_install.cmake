execute_process(COMMAND "/home/st/Course-Training/Udemy_ROS_self_driving/bumperbot_ws/build/bumperbot_localization/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/st/Course-Training/Udemy_ROS_self_driving/bumperbot_ws/build/bumperbot_localization/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
