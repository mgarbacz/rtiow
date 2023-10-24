# rtiow
Ray Tracing in One Weekend

Following [the book](https://raytracing.github.io/books/RayTracingInOneWeekend.html) with supplemental [source code](https://github.com/RayTracing/raytracing.github.io/tree/release#source-code).

## Configuring and building
```sh
cmake -B build
cmake --build build
```

## Running
```sh
./build/main > build/image.ppm
open build/image.ppm
```

## Extra Resources & Further Reading

- [Google C++ Styleguide](https://google.github.io/styleguide/cppguide.html)
- [Google protobuf source code](https://github.com/protocolbuffers/protobuf/tree/main/src/google/protobuf) (to examine application of the style guide)
- [Nvidia RTIOW in CUDA](https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/)
