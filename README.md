# tdd_in_cpp_with_bazel
TDD in C++ with bazel build

## Build Status
[![Build Status](https://travis-ci.com/orieken/tdd_in_cpp_with_bazel.svg?branch=master)](https://travis-ci.com/orieken/tdd_in_cpp_with_bazel)

# Building
* build: `bazel build ...`
* tests: `bazel test ...`
* verbose tests: `bazel test ... --test_output=all`
* watching for file changes: `ag -l | entr -s 'bazel test ... --test_output=all'`

## Bazel files

### WORKSPACE
just has a the list of dependencies

### BUILD
a build file needs to be places in all source dir see specifc `cc_` file
for [more information](https://docs.bazel.build/versions/master/be/c-cpp.html)
