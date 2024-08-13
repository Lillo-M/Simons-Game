# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-src")
  file(MAKE_DIRECTORY "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-src")
endif()
file(MAKE_DIRECTORY
  "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-build"
  "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix"
  "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/tmp"
  "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src/sfml-dep-populate-stamp"
  "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src"
  "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src/sfml-dep-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src/sfml-dep-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/lillo/Documents/thewizard/build2/_deps/sfml-dep-subbuild/sfml-dep-populate-prefix/src/sfml-dep-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
