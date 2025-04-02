SimCity Project

Overview

The SimCity Project simulates the growth and development of a city, complete with residential, commercial, and industrial zones. The simulation includes factors such as population growth, adjacency impacts, and pollution effects, giving users insight into city management dynamics.

Features

Zone Initialization: Automatically detects and initializes residential (R), commercial (C), and industrial (I) zones from a layout file.
Population Growth: Each zone type supports population expansion, influenced by adjacency to other zones and power lines.
Pollution Simulation: Industrial zones generate pollution, which disperses to neighboring cells.
Simulation Step Control: Simulation progresses step-by-step, allowing users to observe city growth and pollution effects in real-time.
City Layout and Pollution Display: Outputs visual representations of the city and pollution distribution at intervals.

Code Structure
City.cpp / City.h: Core classes for managing city zones, adjacency checks, and pollution.
CZone.cpp, RZone.cpp, IZone.cpp: Zone-specific classes for commercial, residential, and industrial areas.
Worker.cpp, Good.cpp: Auxiliary classes handling resources like workers and goods.

Prerequisites
Compiler: A C++ compiler, such as GCC or Clang, to compile the project.
Text Editor: To configure input files and settings if needed.

How to Compile
Compile the code: Run the following command to compile the project.
                    g++ City.cpp  SimCity.cpp
                    ./a.out

