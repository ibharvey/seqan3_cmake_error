CXX?=g++
CXXFLAGS+=-O3 -pipe -fPIC -march=native -mtune=native -std=c++11

PREFIX=/usr/local

# We want to pass -Wa,-q to GCC use the Clang assembler, but Apple Clang can't take that
# So we do an environment variable instead
export AS_INTEGRATED_ASSEMBLER=1

ifeq ($(shell if [ -d /opt/local/include/libomp ];then echo 1;else echo 0;fi), 1)
    # On OS X with Apple Clang, <omp.h>, which our tinyFA dependency needs, isn't always on the include path
    # Pick it up from Macports if it is there.
    # Homebrew ought to put it where the compiler can find it.
    CXXFLAGS += -I/opt/local/include/libomp
endif


BIN_DIR:=bin
BUILD_DIR:=build

LD_LIB_FLAGS=-L./src/ -L./
LD_INC_FLAGS=-I./src/ -I./ -I./src/tinyFA -I./src/tinyFA/pliib -I./$(BUILD_DIR)

ifneq ($(CONDA_PREFIX),)
	LD_LIB_FLAGS += -L$(CONDA_PREFIX)/lib/
	LD_INC_FLAGS += -I$(CONDA_PREFIX)/include
	PREFIX = $(CONDA_PREFIX)
endif

gfak: $(BUILD_DIR)/main.o src/gfakluge.hpp src/tinyFA/pliib/pliib.hpp src/tinyFA/tinyFA.hpp | $(BUILD_DIR) $(BIN_DIR)
	+$(CXX) $(LDFLAGS) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LD_LIB_FLAGS) $(LD_INC_FLAGS)

$(BUILD_DIR)/main.o: src/main.cpp src/gfakluge.hpp src/tinyFA/pliib/pliib.hpp src/tinyFA/tinyFA.hpp | $(BUILD_DIR) $(BIN_DIR)
	+$(CXX) $(LDFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< $(LD_LIB_FLAGS) $(LD_INC_FLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

install: gfak
	mkdir -p $(DESTDIR)$(PREFIX)/include
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp src/gfakluge.hpp $(DESTDIR)$(PREFIX)/include/
	cp src/tinyFA/tinyFA.hpp $(DESTDIR)$(PREFIX)/include/
	cp src/tinyFA/pliib/pliib.hpp $(DESTDIR)$(PREFIX)/include/

	cp gfak $(DESTDIR)$(PREFIX)/bin

check : gfak
	prove test/gfa_test.t


.PHONY: clean all install check


clean:
	$(RM) gfak
	$(RM) src/*.o
	$(RM) *.a
	$(RM) x.sort
	$(RM) y.sort
	rm -rf $(BIN_DIR)
	rm -rf $(BUILD_DIR)
	$(RM) test_test.gfa
	$(RM) q_test.gfa
