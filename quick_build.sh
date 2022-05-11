if [ ! -d 'build' ]; then
	mkdir build
fi
cd build && cmake -DGLFW_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=OFF .. && make && cd ..
