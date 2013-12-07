SRCS = MasterMind.cpp \
       row.cpp \
       result.cpp

CPPFLAGS = -std=c++11 -g

OBJS = $(SRCS:.cpp=.o)

MasterMind : $(OBJS)
	$(CXX) -o $@ $^

.Phony: unit_test
unit_test: test_row test_result
	./test_row
	./test_result

test_row: row.cpp result.cpp
	$(CXX) $(CPPFLAGS) -DUNITTEST_ROW -o $@ $^

test_result: result.cpp
	$(CXX) $(CPPFLAGS) -DUNITTEST_RESULT -o $@ $^

