# Задание 1

## Вам поручили перейти на систему автоматизированной сборки CMake. Исходные файлы находятся в директории formatter_lib. В этой директории находятся файлы для статической библиотеки formatter. Создайте CMakeLists.txt в директории formatter_lib, с помощью которого можно будет собрать ститческую библиотеку formatter:

Создаём нужные нам для статической библиотеки файлы:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib# mkdir include
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib# cd include
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib/include# touch formatter.h
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib/include# subl formatter.h
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib/include# cd ..
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib# mkdir sources
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib# cd sources
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib/sources# touch formatter.cpp
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib/sources# subl formatter.cpp
</pre>

Создаём CMakeLists.txt:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib# touch CMakeLists.txt
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib# subl CMakeLists.txt</pre>

<pre>cmake_minimum_required(VERSION 3.4)
project(formatter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter STATIC ~/eDeodX/workspace/tasks/HM3/formatter_lib/sources/formatter.cpp)
include_directories(~/eDeodX/workspace/tasks/HM3/formatter_lib/include)</pre>

Билдим:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib# cmake -H. -B_build
CMake Deprecation Warning at CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake &lt; 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument &lt;min&gt; value.  Or, use the &lt;min&gt;...&lt;max&gt; syntax
  to tell CMake that the project requires at least &lt;min&gt; but has been updated
  to work with policies introduced by &lt;max&gt; or earlier.


-- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /root/eDeodX/workspace/tasks/HM3/formatter_lib/_build
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_lib# cmake --build _build
[ 50%] <font color="#00AA00">Building CXX object CMakeFiles/formatter.dir/sources/formatter.cpp.o</font>
[100%] <font color="#55FF55"><b>Linking CXX static library libformatter.a</b></font>
[100%] Built target formatter
</pre>

# Задание 2

## У компании "Formatter Inc." есть перспективная бибиотека которая является расширением предыдущей библиотеки. Т.к. вы уже овладели навыком создания CMakeLists.txt для статической библиотеки formatter, ваш руководитель поручает заняться созданием CMakeLists.txt для библиотеки formatter_ex, которая в свою очередь использует библиотеку formatter

Аналогично 1 заданию создаем исходные файлы:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3# mkdir formatter_ex_lib
root@debian:~/eDeodX/workspace/tasks/HM3# cd formatter_ex_lib/
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib# mkdir include
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib# cd include
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib/include# touch formatter_ex.h
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib/include# subl formatter_ex.h 
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib/include# cd ..
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib# mkdir sources
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib# cd sources
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib/sources# touch formatter_ex.cpp
root@debian:~/eDeodX/workspace/tasks/HM3/formatter_ex_lib/sources# subl formatter_ex.cpp
</pre>

CMakeLists.txt в formatter_ex:

<pre>cmake_minimum_required(VERSION 3.10)
project(formatter_ex)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter_ex STATIC sources/formatter_ex.cpp)
target_include_directories(formatter_ex PUBLIC include
  ~/eDeodX/workspace/tasks/HM3/formatter_lib/include
)

target_link_libraries(formatter_ex PUBLIC formatter) </pre>

CMakeLists.txt в корневой папке HM3:

<pre>cmake_minimum_required(VERSION 3.10)
project(HM3)

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)</pre>

Билд:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3# cmake -H. -B_build
-- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /root/eDeodX/workspace/tasks/HM3/_build
root@debian:~/eDeodX/workspace/tasks/HM3# cmake --build _build
[ 25%] <font color="#00AA00">Building CXX object formatter_lib/CMakeFiles/formatter.dir/sources/formatter.cpp.o</font>
[ 50%] <font color="#55FF55"><b>Linking CXX static library libformatter.a</b></font>
[ 50%] Built target formatter
[ 75%] <font color="#00AA00">Building CXX object formatter_ex_lib/CMakeFiles/formatter_ex.dir/sources/formatter_ex.cpp.o</font>
[100%] <font color="#55FF55"><b>Linking CXX static library libformatter_ex.a</b></font>
[100%] Built target formatter_ex
root@debian:~/eDeodX/workspace/tasks/HM3# subl REPORT.md 
</pre>

# Задание 3

## Конечно же ваша компания предоставляет примеры использования своих библиотек. Чтобы продемонстрировать как работать с библиотекой formatter_ex, вам необходимо создать два CMakeList.txt для двух простых приложений:

## hello_world, которое использует библиотеку formatter_ex
## solver, приложение которое использует статические библиотеки formatter_ex и solver_lib

Создаем исходные файлы для библиотеки solver_lib:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3# mkdir examples
root@debian:~/eDeodX/workspace/tasks/HM3# cd examples
root@debian:~/eDeodX/workspace/tasks/HM3/examples# touch hello_world.cpp
root@debian:~/eDeodX/workspace/tasks/HM3/examples# subl hello_world.cpp
root@debian:~/eDeodX/workspace/tasks/HM3/examples# cd ..
root@debian:~/eDeodX/workspace/tasks/HM3# mkdir solver_lib
root@debian:~/eDeodX/workspace/tasks/HM3# cd solver_lib/
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib# mkdir include
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib# cd include
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib/include# touch solver.h
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib/include# subl solver.h 
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib/include# cd ..
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib# mkdir sources
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib# cd sources/
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib/sources# touch solver.cpp
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib/sources# subl solver.cpp 
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib/sources# subl solver.cpp
</pre>

CMakeLists.txt в solver_lib:

<pre>cmake_minimum_required(VERSION 3.10)
project(solver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(solver STATIC sources/solver.cpp)
include_directories(include)</pre>

Билдим solver_lib:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib# cmake -H. -B_build
-- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /root/eDeodX/workspace/tasks/HM3/solver_lib/_build
root@debian:~/eDeodX/workspace/tasks/HM3/solver_lib# cmake --build _build
[ 50%] Building CXX object CMakeFiles/solver.dir/sources/solver.cpp.o
[100%] Linking CXX static library libsolver.a
[100%] Built target solver
</pre>

CMakeLists.txt в hello_world:

<pre>
cmake_minimum_required(VERSION 3.10)
project(hello_world)

add_executable(hello_world hello_world.cpp)

target_link_libraries(hello_world PRIVATE formatter_ex)

target_include_directories(hello_world PRIVATE ~/eDeodX/workspace/tasks/HM3/formatter_ex_lib/include)</pre>

CMakeLists.txt в solver:

<pre>
cmake_minimum_required(VERSION 3.10)
project(solver_app)

add_executable(solver_app solver.cpp)

target_link_libraries(solver_app PRIVATE
  formatter_ex
  solver
)

target_include_directories(solver_app PRIVATE
  ~/eDeodX/workspace/tasks/HM3/formatter_ex_lib/include
  ~/eDeodX/workspace/tasks/HM3/solver_lib/include
)
</pre>

Билдим:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3# cmake -H. -B_build
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /root/eDeodX/workspace/tasks/HM3/_build
root@debian:~/eDeodX/workspace/tasks/HM3# cmake --build _build
[ 10%] Building CXX object formatter_lib/CMakeFiles/formatter.dir/sources/formatter.cpp.o
[ 20%] Linking CXX static library libformatter.a
[ 20%] Built target formatter
[ 30%] Building CXX object formatter_ex_lib/CMakeFiles/formatter_ex.dir/sources/formatter_ex.cpp.o
[ 40%] Linking CXX static library libformatter_ex.a
[ 40%] Built target formatter_ex
[ 50%] Building CXX object solver_lib/CMakeFiles/solver.dir/sources/solver.cpp.o
[ 60%] Linking CXX static library libsolver.a
[ 60%] Built target solver
[ 70%] Building CXX object examples/hello_world/CMakeFiles/hello_world.dir/hello_world.cpp.o
[ 80%] Linking CXX executable hello_world
[ 80%] Built target hello_world
[ 90%] Building CXX object examples/solver/CMakeFiles/solver_app.dir/solver.cpp.o
[100%] Linking CXX executable solver_app
[100%] Built target solver_app
</pre>

Работа hello_world:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3# ./_build/examples/hello_world/hello_world
------------------------
hello, world!
------------------------
</pre>

Работа solver:

<pre>root@debian:~/eDeodX/workspace/tasks/HM3# ./_build/examples/solver/solver_app
1 2 -3
------------------------
x1 = -3.000000
------------------------
------------------------
x2 = 1.000000
------------------------
</pre>