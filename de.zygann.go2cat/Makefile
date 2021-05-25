PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))


# -l ist eine Abkürzung für such die Library libm.a in deinen bekannten Pfaden. 
# Ist der Pfad nicht bekannt füge ihn hinzu idem die LD_LIBRARY_PATH variable angepasst wird
# -L.  (wichtig minus großes L und der PUNKT) heißt such im aktuellen Verzeichnis
LIBS = -L/usr/local/lib -lp11sgx -L/opt/intel/sgxsdk/sdk_libs -lsgx_urts_sim -lsgx_uae_service_sim

OBJS = de.zygann.go2cat.o

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g -O0
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else ifeq ($(BUILD_MODE),linuxtools)
	CFLAGS += -g -pg -fprofile-arcs -ftest-coverage
	LDFLAGS += -pg -fprofile-arcs -ftest-coverage
else
    $(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	go2cat

go2cat:	$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr de.zygann.go2cat $(OBJS)
