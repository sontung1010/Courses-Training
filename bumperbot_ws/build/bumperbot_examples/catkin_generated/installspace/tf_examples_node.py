#!/usr/bin/env python3
import rospy
from bumperbot_examples.tf_example import TfExamples

if __name__ == '__main__':
    rospy.init_node('tf_example')
    tfExamples = TfExamples()
    rospy.spin()