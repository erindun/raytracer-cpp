cmake_minimum_required(VERSION 3.14)
project(raytracer)
add_executable(raytracer src/main.cpp src/utils.cpp src/ray.cpp src/scene_object.cpp src/sphere.cpp)
target_include_directories(raytracer PUBLIC include)
