SRCS = MasterMind.cpp \
       row.cpp \
       result.cpp

CPPFLAGS = -std=c++0x -g -Wall

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

MasterMind : $(OBJS)
	$(CXX) -o $@ $^
	@touch $@

.Phony: unit_test
unit_test: test_row test_result
	./test_row
	./test_result

test_row: row.cpp result.cpp
	$(CXX) $(CPPFLAGS) -DUNITTEST_ROW -o $@ $^

test_result: result.cpp
	$(CXX) $(CPPFLAGS) -DUNITTEST_RESULT -o $@ $^

.Phony: clean
clean:
	@rm -f $(OBJS) $(DEPS)
	@rm -f MasterMind Mastermind.exe
	@rm -f test_*

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(DEPS)
