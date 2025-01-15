check_error() {
  if [ $? -ne 0 ]; then
    echo "Error encountered. Exiting."
    exit 1
  fi
}

if ! command -v cmake &> /dev/null; then
  echo "CMake is not installed. Please install it and try again."
  exit 1
fi

if [ ! -d "build" ]; then
  echo "Creating build directory..."
  mkdir build
fi

cd build || exit

echo "Configuring project with CMake..."
cmake .. 
check_error

echo "Building the project..."
cmake --build . 
check_error

OS=$(uname -s)
if [ "$OS" = "Linux" ] || [ "$OS" = "Darwin" ]; then
  EXECUTABLE="./dist/algebruh"
elif [[ "$OS" == MINGW* || "$OS" == CYGWIN* ]]; then
  EXECUTABLE="./dist/algebruh.exe"
else
  echo "Unsupported operating system: $OS"
  exit 1
fi

if [ -f "$EXECUTABLE" ]; then
  echo "Running the executable..."
  $EXECUTABLE
else
  echo "Executable not found at $EXECUTABLE. Ensure the build was successful."
  exit 1
fi
