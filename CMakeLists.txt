cmake_minimum_required(VERSION 3.14)
project(raytracer)
add_executable(raytracer src/raytrace.cpp src/utils.cpp src/Ray.cpp src/SceneObject.cpp src/Sphere.cpp)
target_include_directories(raytracer PUBLIC include)
