MAIN_FOLDER=plotter
SOURCE_FOLDER=$(MAIN_FOLDER)/src
INCLUDES_FOLDER=$(MAIN_FOLDER)/include
BUILD_FOLDER=build

DEBUG=-g
CFLAG=-Ofast -Wall -std=c++11 -pedantic -Werror $(DEBUG)
INCLUDES=-I$(MAIN_FOLDER)/lib -I/usr/lib/python3.7/site-packages/numpy/core/include -I/usr/include/python3.7m
LIBS=-lcml -lpython3.7m

linear: clean folders
	g++ -DWITHOUT_NUMPY $(SOURCE_FOLDER)/linear.cpp -o $(BUILD_FOLDER)/linear.out \
	$(CFLAG) $(INCLUDES) $(LIBS)

ease_in_sine: clean folders
	g++ -DWITHOUT_NUMPY $(SOURCE_FOLDER)/ease_in_sine.cpp -o $(BUILD_FOLDER)/ease_in_sine.out \
	$(CFLAG) $(INCLUDES) $(LIBS)

clean:
	rm -f ./**/*.{o,out}rm -rf $(BUILD_FOLDER)

folders:
	mkdir $(BUILD_FOLDER)
