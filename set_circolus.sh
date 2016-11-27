#!/usr/bin/env sh

#script per l'avvio di circolus

ROS_MAIN=192.168.0.102

echo $ROS_MAIN

#export ROS_HOSTNAME=`/bin/hostname -I`
#export ROS_IP=`hostname -I`
export ROS_IP=192.168.0.103
export ROS_MASTER_URI=http://$ROS_MAIN:11311

echo MASTER $ROS_MASTER_URI
echo LOCAL $ROS_IP

source ./catkin_ws/devel/setup.sh

rostopic list
