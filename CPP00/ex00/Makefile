NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98

SRCDIR = .
INCDIR = .
OBJDIR = obj

SRCS = $(addprefix $(SRCDIR)/, megaphone.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

IFLAGS = -I$(INCDIR)

TOTAL := $(words $(SRCS))
COUNT_FILE = .build_count

define ESC
$(shell printf '\033')
endef

RESET   = $(ESC)[0m
BOLD    = $(ESC)[1m
RED     = $(ESC)[31m
GREEN   = $(ESC)[32m
YELLOW  = $(ESC)[33m
ORANGE  = $(ESC)[38;5;208m
YLLWGRN = $(ESC)[38;2;150;255;25m

all: init $(NAME)

init:
	@echo 0 > $(COUNT_FILE)

$(NAME): $(OBJS)
	@printf "\n$(GREEN)Linking...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) $(IFLAGS) $(OBJS) -o $(NAME)
	@rm -f $(COUNT_FILE)
	@printf "$(GREEN)Build complete (100%%)$(RESET)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@count=$$(cat $(COUNT_FILE)); \
	count=$$((count + 1)); \
	echo $$count > $(COUNT_FILE); \
	\
	percent_str=$$(echo "scale=2; $$count / $(TOTAL) * 100" | bc); \
	percent_int=$$(printf "%.0f" $$percent_str); \
	\
	filled=$$((percent_int / 2)); \
	empty=$$((50 - filled)); \
	\
	bar=""; bg=""; \
	i=0; while [ $$i -lt $$filled ]; do bar="$${bar}█"; i=$$((i+1)); done; \
	i=0; while [ $$i -lt $$empty ]; do bg="$${bg}░"; i=$$((i+1)); done; \
	\
	if [ $$percent_int -lt 25 ]; then color="$(RED)"; \
	elif [ $$percent_int -lt 50 ]; then color="$(ORANGE)"; \
	elif [ $$percent_int -lt 75 ]; then color="$(YELLOW)"; \
	elif [ $$percent_int -lt 100 ]; then color="$(YLLWGRN)"; \
	else color="$(GREEN)"; fi; \
	\
	printf "\r%sCompiling $(NAME): [%s%s] [%3d/%3d] %6.2f%%%s" \
	"$(BOLD)$$color" "$$bar" "$$bg" $$count $(TOTAL) "$$percent_str" "$(RESET)"; \
	\
	printf "\nCompiling %-34s" "$(notdir $@)"; \
	\
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

-include $(DEPS)

clean:
	@rm -rf $(OBJDIR) $(COUNT_FILE)
	@printf "$(RED)Objects removed$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)Executable removed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re init