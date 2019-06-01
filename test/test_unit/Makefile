CXX=g++ -g
CXXFLAG=

Src=
Obj=mainTest
CustomHeaderPath=E:\MyProjects\CPP\openSource\googletest-release-1.8.1\googletest\include\gtest

$(Obj):$(Src)
	$(CXX) -o $@ $^ -I $(CustomHeaderPath)

.PHONY:clean

clean:
	-rm -rf $(Obj)
