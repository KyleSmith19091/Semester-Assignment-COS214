<div align="center">
<h1> Semester Assignment COS214 <img src="https://raw.githubusercontent.com/MartinHeinz/MartinHeinz/master/wave.gif" width="30px"></h1>
</div>

## Folder Structure
```
+-- Data - Data files used in System
|
|
+-- Report - Files related to Report
|
|
+-- System - Implementation of proposed system
|    +-- src - Source files (*.cpp)
|    +-- include - Header Files (*.h)
|    +-- build - executable files
|    +-- test - Test.cpp -> Unit Tests
|    +-- makefile
|    +-- README - explaining git branching strategy and was used as guidelin
```

## Compiling, Running, Testing System

### 1. CD into System working directory

```bash
$ cd ./System
```

### 2. Compile and Run System
```bash
$ make
```

### 3. Running Test Suite 

'Ensure GoogleTest is installed on Personal Device'

```
make gtest
```

## Data Files
All data files created by the System can be found as .txt files in the **Data** directory.
