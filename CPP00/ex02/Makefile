NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

TOTAL := $(words $(SRCS))
COUNT := 0

# Progress bar function
define progress_bar
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	$(eval PERCENT=$(shell echo $$(($(COUNT)*100/$(TOTAL)))))
	$(eval FILLED=$(shell echo $$(($(PERCENT)/2))))

	@printf "\r[%d/%d] (%3d%%) " $(COUNT) $(TOTAL) $(PERCENT)
	@printf "%0.s█" $$(seq 1 $(FILLED))
	@printf "%0.s " $$(seq 1 $$(($(50)-$(FILLED))))
	@printf " Compiling $<"
endef

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "\nBuild complete.\n"

%.o: %.cpp
	$(progress_bar)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Objects removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re