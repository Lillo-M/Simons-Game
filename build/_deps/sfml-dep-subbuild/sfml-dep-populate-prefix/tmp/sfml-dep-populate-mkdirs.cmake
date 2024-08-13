# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/lillo/thewizard/build/_deps/sfml-dep-src"
  "/home/lillo/thewizard/build/_deps/sfml-dep-build"
  "/home/lillo/thewizard/build/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix"
  "/home/lillo/thewizard/build/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/tmp"
  "/home/lillo/thewizard/build/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src/sfml-dep-populate-stamp"
  "/home/lillo/thewizard/build/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src"
  "/home/lillo/thewizard/build/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src/sfml-dep-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/lillo/thewizard/build/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src/sfml-dep-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/lillo/thewizard/build/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src/sfml-dep-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
