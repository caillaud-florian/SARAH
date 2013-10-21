# These options can be changed

srcdirs := src 
incdirs := include
bindir := bin
bin := SarahProject
objdir := .make.cache
makedir := .make.cache
resdir := ../resources

CXX := g++
CPPFLAGS := 
CXXFLAGS := -std=c++0x -g -Wall -pedantic
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lGL
# Filter input
srcdirs := $(strip $(srcdirs)
incdirs := $(strip $(incdirs))
bindir := $(strip $(bindir))
objdir := $(strip $(objdir))

# Not these ones
srcs := $(shell find $(srcdirs) -type f -name '*.cpp')
objs := $(subst $(srcdirs),$(objdir),$(srcs:.cpp=.o)) 
deps := $(subst $(srcdirs),$(objdir),$(srcs:.cpp=.d))

output_executable := $(bin)


all: $(bindir)/$(output_executable)
	@echo "$(output_executable) Ready to use, but with caution please."
	
$(bindir)/$(output_executable): $(objs) | $(bindir)
	@echo Linking...
	@$(CXX) -o $@ $+ $(LDFLAGS)

test: $(bindir)/$(output_executable)
	@echo Running...
	@cd $(bindir) ; ./$(output_executable)



$(binresdir)/%: $(resdir)/%
	@echo "Updating Resource $(notdir $@)..."
	@mkdir -p $(dir $@)
	@cp $< $@


$(objdir)/%.o: $(srcdirs)/%.cpp | $(objdir)
	@mkdir -p $(dir $@)
	@echo Compiling $(notdir $<)...
	@$(CXX) -c $< -o $@ -I$(incdirs) $(CXXFLAGS) $(CPPFLAGS)

$(makedir)/%.d: $(srcdirs)/%.cpp | $(makedir)
	@echo Making $(notdir $<) dependencies...
	@mkdir -p $(dir $@)
	@rm -f $@
	@$(CXX) -MM -I$(incdirs) $(CXXFLAGS) $(CPPFLAGS) $< > $@.temp
	@sed 's,\(.*\.o\)[ :]*, $(objdir)/$*.o $@ : ,g' < $@.temp > $@
	@rm -f $@.temp


ifneq ($(MAKECMDGOALS),clean)
-include $(deps)
endif

.PHONY: clean

$(bindir):
	@mkdir $(bindir)

ifneq ($(bindir),$(objdir))
$(objdir):
	@mkdir $(objdir)
endif

ifneq ($(bindir),$(makedir))
ifneq ($(objdir),$(makedir))
$(makedir):
	@mkdir $(makedir)
endif
endif

clean:
	@rm -rf $(objs) $(wildcard $(bindir)/*$(bin)*) $(binres) $(binresdir) $(wildcard $(makedir)/*$(bin)*)  $(deps)
	@[ -e $(objdir) ] && [ $(objdir) != . ] && find $(objdir) -depth -empty -type d -exec rmdir {} \; || :
	@[ -e $(bindir) ] && [ $(bindir) != "." ] && find $(bindir) -depth -empty -type d -exec rmdir {} \; || :
	@[ -e $(makedir) ] && [ $(makedir) != "." ] && find $(makedir) -depth -empty -type d -exec rmdir {} \; || :
	@echo Cleaned.
