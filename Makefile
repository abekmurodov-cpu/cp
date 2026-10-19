CXX := c++
CXXFLAGS := -std=c++17

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
