#!/usr/bin/env python3
import rospy


def timerCallback(event=None):
    rospy.loginfo("Called timerCallback function")

if __name__ == '__main__':
    rospy.init_node("simple_timer_py", anonymous=True)
    timer_duration = rospy.Duration(1)
    rospy.Timer(timer_duration, timerCallback)
    rospy.spin()
