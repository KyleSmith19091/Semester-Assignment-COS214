<div align="center">
<h1> Semester Assignment COS214 <img src="https://raw.githubusercontent.com/MartinHeinz/MartinHeinz/master/wave.gif" width="30px"></h1>
</div>

## Group Members 🎯
```c++
class StefanVanSchoor : public Student { std::string studentNumber = "u20573783" };
class KyleSmith       : public Student { std::string studentNumber = "u20435992" };
class DylanKapnias    : public Student { std::string studentNumber = "u18108467" };
class DanielBurgess   : public Student { std::string studentNumber = "u18055215" };
class TabithaJemwa    : public Student { std::string studentNumber = "u19294418" };
class LarisaBotha     : public Student { std::string studentNumber = "u20522623" };
```

## Folder Structure 📂
```
+-- Data - Data files used in System
|
|
+-- Report - Files related to Report
|    +-- refman.pdf - Doxygen document
|
+-- System - Implementation of proposed system
|    +-- src - Source files (*.cpp)
|    +-- include - Header Files (*.h)
|    +-- build - executable files
|    +-- test - Test.cpp -> Unit Tests
|    +-- makefile
|    +-- README - explaining git branching strategy and was used as guide for git workflow
```

## Compiling, Running, Testing System 🧪

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

## Data Files ⚡️
All data files created by the System can be found as .txt files in the **Data** directory.
