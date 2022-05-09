if [ ! -d 'build' ]; then
	mkdir build
fi
cd build && cmake -DGLFW_BUILD_TESTS=OFF .. && make && cd ..
