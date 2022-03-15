CC:=g++
srcs:=$(wildcard ./Boy/*.cpp)
objs:=$(srcs:%.cpp=%.o)
srcs2:=$(wildcard ./Girl/*.cpp)
objs2:=$(srcs2:%.cpp=%.o)
srcs3:=$(wildcard ./BoyStdOut/*.cpp)
objs3:=$(srcs3:%.cpp=%.o)
srcs4:=$(wildcard ./GirlStdOut/*.cpp)
objs4:=$(srcs4:%.cpp=%.o)
out:=boy
out2:=girl
out3:=boystdout
out4:=girlstdout
all:$(out) $(out2) $(out3) $(out4)
$(out4):$(objs4)
	$(CC) $(objs4) -g -o $(out4) 
%.o:%.cpp
	$(CC) -g -Wall -c $^ -o $@
$(out3):$(objs3)
	$(CC) $(objs3) -g -o $(out3) 
%.o:%.cpp
	$(CC) -g -Wall -c $^ -o $@
$(out2):$(objs2)
	$(CC) $(objs2) -g -o $(out2) 
%.o:%.cpp
	$(CC) -g -Wall -c $^ -o $@
$(out):$(objs)
	$(CC) $(objs) -g -o $(out) 
%.o:%.cpp
	$(CC) -g -Wall -c $^ -o $@
.PHONY:clean rebuild
clean:
	$(RM) $(objs) $(out) $(objs2) $(out2) $(objs3) $(out3) $(objs4) $(out4)
rebuild:clean all



