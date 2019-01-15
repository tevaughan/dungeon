# @file       Makefile
# @author     Thomas E. Vaughan
# @brief      Automatic dependencies and rules for building unit tests.
# @copyright  2019 Thomas E. Vaughan
# @license    GPL3; see 'LICENSE' file.

SRCS   := $(shell ls *.cpp)
OBJS   := $(SRCS:.cpp=.o)
CC     := $(CXX)
DEPDIR := .d

tests : $(OBJS)

clean :
	@rm -fv $(OBJS)
	@rm -fv tests
	@rm -frv $(DEPDIR)

# The following was obtained from
# 'http://make.mad-scientist.net/papers/advanced-auto-dependency-generation'.
# Each cpp file must be list above in the definition of SRCS, and DEPDIR must
# be defined.

$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

%.o : %.cpp
%.o : %.cpp $(DEPDIR)/%.d
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS))))
