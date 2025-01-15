#### Qt online installer

```bash
qt-online-installer-windows-x64-x.x.x.exe --mirror https://mirrors.nju.edu.cn/qt
```


```bash
MaintenanceTool.exe --mirror https://mirrors.nju.edu.cn/qt
```


#### Opencv CMakeLists.txt

```
set(OpenCV_DIR "/opencv/build")
find_package(OpenCV REQUIRED)
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(${ProjectName} ${OpenCV_LIBS})
```
