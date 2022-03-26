NAME = miniRT

LIST =	./srcs_miniRT/main_miniRT.c\
		./srcs_miniRT/ray_traysing/ray_traysing.c\
		./srcs_miniRT/ray_traysing/compute_lighting.c\
		./srcs_miniRT/ray_traysing/get_normal.c\
		./srcs_miniRT/ray_traysing/color_functions.c\
		./srcs_miniRT/scene.c\
		./srcs_miniRT/intersect_all/intersect_all.c\
		./srcs_miniRT/intersect_all/intersect_obj.c\
		./srcs_miniRT/intersect_all/get_discriminant.c\
		./srcs_miniRT/vector_functions_1.c\
		./srcs_miniRT/vector_functions_2.c\
		./srcs_miniRT/mlx_utils.c\
		./srcs_miniRT/parser/parser.c\
		./srcs_miniRT/parser/parser_utils_1.c\
		./srcs_miniRT/parser/parser_utils_2.c\
		./srcs_miniRT/parser/split.c\
		./srcs_miniRT/parser/parse_number.c\
		./srcs_miniRT/parser/parse_light.c\
		./srcs_miniRT/parser/parse_ambient_light.c\
		./srcs_miniRT/parser/parse_camera.c\
		./srcs_miniRT/parser/parse_sphere.c\
		./srcs_miniRT/parser/parse_plane.c\
		./srcs_miniRT/parser/parse_cylinder.c\
		./srcs_miniRT/gnl/get_next_line.c\
		./srcs_miniRT/gnl/get_next_line_utils.c\

OBJ = ${LIST:.c=.o}

MLX_DIR		= ./minilibx_macos
MLX			= ./minilibx_macos/libmlx.a

FLAGS		= -Wall -Wextra -Werror -g
INC_DIR		= ./includes_miniRT/
INCLUDE		= $(addprefix -I, $(INC_DIR))
INCLUDE		+= $(addprefix -I, $(MLX_DIR))
DEPS		= $(OBJ:.o=.d)

$(NAME):	$(OBJ) $(MLX)
			gcc $(FLAGS) $(INCLUDE) $(OBJ) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
			gcc $(FLAGS) $(INCLUDE) -MMD -c $< -o $@

$(MLX):
		$(MAKE) -C minilibx_macos

all: $(NAME)

bonus: $(NAME)

clean: 
		rm -f $(OBJ)
		rm -f $(DEPS)

fclean: clean
		rm -f $(NAME)
		@make -C $(MLX_DIR) clean

re:		fclean all

.PHONY: all clean fclean re
-include $(DEPS)
