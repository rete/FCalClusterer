#pragma once

#include "TestUtilities.hh"

int runTest(int argn, char** argc);

int main(int argn, char** argc) {
#ifndef STREAMLOG_NEW_TS_IMPL
  streamlog::out.init(std::cout, "Testing");
  initLogLevels();
  streamlog::logscope scope(streamlog::out);
  scope.setLevel("DEBUG6");
#else
  streamlog::logstream::global_init( &std::cout, "Testing", "DEBUG6" ) ;
#endif

  try {
    return runTest(argn, argc);
  } catch (std::out_of_range& e) {
    std::cerr << "Geometry does not agree with energy in the trees:" << e.what() << std::endl;
    return 1;
  } catch (std::runtime_error& e) {
    std::cerr << "Runtime Error: " << e.what() << std::endl;
    return 1;
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
