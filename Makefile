.PHONY: format check build test clean

format:
	find src tests -name "*.cc" -o -name "*.h" | xargs clang-format -i

check:
	clang-tidy -p build src/*.cc src/gui/*.cc src/core/*.cc

build:
	cmake -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	ninja -C build

test:
	cd build && ctest --output-on-failure

clean:
	rm -rf build
