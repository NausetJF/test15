# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-src"
  "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-build"
  "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-subbuild/sodium-populate-prefix"
  "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-subbuild/sodium-populate-prefix/tmp"
  "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-subbuild/sodium-populate-prefix/src/sodium-populate-stamp"
  "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-subbuild/sodium-populate-prefix/src"
  "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-subbuild/sodium-populate-prefix/src/sodium-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-subbuild/sodium-populate-prefix/src/sodium-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/nausetjf/CodeFiles/raylib/test15/cmake-build-debug/_deps/sodium-subbuild/sodium-populate-prefix/src/sodium-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
