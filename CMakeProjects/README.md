# C++ LinkedList implementation and build project

## Overview

This project is a C++ application that includes unit tests. The following instructions will guide you through installing the prerequisites, setting up the project, and running the tests.

### Setting up formater

Add this code to settings.json if you are using Visual Studio Code
```
{
  "editor.formatOnSave": true,
  "clang-format.executable": "clang-format",
  "clang-format.style": "file"
}
```

## Building the Project

1. **Clone the Repository**
```
git clone https://github.com/MatejStrlek/MicroblinkPraxis.git
cd MicroblinkPraxis/LinkedList/
```

2. **Create a Build Directory**
```
mkdir build
cd build
```

3. **Configure the Project**
```
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined" ..
```

4. **Build the project**
```
cmake --build .
```

5. **Run tests**
```
ctest --verbose
```