conan install . -s build_type=RelWithDebInfo --build=missing
cmake --preset=conan-default -DCMAKE_BUILD_TYPE=RelWithDebInfo -DBENCH_HE2PALEO=ON -DTEST_HE2PALEO=ON
cmake --build build --config RelWithDebInfo