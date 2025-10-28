run() {
  ./build/luablocks
}

build() {
  cmake -S . -B build
  cmake --build build
}

clean() {
  rm -rf build/
}

all() {
  clean && build && run
}

case $1 in
  "run")
    run
  ;;
  "build")
    build
  ;;
  "clean")
    clean
  ;;
  "all")
    all
  ;;
esac

