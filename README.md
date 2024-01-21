Very simple example workspace for ROS2 Humble, including one package in Python and another in C++. Workshop notes are below.

# ROS workshop

[toc]

## What's ROS?

ROS (pronounced "Ross") is a communication framework for robots. In a ROS system, different algorithms and programs running on a robot can easily and efficiently talk to each other. 

Beyond its communication capabilities, ROS includes useful tools for visualization, coordinate transformations, simulation, development, and more. Examples of these tools are Rviz, Nav2, and Gazebo (distributed separately).

## Components of a ROS network

Individual programs in ROS are called **nodes**. Nodes can be written in Python, C++, C#, JavaScript, or any other language that has a ROS Client Library (RCL).

In most cases, nodes communicate with each other using a **publisher-subscriber model**. In this model, nodes can exchange messages by publishing and subscribing to **topics**. When a node publishes a message to a topic, any other nodes that subscribe to this topic immediately receive the message. You can think of this as a mailing list.

A single node can publish and subscribe to as many topics as you tell it to. Internally, a node sets up these connections with **publishers** and **subscribers**, with a single publisher or subscriber for each topic.

Messages in ROS follow specific formats called **message types**. ROS includes all kinds of messages out of the box, including the **Image** message, the **Pose** message, and the **Path** message.

## Organization of ROS code

ROS nodes, custom message types, and supporting files are organized into **packages**. It's a good idea to group nodes with similar functionality into a single package, especially if they share common backend logic. While packages typically contain a single node, they often include several.

Packages are grouped into a **workspace**. With rare exceptions, every ROS project should have only one workspace. In other words, Arbor Robotics will have one ROS workspace, which will also be our Git repository. Workspaces can have dozens of packages. As we'll see, code within a workspace is typically built all at once.

## About ROS2

ROS2 is a completely rebuilt version of ROS. Both ROS2 and ROS1 share the terms listed above-- nodes, publishers, packages, and so on. However, the communication backend of ROS2 is totally different, which makes it highly efficient and stable.

While ROS1 was only ever meant to support academic research, ROS2 was designed to actually be deployed in industrial and commercial settings.

ROS1 is nearly obsolete. Open Robotics, the foundation behind ROS, will stop supporting ROS1 in May 2025.

## Prerequisite steps

In this section we will install **ROS2 Humble Hawksbill**, which runs on **Ubuntu 22.04**.

### 1. Install Ubuntu, WSL, or Docker

The vast majority of ROS systems run on Ubuntu. If you plan on developing code for our robot, I would strongly recommend that you install Ubuntu directly onto your machine, such as with dual booting.

If you only plan on editing a few files here and there, you can install ROS onto your Windows or Mac environment using Docker or WSL (Windows only).

#### a. Installing on Ubuntu 22.04

You should install`ros-foxy-desktop` from Debian packages. Instructions are [available here](https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html). The summarized version is:

```
$ sudo apt install software-properties-common
$ sudo add-apt-repository universe

$ sudo apt update && sudo apt install curl -y
$ sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
$ echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

$ sudo apt update && sudo apt upgrade

$ sudo apt install ros-foxy-desktop python3-argcomplete
```

That's it!

#### b. Installing using Docker or WSL

Tutorials are available online. The short version for Docker is:

1. Install Docker.
2. Start the Docker Engine.
3. Open your terminal.
4. `docker run -it ros:humble`

## Points to cover

- symlink-install
- cmake-clean-cache
- rqt_graph
- setup.py
- package.xml
- ros2 topic list, echo

## Tips

- For colcon errors that mention CMake, CMakelists.txt, etc, try appending the `--cmake-clean-cache` flag to `colcon build`.

- Since Python scripts are interpreted and not compiled, you can simply add a symlink to them from your source directory to `build`, meaning you only need to "rebuild" Python nodes once. Colcon can do this automatically using the `--symlink-install` flag.

- In rare cases, ROS2's backend communication layer will fail silently. You'll know this is happening when nodes stop receiving messages from each other, and all obvious causes are ruled out. You can restart the backend with `$ ros2 daemon stop && ros2 daemon start`.

- Beyond publishers and subscribers, ROS also supports individual, node-to-node connections that avoid topics entirely. ROS services

  
