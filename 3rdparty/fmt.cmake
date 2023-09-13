include(FetchContent)
option(FMT_PEDANTIC "Enable extra warnings and expensive tests." OFF)
option(FMT_WERROR "Halt the compilation with an error on compiler warnings."
       OFF)
# Options that control generation of various targets.
option(FMT_DOC "Generate the doc target." OFF)
option(FMT_INSTALL "Generate the install target." OFF)
option(FMT_TEST "Generate the test target." OFF)
option(FMT_FUZZ "Generate the fuzz target." OFF)
option(FMT_CUDA_TEST "Generate the cuda-test target." OFF)
option(FMT_OS "Include core requiring OS (Windows/Posix) " OFF)
option(FMT_MODULE "Build a module instead of a traditional library." OFF)
option(FMT_SYSTEM_HEADERS "Expose headers with marking them as system." OFF)
FetchContent_Declare(
  fmt
  SYSTEM
  URL https://github.com/fmtlib/fmt/archive/refs/tags/10.1.1.tar.gz)
FetchContent_MakeAvailable(fmt)
